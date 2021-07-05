#include "SFXBuffer.h"
#include "io/SFXHandle.h"

using namespace OpenSFX;

SFXBuffer *SFXBuffer::get()
{
    static SFXBuffer *buffer = new SFXBuffer();
    return buffer;
}

ALuint SFXBuffer::addSound(const char *filename)
{
    SFXHandle* handle = SFXHandle::open(filename);
    if (handle == nullptr)
        return 0;

    ALuint buffer;
    alGenBuffers(1, &buffer);

    std::vector<unsigned short> data;
    unsigned short read_buf[2048];

    size_t read_size = 0;
    while ((read_size = handle->read(read_buf, 2048)) != 0)
    {
        data.insert(data.end(), read_buf, read_buf + read_size);
    }

    alBufferData(buffer, handle->getChannels() == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16,
                 &data.front(), data.size() * sizeof(unsigned short), handle->getSampleRate());

    handle->close();
    return buffer;
}

bool SFXBuffer::removeSound(const ALuint &buffer)
{
    auto it = mBuffers.begin();
    while (it != mBuffers.end())
    {
        if (*it == buffer)
        {
            alDeleteBuffers(1, &*it);
            it = mBuffers.erase(it);

            return true;
        } else
        {
            ++it;
        }
    }

    return false;
}

SFXBuffer::SFXBuffer()
{
    mBuffers.clear();
}

SFXBuffer::~SFXBuffer()
{
    alDeleteBuffers(mBuffers.size(), mBuffers.data());

    mBuffers.clear();
}