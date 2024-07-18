#include <ctime>
#include "MainGameScreen.h"
#include "Globals.h"
#include "Player.h"
#include "Enemy.h"

MainGameScreen::MainGameScreen() {
    audioManager = new AudioManager();
    player = new Player();
    enemy = new Enemy();
}

MainGameScreen::~MainGameScreen() {

    // Delete audio manager
    delete(audioManager);
    audioManager = nullptr;

    // Delete Player
    delete(player);
    player = nullptr;

    // Delete Enemy
    delete(enemy);
    enemy = nullptr;
}

void MainGameScreen::update(joypad_inputs_t &controller_state) {

    // Update entities
    player->update(controller_state);
    enemy->update();

    // Play audio
    audioManager->playAudio();
}

void MainGameScreen::draw(surface_t *display_surface) {

    // Draw entities
    player->draw(display_surface);
    enemy->draw(display_surface);

    // Show the display surface
    // TODO: Look into moving this into game draw method
    // Only here because main menu is calling rdpq_detach_show()
    // and calling this on top of that will throw an exception
    display_show(display_surface);
}
