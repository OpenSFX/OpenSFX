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

    std::cout << "Opening Audio Device..." << std::endl;
    if (!sfx_open_device(nullptr))
    {
        std::cerr << "Error: Failed to open audio device!" << std::endl;
        return 1;
    }

    std::cout << "Loading File: '" << path << "'..." << std::endl;
    SFXAudioFile* file = sfx_file_load(path);
    if (file == nullptr)
    {
        std::cerr << "Error: Failed to open file!" << std::endl;
        return 1;
    }

    std::cout << "Creating Source..." << std::endl;
    SFXAudioSource* source = sfx_source_create();

    std::cout << "Loading Data..." << std::endl;
    sfx_source_data(source, file);

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
