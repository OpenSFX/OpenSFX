#include "OpenSFX.h"
#include <AL/al.h>
#include "SFXDevice.h"
#include "SFXBuffer.h"
#include "SFXSource.h"
#include "OpenSFXException.h"

using namespace OpenSFX;

struct SFXAudioFile
{
    ALuint buffer;
    const char* fileName;
};

struct SFXAudioSource
{
    SFXSource* source;
};

bool sfx_open_device(const char* deviceName)
{
    try
    {
        SFXDevice::get(deviceName);
    } catch (OpenSFX::OpenSFXException e)
    {
        return false;
    }

    return true;
}

struct SFXAudioFile* sfx_file_load(const char* file)
{
    ALuint buffer = SFXBuffer::get()->addSound(file);
    if (buffer == 0)
        return nullptr;
    SFXAudioFile* audioFile = new SFXAudioFile();
    audioFile->buffer = buffer;
    audioFile->fileName = file;
    return audioFile;
}

void sfx_file_free(struct SFXAudioFile* file)
{
    if (file)
    {
        SFXBuffer::get()->removeSound(file->buffer);
        delete file;
    }
}

struct SFXAudioSource* sfx_file_play(struct SFXAudioFile* file)
{
    SFXAudioSource* source = sfx_source_create();
    if (source == nullptr)
        return nullptr;

    source->source->setData(file->buffer);
    source->source->play();

    return source;
}

struct SFXAudioSource* sfx_file_play_streaming(struct SFXAudioFile* file)
{
    // TODO: Implement: sfx_file_play_streaming
    return new SFXAudioSource();
}

struct SFXAudioSource* sfx_source_create()
{
    SFXAudioSource* source = new SFXAudioSource();
    source->source = new SFXSource();

    return source;
}

void sfx_source_free(struct SFXAudioSource* source)
{
    if (source)
    {
        delete source->source;
        delete source;
    }
}

void sfx_source_data(struct SFXAudioSource* source, struct SFXAudioFile* file)
{
    if (source == nullptr || file == nullptr)
        return;
    source->source->setData(file->buffer);
}

void sfx_source_play(struct SFXAudioSource* source)
{
    if (source == nullptr)
        return;

    source->source->play();
}

void sfx_source_pause(struct SFXAudioSource* source)
{
    if (source == nullptr)
        return;

    source->source->pause();
}

void sfx_source_stop(struct SFXAudioSource* source)
{
    if (source == nullptr)
        return;

    source->source->stop();
}

void sfx_source_seek(struct SFXAudioSource* source, unsigned int position)
{
    if (source == nullptr)
        return;

    source->source->seek(position);
}

unsigned int sfx_source_tell(struct SFXAudioSource* source)
{
    if (source == nullptr)
        return 0;

    return source->source->tell();
}

enum SFXAudioStatus sfx_source_status(struct SFXAudioSource* source)
{
    if (source == nullptr)
        return SFX_STOPPED;

    return source->source->getStatus();
}

void sfx_source_distance(struct SFXAudioSource* source, float min, float max)
{
    if (source == nullptr)
        return;

    source->source->setDistance(min, max);
}

void sfx_source_looping(struct SFXAudioSource* source, bool looping)
{
    if (source == nullptr)
        return;

    source->source->setLooping(looping);
}

void sfx_source_position(struct SFXAudioSource* source, float x, float y, float z)
{
    if (source == nullptr)
        return;

    source->source->setPosition(x, y, z);
}

void sfx_source_direction(struct SFXAudioSource* source, float x, float y, float z)
{
    if (source == nullptr)
        return;

    source->source->setDirection(x, y, z);
}

void sfx_source_velocity(struct SFXAudioSource* source, float x, float y, float z)
{
    if (source == nullptr)
        return;

    source->source->setVelocity(x, y, z);
}

void sfx_source_volume(struct SFXAudioSource* source, float volume)
{
    if (source == nullptr)
        return;

    source->source->setVolume(volume);
}

void sfx_source_pitch(struct SFXAudioSource* source, float pitch)
{
    if (source == nullptr)
        return;

    source->source->setPitch(pitch);
}

void sfx_source_frequency(struct SFXAudioSource* source, int frequency)
{
    if (source == nullptr)
        return;

    source->source->setFrequency(frequency);
}

void sfx_source_cone(struct SFXAudioSource* source, float innerAngle, float outerAngle, float outerVolume)
{
    if (source == nullptr)
        return;

    source->source->setCone(innerAngle, outerAngle, outerVolume);
}

void sfx_source_relative(struct SFXAudioSource* source, bool relative)
{
    if (source == nullptr)
        return;

    source->source->setRelative(relative);
}

void sfx_listener_position(float x, float y, float z)
{
    alListener3f(AL_POSITION, x, y, z);
}

void sfx_listener_velocity(float x, float y, float z)
{
    alListener3f(AL_VELOCITY, x, y, z);
}

void sfx_listener_orientation(float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ)
{
    float orientation[3][2];
    orientation[0][0] = forwardX;
    orientation[1][0] = forwardY;
    orientation[2][0] = forwardZ;
    orientation[0][1] = upX;
    orientation[1][1] = upX;
    orientation[2][1] = upX;

    alListenerfv(AL_ORIENTATION, (const float*)&orientation[0]);
}
