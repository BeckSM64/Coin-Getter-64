#pragma once
#include "AudioManager.h"

class MainMenu {

    private:
        AudioManager *audioManager = nullptr;
        rdpq_font_t *font = nullptr;
        rdpq_fontstyle_t fontStyle;

    public:
        MainMenu();
        ~MainMenu();
        void update(joypad_inputs_t &controller_state);
        void draw(surface_t *display_surface);
        uint8_t getRandomNumberInRange(uint8_t min, uint8_t max);
        bool startGame = false;
};
