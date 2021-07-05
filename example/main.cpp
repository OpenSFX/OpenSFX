#include <iostream>
#include <OpenSFX.h>

int main(int argc, const char** argv)
{
    std::cout << "OpenSFX Example" << std::endl;

    if (argc < 2)
    {
        std::cout << "No audio file specified" << std::endl;
        return 0;
    }

    const char* path = argv[1];

    std::cout << "Loading File: '" << path << "'..." << std::endl;
    SFXAudioFile* file = sfx_file_load(path);

    std::cout << "Creating Source..." << std::endl;
    SFXAudioSource* source = sfx_source_create(file);

    std::cout << "Freeing File..." << std::endl;
    sfx_file_free(file);

    std::cout << "Playing Source..." << std::endl;
    sfx_source_play(source);

    std::cout << "Waiting for source to finish playing..." << std::endl;
    while (sfx_source_status(source) == SFX_PLAYING);

    std::cout << "Freeing Source..." << std::endl;
    sfx_source_free(source);

    std::cout << "Done." << std::endl;

    return 0;
}
