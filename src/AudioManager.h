#include <libdragon.h>

class AudioManager {

    private:
        wav64_t level_music;

    public:
        AudioManager();
        void playAudio();
};