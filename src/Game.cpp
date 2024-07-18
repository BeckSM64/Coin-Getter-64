#include <libdragon.h>
#include "Game.h"
#include "MainMenu.h"

Game::Game() {

    // Create display input
    display_init( RESOLUTION_640x480, DEPTH_32_BPP, 3, GAMMA_NONE, FILTERS_DISABLED );

    // Initialize DFS
    dfs_init(DFS_DEFAULT_LOCATION);

    // Initialize controller subsystem
    controller_init();

    // Create player
    player = new Player();
    enemy = new Enemy();
    mainMenu = new MainMenu();
}

void Game::update() {

    // Get controller input
    controller_scan();
    SI_controllers_state_t controller_state = get_keys_pressed();

    if (mainMenu != nullptr) {

        mainMenu->update(controller_state);

        // Check if game has been started
        if ( mainMenu->startGame ) {
            delete(mainMenu);
            mainMenu = nullptr;
        }
    } else {

        if (audioManager == nullptr) {
            // Create audio manager
            audioManager = new AudioManager();
        }

        // Update entities
        player->update(controller_state);
        enemy->update();

        // Play audio
        audioManager->playAudio();
    }
}

void Game::draw() {

    // Create a background color to fill screen
    uint32_t background_color = graphics_make_color(20, 15, 36, 0);

    // Get the display input
    surface_t *display_surface = display_get();

    // Fill the screen with a solid color
    graphics_fill_screen(display_surface, background_color);

    if (mainMenu != nullptr) {

        mainMenu->draw(display_surface);

    } else {

        // Draw entities
        player->draw(display_surface);
        enemy->draw(display_surface);

        // Show the display surface
        display_show(display_surface);
    }
}

void Game::run() {

    update();
    draw();
}
