#pragma once
#include "SFXHandle.h"
#include "minimp3_ex.h"

namespace OpenSFX
{
    class SFXHandleMP3 : public SFXHandle
    {
    private:
        typedef SFXHandle Parent;

    public:
        SFXHandleMP3();
        ~SFXHandleMP3() override;

        bool openFile(const char *file) override;
        size_t read(unsigned short *ptr, size_t items) override;

    private:
        mp3dec_t *mDec;
        mp3dec_file_info_t *mFileInfo;
        mp3dec_map_info_t *mMapInfo;
        mp3dec_frame_info_t *mFrameInfo;
        int mSamples;
        size_t mAllocated;
        size_t mReadPos;
        bool mLoaded;
    };
}
