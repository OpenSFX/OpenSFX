#include "OpenSFX.h"

struct SFXAudioFile
{
    // TODO: Implement: SFXAudioFile
};

struct SFXAudioSource
{
    // TODO: Implement: SFXAudioSource
};

bool sfx_open_device(const char* deviceName)
{
    // TODO: Implement: sfx_open_device
    return false;
}

void sfx_close_device()
{
    // TODO: Implement: sfx_close_device
}

struct SFXAudioFile* sfx_file_load(const char* file)
{
    // TODO: Implement: sfx_file_load
    return new SFXAudioFile();
}

void sfx_file_free(struct SFXAudioFile* file)
{
    delete file;
}

struct SFXAudioSource* sfx_file_play(struct SFXAudioFile* file)
{
    // TODO: Implement: sfx_file_play
    return new SFXAudioSource();
}

struct SFXAudioSource* sfx_file_play_streaming(struct SFXAudioFile* file)
{
    // TODO: Implement: sfx_file_play_streaming
    return new SFXAudioSource();
}

struct SFXAudioSource* sfx_source_create(struct SFXAudioFile* file)
{
    // TODO: Implement: sfx_source_create
    return new SFXAudioSource();
}

void sfx_source_free(struct SFXAudioSource* source)
{
    delete source;
}

void sfx_source_play(struct SFXAudioSource* source)
{
    // TODO: Implement: sfx_source_play
}

void sfx_source_pause(struct SFXAudioSource* source)
{
    // TODO: Implement: sfx_source_pause
}

void sfx_source_stop(struct SFXAudioSource* source)
{
    // TODO: Implement: sfx_source_stop
}

void sfx_source_seek(struct SFXAudioSource* source, unsigned int position)
{
    // TODO: Implement: sfx_source_seek
}

unsigned int sfx_source_tell(struct SFXAudioSource* source)
{
    // TODO: Implement: sfx_source_tell
    return 0;
}

enum SFXAudioStatus sfx_source_status(struct SFXAudioSource* source)
{
    // TODO: Implement: sfx_source_status
    return SFX_STOPPED;
}

void sfx_source_distance(struct SFXAudioSource* source, float min, float max)
{
    // TODO: Implement: sfx_source_distance
}

void sfx_source_looping(struct SFXAudioSource* source, bool looping)
{
    // TODO: Implement: sfx_source_looping
}

void sfx_source_position(struct SFXAudioSource* source, float x, float y, float z)
{
    // TODO: Implement: sfx_source_position
}

void sfx_source_direction(struct SFXAudioSource* source, float x, float y, float z)
{
    // TODO: Implement: sfx_source_direction
}

void sfx_source_velocity(struct SFXAudioSource* source, float x, float y, float z)
{
    // TODO: Implement: sfx_source_velocity
}

void sfx_source_volume(struct SFXAudioSource* source, float volume)
{
    // TODO: Implement: sfx_source_volume
}

void sfx_source_pitch(struct SFXAudioSource* source, float pitch)
{
    // TODO: Implement: sfx_source_pitch
}

void sfx_source_frequency(struct SFXAudioSource* source, int frequency)
{
    // TODO: Implement: sfx_source_frequency
}

void sfx_source_cone(struct SFXAudioSource* source, float innerAngle, float outerAngle, float outerVolume)
{
    // TODO: Implement: sfx_source_cone
}

void sfx_source_relative(struct SFXAudioSource* source, bool relative)
{
    // TODO: Implement: sfx_source_relative
}

void sfx_listener_position(float x, float y, float z)
{
    // TODO: Implement: sfx_listener_position
}

void sfx_listener_velocity(float x, float y, float z)
{
    // TODO: Implement: sfx_listener_velocity
}

void sfx_listener_orientation(float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ)
{
    // TODO: Implement: sfx_listener_orientation
}
