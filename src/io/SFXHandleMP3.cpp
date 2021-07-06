#include "SFXHandleMP3.h"
#include <MP3Detect.h>

#include <memory>
#define MINIMP3_IMPLEMENTATION
#define MINIMP3_NO_SIMD
#include <minimp3.h>
#include <minimp3_ex.h>

using namespace OpenSFX;

SFXHandleMP3::SFXHandleMP3()
{

}

SFXHandleMP3::~SFXHandleMP3()
{
    mp3dec_close_file(mMapInfo);
    delete mMapInfo;
    delete mFrameInfo;
    delete mFileInfo;
    delete mDec;
}

bool SFXHandleMP3::openFile(const char *file)
{
    if (!mp3detect_is_mp3_file(file))
        return false;

    mp3dec_t *dec = new mp3dec_t();
    mp3dec_file_info_t *info = new mp3dec_file_info_t();
    mp3dec_map_info_t *map_info = new mp3dec_map_info_t();
    if (mp3dec_open_file(file, map_info))
    {
        delete dec;
        delete info;
        delete map_info;
        return false;
    }

    size_t orig_buf_size = map_info->size;
    mp3d_sample_t pcm[MINIMP3_MAX_SAMPLES_PER_FRAME];
    mp3dec_frame_info_t *frame_info = new mp3dec_frame_info_t();

    mDec = dec;
    mFileInfo = info;
    mMapInfo = map_info;
    mFrameInfo = frame_info;

    /* skip id3 */
    mp3dec_skip_id3(&map_info->buffer, &map_info->size);
    if (!map_info->size)
    {
        delete dec;
        delete info;
        delete map_info;
        delete frame_info;
        return false;
    }
    /* try to make allocation size assumption by first frame */
    mp3dec_init(dec);
    mSamples = 0;
    do
    {
        mSamples = mp3dec_decode_frame(dec, map_info->buffer, map_info->size, pcm, mFrameInfo);
        map_info->buffer += frame_info->frame_bytes;
        map_info->size -= frame_info->frame_bytes;
        if (mSamples)
            break;
    } while (frame_info->frame_bytes);
    if (!mSamples)
    {
        mp3dec_close_file(map_info);
        delete dec;
        delete info;
        delete map_info;
        delete frame_info;
        return false;
    }
    mSamples *= frame_info->channels;
    mAllocated = (map_info->size / frame_info->frame_bytes) * mSamples * sizeof(mp3d_sample_t) + MINIMP3_MAX_SAMPLES_PER_FRAME * sizeof(mp3d_sample_t);
    info->buffer = (mp3d_sample_t *)malloc(mAllocated);
    if (!info->buffer)
    {
        mp3dec_close_file(map_info);
        delete dec;
        delete info;
        delete map_info;
        delete frame_info;
        return false;
    }
    info->samples = mSamples;
    memcpy(info->buffer, pcm, info->samples * sizeof(mp3d_sample_t));
    /* save info */
    info->channels = frame_info->channels;
    info->hz = frame_info->hz;
    info->layer = frame_info->layer;

    mChannels = info->channels;
    mSampleRate = info->hz;

    mReadPos = 0;
    mLoaded = false;

    return true;
}

size_t SFXHandleMP3::read(unsigned short *ptr, size_t items)
{
    size_t avg_bitrate_kbps = mFrameInfo->bitrate_kbps;
    size_t frames = 1;

    size_t bytes_to_read = items * sizeof(unsigned short);
    size_t bytes_read = 0;

    if (mLoaded)
    {
        bytes_read = mFileInfo->samples * sizeof(mp3d_sample_t) - mReadPos;
    } else
    {
        /* decode rest frames */
        int frame_bytes;
        do
        {
            if ((mAllocated - mFileInfo->samples * sizeof(mp3d_sample_t)) < MINIMP3_MAX_SAMPLES_PER_FRAME * sizeof(mp3d_sample_t))
            {
                mAllocated *= 2;
                mFileInfo->buffer = (mp3d_sample_t *)realloc(mFileInfo->buffer, mAllocated);
            }
            mSamples = mp3dec_decode_frame(mDec, mMapInfo->buffer, mMapInfo->size, mFileInfo->buffer + mFileInfo->samples, mFrameInfo);
            frame_bytes = mFrameInfo->frame_bytes;
            mMapInfo->buffer += frame_bytes;
            mMapInfo->size -= frame_bytes;
            if (mSamples)
            {
                if (mFileInfo->hz != mFrameInfo->hz || mFileInfo->layer != mFrameInfo->layer)
                    break;
                if (mFileInfo->channels && mFileInfo->channels != mFrameInfo->channels)
#ifdef MINIMP3_ALLOW_MONO_STEREO_TRANSITION
                    info->channels = 0; /* mark file with mono-stereo transition */
#else
                    break;
#endif
                mFileInfo->samples += mSamples * mFrameInfo->channels;
                avg_bitrate_kbps += mFrameInfo->bitrate_kbps;
                frames++;
            }

            bytes_read += mSamples * mFrameInfo->channels * sizeof(int16_t);
        } while (frame_bytes && bytes_read < bytes_to_read);

        if (!frame_bytes)
        {
            mLoaded = true;
            bytes_read = mFileInfo->samples * sizeof(mp3d_sample_t) - mReadPos;
        }

        /* reallocate to normal buffer size */
        if (frame_bytes == 0 && mAllocated != mFileInfo->samples * sizeof(mp3d_sample_t))
            mFileInfo->buffer = (mp3d_sample_t *)realloc(mFileInfo->buffer, mFileInfo->samples * sizeof(mp3d_sample_t));
        mFileInfo->avg_bitrate_kbps = avg_bitrate_kbps / frames;

    }

    size_t ret = min(bytes_to_read, bytes_read);

    if (ret == 0)
        return 0;

    uint8_t* data_read = (uint8_t*)(mFileInfo->buffer) + mReadPos;
#if defined(__STDC_WANT_LIB_EXT1__) || defined(_MSC_VER)
    memcpy_s((uint8_t *)ptr, bytes_to_read, data_read, ret);
#else
    memcpy((uint8_t *)ptr, data_read, ret);
#endif

    mReadPos += ret;

    return ret / 2;
}
