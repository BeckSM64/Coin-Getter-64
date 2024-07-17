#include <libdragon.h>
#include "AudioManager.h"

AudioManager::AudioManager() {

    // Init audio subsystem
    audio_init(44100, 20);
	mixer_init(32);
	mixer_ch_set_limits(6, 0, 128000, 0);

    // Load WAV file and play it
    wav64_open(&level_music, "rom:/endo.wav64");
    wav64_play(&level_music, 0);
}

void AudioManager::playAudio() {

    // Play audio, poll the mixer
    if (audio_can_write()) {
        short *buf = audio_write_begin();
        mixer_poll(buf, audio_get_buffer_length());
        audio_write_end();
    }
}
