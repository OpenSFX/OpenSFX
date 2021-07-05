#pragma once
#include "OpenSFX.h"

#include <AL/al.h>

namespace OpenSFX
{
    class SFXSource
    {
    public:
        SFXSource();
        ~SFXSource();

        void setData(const ALuint buffer);
        void play();
        void pause();
        void stop();

        SFXAudioStatus getStatus() const;

        void seek(ALuint pos);
        ALuint tell() const;

        void setDistance(float min, float max);
        void setLooping(bool looping);
        void setPosition(float x, float y, float z);
        void setDirection(float x, float y, float z);
        void setVelocity(float x, float y, float z);
        void setVolume(float volume);
        void setPitch(float pitch);
        void setFrequency(int frequency);
        void setCone(float innerAngle, float outerAngle, float outerVolume);
        void setRelative(bool relative);

    private:
        ALuint mSource;
        ALuint mBuffer;

        float mResumeOffset;
    };
}
