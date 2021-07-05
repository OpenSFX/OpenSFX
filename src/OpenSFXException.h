#pragma once

namespace OpenSFX
{
    struct OpenSFXException
    {
        const char *message;

        OpenSFXException(const char *message) : message(message) {}
    };
}