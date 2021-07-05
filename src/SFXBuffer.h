#pragma once

#include <AL/al.h>
#include <vector>

namespace OpenSFX
{
    class SFXBuffer
    {
    public:
        static SFXBuffer* get();

        ALuint addSound(const char* filename);
        bool removeSound(const ALuint& buffer);

    private:
        SFXBuffer();
        ~SFXBuffer();

        std::vector<ALuint> mBuffers;
    };
}
