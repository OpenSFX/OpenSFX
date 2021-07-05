#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

    struct AudioFile;
    struct AudioSource;

    /**
     * The current status of an audio source
     */
    enum AudioStatus
    {
        PLAYING, // The source is playing
        PAUSED,  // The source is paused
        STOPPED  // The source is stopped
    };

    /**
     * Loads an audio file into memory
     * @param file The path of the file to load
     * @return The AudioFile structure representing the loaded audio file
     */
    struct AudioFile* sfx_load_audio(const char* file);

    /**
     * Releases the memory associated with a loaded audio file
     * @param file The audio file to unload
     */
    void sfx_free_audio(struct AudioFile* file);

    /**
     * Creates an AudioSource from an audio file
     * @param file The audio file to load
     * @return The created audio source
     */
    struct AudioSource* sfx_create_source(struct AudioFile* file);

    /**
     * Releases the memory associated with an audio source
     * @param source The AudioSource to unload
     */
    void sfx_free_source(struct AudioSource* source);

    /**
     * Plays audio directly from a file
     * @param file The audio file to play
     * @return The created audio source
     */
    struct AudioSource* sfx_play_audio(struct AudioFile* file);

    /**
     * Plays an audio source
     * @param source The audio source to play
     */
    void sfx_play_source(struct AudioSource* source);

    /**
     * Starts streaming an audio file
     * @param file The file to play
     * @return The created audio source
     */
    struct AudioSource* sfx_play_streaming_audio(struct AudioFile* file);

    /**
     * Pauses an audio source
     * @param source The source to pause
     */
    void sfx_pause(struct AudioSource* source);

    /**
     * Stops an audio source
     * @param source The source to stop
     */
    void sfx_stop(struct AudioSource* source);

    /**
     * Sets the sample position of an audio source
     * @param source The audio source to modify
     * @param position The new sample position
     */
    void sfx_set_sample_position(struct AudioSource* source, unsigned int position);

    /**
     * Gets the sample position of an audio source
     * @param source The audio source to get the sample position from
     * @return The sample position
     */
    unsigned int sfx_get_sample_position(struct AudioSource* source);

    /**
     * Gets the status of an audio source
     * @param source The audio source to get the status from
     * @return The status of the specified audio source
     */
    enum AudioStatus sfx_get_status(struct AudioSource* source);

    /**
     * Sets the minimum and maximum distance where the source is audible
     * @param source The audio source to modify
     * @param min The minimum distance where the source is audible
     * @param max The maximum distance where the source is audible
     */
    void sfx_set_audible_distance(struct AudioSource* source, float min, float max);

    /**
     * Sets whether or not the source should loop
     * @param source The audio source to modify
     * @param looping true if the source should loop,
     * false if it shouldn't
     */
    void sfx_set_looping(struct AudioSource* source, bool looping);

    /**
     * Sets the position of an audio source
     * @param source The audio source to modify
     * @param x The X Coordinate of the position
     * @param y The Y Coordinate of the position
     * @param z The Z Coordinate of the position
     */
    void sfx_set_position(struct AudioSource* source, float x, float y, float z);

    /**
     * Sets the direction of an audio source
     * @param source The audio source to modify
     * @param x The X Coordinate of the direction
     * @param y The Y Coordinate of the direction
     * @param z The Z Coordinate of the direction
     */
    void sfx_set_direction(struct AudioSource* source, float x, float y, float z);

    /**
     * Sets the velocity of an audio source
     * @param source The audio source to modify
     * @param x The X Coordinate of the velocity
     * @param y The Y Coordinate of the velocity
     * @param z The Z Coordinate of the velocity
     */
    void sfx_set_velocity(struct AudioSource* source, float x, float y, float z);

    /**
     * Sets the volume of an audio source
     * @param source The audio source to modify
     * @param volume The new volume to set
     */
    void sfx_set_volume(struct AudioSource* source, float volume);

    /**
     * Sets the pitch of an audio source
     * @param source The audio source to modify
     * @param pitch The new pitch for the audio source
     * @example sfx_set_pitch(source, 1.2f);
     */
    void sfx_set_pitch(struct AudioSource* source, float pitch);

    /**
     * Sets the frequency of an audio source
     * @param source The audio source to modify
     * @param frequency The new frequency for the audio source
     * @example sfx_set_frequency(source, 44100);
     */
    void sfx_set_frequency(struct AudioSource* source, int frequency);

    /**
     * Sets the cone of an audio source
     * @param source The audio source to modify
     * @param innerAngle The inner angle of the cone
     * @param outerAngle The outer angle of the cone
     * @param outerVolume The outer volume of the cone
     */
    void sfx_set_cone(struct AudioSource* source, float innerAngle, float outerAngle, float outerVolume);

    /**
     * Sets whether or not the position of this audio source is
     * relative to the position of the listener
     * @param source The audio source to modify
     * @param relative true if the position of this audio source
     * should be relative to the listener position, false otherwise
     */
    void sfx_set_relative(struct AudioSource* source, bool relative);

    /**
     * Sets the listener position
     * @param x The X Coordinate of the position
     * @param y The Y Coordinate of the position
     * @param z The Z Coordinate of the position
     */
    void sfx_set_listener_position(float x, float y, float z);

    /**
     * Sets the listener velocity
     * @param x The X Coordinate of the velocity
     * @param y The Y Coordinate of the velocity
     * @param z The Z Coordinate of the velocity
     */
    void sfx_set_listener_velocity(float x, float y, float z);

    /**
     * Sets the listener orientation
     * @param forwardX The X Coordinate of the forward vector
     * @param forwardY The Y Coordinate of the forward vector
     * @param forwardZ The Z Coordinate of the forward vector
     * @param upX The X Coordinate of the up vector
     * @param upY The Y Coordinate of the up vector
     * @param upZ The Z Coordinate of the up vector
     */
    void sfx_set_listener_orientation(float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ);

#ifdef __cplusplus
}
#endif
