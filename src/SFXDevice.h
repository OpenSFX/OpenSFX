#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include "OpenSFXException.h"

namespace OpenSFX
{
    class SFXDevice
    {
    public:
        static SFXDevice* get(const char* deviceName);

        const char* getDeviceName() { return mName; }

    private:
        SFXDevice(const char* deviceName) throw(OpenSFXException);
        ~SFXDevice() throw(OpenSFXException);

        ALCdevice* mALCDevice;
        ALCcontext* mALCContext;
        const char* mName;
    };
}
