#include <libdragon.h>
#include "Game.h"
#include "MainMenu.h"
#include "MainGameScreen.h"

Game::Game() {

    // Create display input
    display_init( RESOLUTION_640x480, DEPTH_32_BPP, 3, GAMMA_NONE, FILTERS_DISABLED );

    // Initialize DFS
    dfs_init(DFS_DEFAULT_LOCATION);

    // Initialize controller subsystem
    joypad_init();

    mainMenu = new MainMenu();
}

void Game::update() {

    // Get controller input
    joypad_poll();
    joypad_inputs_t controller_state = joypad_get_inputs(JOYPAD_PORT_1);

    if ( mainMenu != nullptr ) {
        mainMenu->update(controller_state);

        if ( mainMenu->startGame == true ) {
            delete(mainMenu);
            mainMenu = nullptr;
            mainGameScreen = new MainGameScreen();
        }
    } else {
        mainGameScreen->update(controller_state);
    }
}

void Game::draw() {

    // Create a background color to fill screen
    uint32_t background_color = graphics_make_color(20, 15, 36, 0);

    // Get the display input
    surface_t *display_surface = display_get();

    // Fill the screen with a solid color
    graphics_fill_screen(display_surface, background_color);

    // Screen draws go here
    if ( mainMenu != nullptr ) {
        mainMenu->draw(display_surface);
    } else {
        mainGameScreen->draw(display_surface);
    }
}

void Game::run() {

    update();
    draw();
}
