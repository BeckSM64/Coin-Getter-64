#pragma once
#include "Screen.h"
#include "AudioManager.h"
#include "Player.h"
#include "Enemy.h"

class MainGameScreen : public Screen {

    private:
        AudioManager *audioManager = nullptr;
        Player *player = nullptr;
        Enemy *enemy = nullptr;

    public:
        MainGameScreen();
        ~MainGameScreen();
        void update(joypad_inputs_t &controller_state) override;
        void draw(surface_t *display_surface) override;
};
