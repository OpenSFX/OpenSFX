#include "SFXHandle.h"

using namespace OpenSFX;

SFXHandle* SFXHandle::open(const char *file)
{
    SFXHandle* handle;

    // TODO: Pick appropriate subclass for file format

    if (!handle->openFile(file))
        return nullptr;

    return handle;
}

SFXHandle::SFXHandle() : mPath(nullptr), mChannels(0), mSampleRate(0)
{

}

SFXHandle::~SFXHandle()
{

}