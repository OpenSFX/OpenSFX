#include "SFXSource.h"

using namespace OpenSFX;

SFXSource::SFXSource() : mSource(0), mBuffer(0), mResumeOffset(-1.0f)
{
    alGenSources(1, &mSource);
}

SFXSource::~SFXSource()
{
    alDeleteSources(1, &mSource);
}

void SFXSource::setData(const ALuint buffer)
{
    if (buffer != mBuffer)
    {
        mBuffer = buffer;
        alSourcei(mSource, AL_BUFFER, (ALint)mBuffer);
    }
}

void SFXSource::play()
{
    if (mBuffer == 0)
        return;

    alSourceStop(mSource);
    alSourcePlay(mSource);

    // OpenAL can sometimes be buggy and
    // resume paused sounds at the wrong offset
    // This fixes that.
    if (mResumeOffset != -1.0f)
    {
        alSourcef(mSource, AL_SAMPLE_OFFSET, mResumeOffset);
        mResumeOffset = -1.0f;
    }
}

void SFXSource::pause()
{
    alSourcePause(mSource);

    // OpenAL can sometimes be buggy and
    // resume paused sounds at the wrong offset
    // This fixes that.
    alGetSourcef(mSource, AL_SAMPLE_OFFSET, &mResumeOffset);
}

void SFXSource::stop()
{
    alSourceStop(mSource);

    mResumeOffset = -1.0f;
}

SFXAudioStatus SFXSource::getStatus() const
{
    ALint state;
    alGetSourcei(mSource, AL_SOURCE_STATE, &state);

    switch (state)
    {
        case AL_PLAYING:
            return SFX_PLAYING;
        case AL_PAUSED:
            return SFX_PAUSED;
        default:
            return SFX_STOPPED;
    }
}

void SFXSource::seek(ALuint pos)
{
    alSourcei(mSource, AL_SAMPLE_OFFSET, (ALint)pos);

    mResumeOffset = -1.0f;
}

ALuint SFXSource::tell() const
{
    ALint pos;
    alGetSourcei(mSource, AL_SAMPLE_OFFSET, &pos);

    return pos;
}

void SFXSource::setDistance(float min, float max)
{
    alSourcef(mSource, AL_REFERENCE_DISTANCE, min);
    alSourcef(mSource, AL_MAX_DISTANCE, max);
}

void SFXSource::setLooping(bool looping)
{
    // TODO: Deal with streaming audio
    alSourcei(mSource, AL_LOOPING, looping ? AL_TRUE : AL_FALSE);
}

void SFXSource::setPosition(float x, float y, float z)
{
    alSource3f(mSource, AL_POSITION, x, y, z);
}

void SFXSource::setDirection(float x, float y, float z)
{
    alSource3f(mSource, AL_DIRECTION, x, y, z);
}

void SFXSource::setVelocity(float x, float y, float z)
{
    alSource3f(mSource, AL_VELOCITY, x, y, z);
}

void SFXSource::setVolume(float volume)
{
    alSourcef(mSource, AL_GAIN, volume);
}

void SFXSource::setPitch(float pitch)
{
    alSourcef(mSource, AL_PITCH, pitch);
}

void SFXSource::setFrequency(int frequency)
{
    // TODO: Implement a way to get the frequency
    //setPitch(baseFrequency * frequency);
}

void SFXSource::setCone(float innerAngle, float outerAngle, float outerVolume)
{
    alSourcef(mSource, AL_CONE_INNER_ANGLE, innerAngle);
    alSourcef(mSource, AL_CONE_OUTER_ANGLE, outerAngle);
    alSourcef(mSource, AL_CONE_OUTER_GAIN, outerVolume);
}

void SFXSource::setRelative(bool relative)
{
    alSourcei(mSource, AL_SOURCE_RELATIVE, relative ? AL_TRUE : AL_FALSE);
}
