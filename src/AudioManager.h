#pragma once

#include <libdragon.h>

class AudioManager {

    private:
        wav64_t level_music;

    public:
        AudioManager();
        ~AudioManager();
        void playAudio();
};