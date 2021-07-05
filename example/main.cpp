#include <iostream>
#include <AudioLib.h>

int main(int argc, const char** argv)
{
    std::cout << "Audio Lib Example" << std::endl;

    if (argc < 2)
    {
        std::cout << "No audio file specified" << std::endl;
        return 0;
    }

    const char* path = argv[1];

    std::cout << "Loading File: '" << path << "'..." << std::endl;
    AudioFile* file = sfx_load_file(path);

    std::cout << "Creating Source..." << std::endl;
    AudioSource* source = sfx_create_source(file);

    std::cout << "Freeing File..." << std::endl;
    sfx_free_file(file);

    std::cout << "Playing Source..." << std::endl;
    sfx_play(source);

    std::cout << "Waiting for source to finish playing..." << std::endl;
    while (sfx_get_status(source));

    std::cout << "Freeing Source..." << std::endl;
    sfx_free_source(source);

    std::cout << "Done." << std::endl;

    return 0;
}
