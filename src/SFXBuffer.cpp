#include "SFXBuffer.h"

using namespace OpenSFX;

SFXBuffer *SFXBuffer::get()
{
    static SFXBuffer *buffer = new SFXBuffer();
    return buffer;
}

ALuint SFXBuffer::addSound(const char *filename)
{
    //ALuint buffer;
    //alGenBuffers(1, &buffer);
    return 0;
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