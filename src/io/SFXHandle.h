#pragma once

namespace OpenSFX
{
    class SFXHandle
    {
    public:
        static SFXHandle* open(const char* file);

        virtual bool openFile(const char* file) = 0;
        virtual size_t read(unsigned short* ptr, size_t items) = 0;

        const char* getPath() const { return mPath; }
        int getChannels() const { return mChannels; }
        int getSampleRate() const { return mSampleRate; }

        virtual ~SFXHandle();
    protected:
        SFXHandle();

        const char* mPath;
        int mChannels;
        int mSampleRate;
    };
}
