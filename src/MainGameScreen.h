#pragma once
#include "Globals.h"
#include "AudioManager.h"
#include "Player.h"
#include "Enemy.h"

class MainGameScreen {

    private:
        AudioManager *audioManager = nullptr;
        Player *player = nullptr;
        Enemy *enemy = nullptr;

    public:
        MainGameScreen();
        ~MainGameScreen();
        void update(joypad_inputs_t &controller_state);
        void draw(surface_t *display_surface);
        int currentGameState = states::GAMESCREEN;
};
