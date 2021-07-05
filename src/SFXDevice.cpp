#include "SFXDevice.h"
#include "OpenSFXException.h"

using namespace OpenSFX;

SFXDevice* SFXDevice::get(const char* deviceName)
{
    static SFXDevice* device = new SFXDevice(deviceName);
    return device;
}

SFXDevice::SFXDevice(const char *deviceName) throw(OpenSFXException)
{
    mALCDevice = alcOpenDevice(deviceName);
    if (!mALCDevice)
        throw OpenSFXException("failed to get sound device");

    mALCContext = alcCreateContext(mALCDevice, nullptr);
    if (!mALCContext)
        throw OpenSFXException("failed to set sound context");

    if (!alcMakeContextCurrent(mALCContext))
        throw OpenSFXException("failed to make context current");

    mName = nullptr;
    if (alcIsExtensionPresent(mALCDevice, "ALC_ENUMERATE_ALL_EXT"))
        mName = alcGetString(mALCDevice, ALC_ALL_DEVICES_SPECIFIER);
    if (!mName || alcGetError(mALCDevice) != AL_NO_ERROR)
        mName = alcGetString(mALCDevice, ALC_DEVICE_SPECIFIER);
}

SFXDevice::~SFXDevice() throw(OpenSFXException)
{
    if (!alcMakeContextCurrent(nullptr))
        throw OpenSFXException("failed to set context to nullptr");

    alcDestroyContext(mALCContext);
    if (mALCContext)
        throw OpenSFXException("failed to unset during close");

    if (!alcCloseDevice(mALCDevice))
        throw OpenSFXException("failed to close sound device");
}