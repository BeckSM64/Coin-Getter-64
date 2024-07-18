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

    // Current game state (Starts on Main Menu)
    currentGameState = states::MAINMENU;
}

void Game::run() {

    // Get controller input
    joypad_poll();
    joypad_inputs_t controller_state = joypad_get_inputs(JOYPAD_PORT_1);

    // Create a background color to fill screen
    uint32_t background_color = graphics_make_color(20, 15, 36, 0);

    // Get the display input
    surface_t *display_surface = display_get();

    // Fill the screen with a solid color
    graphics_fill_screen(display_surface, background_color);

    // Check and change game state if needed
    switch (currentGameState) {

        case states::MAINMENU:

            // First check for nullptr
            if ( mainMenu == nullptr ) {
                mainMenu = new MainMenu();
            }

            mainMenu->update(controller_state);
            mainMenu->draw(display_surface);

            // Change state
            if ( mainMenu->currentGameState != states::MAINMENU ) {
                currentGameState = mainMenu->currentGameState;
                delete(mainMenu);
                mainMenu = nullptr;
            }
            break;

        case states::GAMESCREEN:

            // First check for nullptr
            if ( mainGameScreen == nullptr ) {
                mainGameScreen = new MainGameScreen();
            }

            mainGameScreen->update(controller_state);
            mainGameScreen->draw(display_surface);

            // Change state
            if ( mainGameScreen->currentGameState != states::GAMESCREEN ) {
                currentGameState = mainGameScreen->currentGameState;
                delete(mainGameScreen);
                mainGameScreen = nullptr;
            }
            break;

        default:
            break;
    }

}
