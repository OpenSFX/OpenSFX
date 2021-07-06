#include "SFXHandle.h"
#include "SFXHandleMP3.h"

using namespace OpenSFX;

SFXHandle* SFXHandle::open(const char *file)
{
    SFXHandle* handle;

    // Pick appropriate subclass for file format

    // MP3
    if (handle = new SFXHandleMP3(),
        !handle->openFile(file))
    {
        delete handle;
        handle = nullptr;
    }

    handle->mPath = file;

    return handle;
}

SFXHandle::SFXHandle() : mPath(nullptr), mChannels(0), mSampleRate(0)
{

}

SFXHandle::~SFXHandle()
{

}