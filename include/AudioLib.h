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

    AudioFile* load_audio(const char* file);
    void free_audio(AudioFile* file);

    AudioSource* create_source();
    void free_source(AudioSource* source);

    AudioSource* play_audio(AudioFile* file);
    void play_source(AudioSource* source);

    AudioSource* play_streaming_audio(AudioFile* file);

    void pause_audio(AudioSource* source);
    void stop_audio(AudioSource* source);

    void set_sample_position(AudioSource* source, unsigned int position);
    unsigned int get_sample_position(AudioSource* source);

    enum AudioStatus get_status(AudioSource* source);

    void set_audible_distance(AudioSource* source, float min, float max);
    void set_looping(AudioSource* source, bool looping);
    void set_position(AudioSource* source, float x, float y, float z);
    void set_direction(AudioSource* source, float x, float y, float z);
    void set_velocity(AudioSource* source, float x, float y, float z);
    void set_volume(AudioSource* source, float volume);
    void set_pitch(AudioSource* source, float pitch);
    void set_frequency(AudioSource* source, int frequency);
    void set_cone(AudioSource* source, float innerAngle, float outerAngle, float outerVolume);


#ifdef __cplusplus
}
#endif
