#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

    struct AudioFile;
    struct AudioSource;

    enum AudioStatus
    {
        PLAYING,
        PAUSED,
        STOPPED
    };

    AudioFile* sfx_load_audio(const char* file);
    void sfx_free_audio(AudioFile* file);

    AudioSource* sfx_create_source(AudioFile* file);
    void sfx_free_source(AudioSource* source);

    AudioSource* sfx_play_audio(AudioFile* file);
    void sfx_play_source(AudioSource* source);

    AudioSource* sfx_play_streaming_audio(AudioFile* file);

    void sfx_pause(AudioSource* source);
    void sfx_stop(AudioSource* source);

    void sfx_set_sample_position(AudioSource* source, unsigned int position);
    unsigned int sfx_get_sample_position(AudioSource* source);

    enum AudioStatus sfx_get_status(AudioSource* source);

    void sfx_set_audible_distance(AudioSource* source, float min, float max);
    void sfx_set_looping(AudioSource* source, bool looping);
    void sfx_set_position(AudioSource* source, float x, float y, float z);
    void sfx_set_direction(AudioSource* source, float x, float y, float z);
    void sfx_set_velocity(AudioSource* source, float x, float y, float z);
    void sfx_set_volume(AudioSource* source, float volume);
    void sfx_set_pitch(AudioSource* source, float pitch);
    void sfx_set_frequency(AudioSource* source, int frequency);
    void sfx_set_cone(AudioSource* source, float innerAngle, float outerAngle, float outerVolume);
    void sfx_set_relative(AudioSource* source, bool relative);

    void sfx_set_listener_position(float x, float y, float z);
    void sfx_set_listener_velocity(float x, float y, float z);
    void sfx_set_listener_orientation(float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ);

#ifdef __cplusplus
}
#endif
