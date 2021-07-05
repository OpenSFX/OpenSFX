#ifndef __OPEN_SFX_H_
#define __OPEN_SFX_H_

#ifdef __cplusplus
extern "C"
{
#endif

    struct SFXAudioFile;
    struct SFXAudioSource;

    /**
     * The current status of an audio source
     */
    enum SFXAudioStatus
    {
        SFX_PLAYING, // The source is playing
        SFX_PAUSED,  // The source is paused
        SFX_STOPPED  // The source is stopped
    };

    /**
     * Opens an audio device
     * @param deviceName the name of the device to open
     * or null for the default device
     * @return true if the function succeeded, false otherwise
     */
    extern bool sfx_open_device(const char* deviceName);

    /**
     * Closes the opened audio device
     */
    extern void sfx_close_device();

    /**
     * Loads an audio file into memory
     * @param file The path of the file to load
     * @return The SFXAudioFile structure representing the loaded audio file
     */
    extern struct SFXAudioFile* sfx_file_load(const char* file);

    /**
     * Releases the memory associated with a loaded audio file
     * @param file The audio file to unload
     */
    extern void sfx_file_free(struct SFXAudioFile* file);

    /**
     * Plays audio directly from a file
     * @param file The audio file to play
     * @return The created audio source
     */
    extern struct SFXAudioSource* sfx_file_play(struct SFXAudioFile* file);

    /**
     * Starts streaming an audio file
     * @param file The file to play
     * @return The created audio source
     */
    extern struct SFXAudioSource* sfx_file_play_streaming(struct SFXAudioFile* file);

    /**
     * Creates an SFXAudioSource from an audio file
     * @param file The audio file to load
     * @return The created audio source
     */
    extern struct SFXAudioSource* sfx_source_create(struct SFXAudioFile* file);

    /**
     * Releases the memory associated with an audio source
     * @param source The SFXAudioSource to unload
     */
    extern void sfx_source_free(struct SFXAudioSource* source);

    /**
     * Plays an audio source
     * @param source The audio source to play
     */
    extern void sfx_source_play(struct SFXAudioSource* source);

    /**
     * Pauses an audio source
     * @param source The source to pause
     */
    extern void sfx_source_pause(struct SFXAudioSource* source);

    /**
     * Stops an audio source
     * @param source The source to stop
     */
    extern void sfx_source_stop(struct SFXAudioSource* source);

    /**
     * Sets the sample position of an audio source
     * @param source The audio source to modify
     * @param position The new sample position
     */
    extern void sfx_source_seek(struct SFXAudioSource* source, unsigned int position);

    /**
     * Gets the sample position of an audio source
     * @param source The audio source to get the sample position from
     * @return The sample position
     */
    extern unsigned int sfx_source_tell(struct SFXAudioSource* source);

    /**
     * Gets the status of an audio source
     * @param source The audio source to get the status from
     * @return The status of the specified audio source
     */
    extern enum SFXAudioStatus sfx_source_status(struct SFXAudioSource* source);

    /**
     * Sets the minimum and maximum distance where the source is audible
     * @param source The audio source to modify
     * @param min The minimum distance where the source is audible
     * @param max The maximum distance where the source is audible
     */
    extern void sfx_source_distance(struct SFXAudioSource* source, float min, float max);

    /**
     * Sets whether or not the source should loop
     * @param source The audio source to modify
     * @param looping true if the source should loop,
     * false if it shouldn't
     */
    extern void sfx_source_looping(struct SFXAudioSource* source, bool looping);

    /**
     * Sets the position of an audio source
     * @param source The audio source to modify
     * @param x The X Coordinate of the position
     * @param y The Y Coordinate of the position
     * @param z The Z Coordinate of the position
     */
    extern void sfx_source_position(struct SFXAudioSource* source, float x, float y, float z);

    /**
     * Sets the direction of an audio source
     * @param source The audio source to modify
     * @param x The X Coordinate of the direction
     * @param y The Y Coordinate of the direction
     * @param z The Z Coordinate of the direction
     */
    extern void sfx_source_direction(struct SFXAudioSource* source, float x, float y, float z);

    /**
     * Sets the velocity of an audio source
     * @param source The audio source to modify
     * @param x The X Coordinate of the velocity
     * @param y The Y Coordinate of the velocity
     * @param z The Z Coordinate of the velocity
     */
    extern void sfx_source_velocity(struct SFXAudioSource* source, float x, float y, float z);

    /**
     * Sets the volume of an audio source
     * @param source The audio source to modify
     * @param volume The new volume to set
     */
    extern void sfx_source_volume(struct SFXAudioSource* source, float volume);

    /**
     * Sets the pitch of an audio source
     * @param source The audio source to modify
     * @param pitch The new pitch for the audio source
     * @example sfx_set_pitch(source, 1.2f);
     */
    extern void sfx_source_pitch(struct SFXAudioSource* source, float pitch);

    /**
     * Sets the frequency of an audio source
     * @param source The audio source to modify
     * @param frequency The new frequency for the audio source
     * @example sfx_set_frequency(source, 44100);
     */
    extern void sfx_source_frequency(struct SFXAudioSource* source, int frequency);

    /**
     * Sets the cone of an audio source
     * @param source The audio source to modify
     * @param innerAngle The inner angle of the cone
     * @param outerAngle The outer angle of the cone
     * @param outerVolume The outer volume of the cone
     */
    extern void sfx_source_cone(struct SFXAudioSource* source, float innerAngle, float outerAngle, float outerVolume);

    /**
     * Sets whether or not the position of this audio source is
     * relative to the position of the listener
     * @param source The audio source to modify
     * @param relative true if the position of this audio source
     * should be relative to the listener position, false otherwise
     */
    extern void sfx_source_relative(struct SFXAudioSource* source, bool relative);

    /**
     * Sets the listener position
     * @param x The X Coordinate of the position
     * @param y The Y Coordinate of the position
     * @param z The Z Coordinate of the position
     */
    extern void sfx_listener_position(float x, float y, float z);

    /**
     * Sets the listener velocity
     * @param x The X Coordinate of the velocity
     * @param y The Y Coordinate of the velocity
     * @param z The Z Coordinate of the velocity
     */
    extern void sfx_listener_velocity(float x, float y, float z);

    /**
     * Sets the listener orientation
     * @param forwardX The X Coordinate of the forward vector
     * @param forwardY The Y Coordinate of the forward vector
     * @param forwardZ The Z Coordinate of the forward vector
     * @param upX The X Coordinate of the up vector
     * @param upY The Y Coordinate of the up vector
     * @param upZ The Z Coordinate of the up vector
     */
    extern void sfx_listener_orientation(float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ);

#ifdef __cplusplus
}
#endif

#endif // __OPEN_SFX_H_
