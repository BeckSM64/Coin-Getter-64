#include <ctime>
#include "MainMenu.h"
#include "Globals.h"

MainMenu::MainMenu() {
    audioManager = new AudioManager();

    // Seed the random number generator
    srand(time(0));
    
    // Init RDPQ library to interface with RDP
    rdpq_init();

    // Load font
    font = rdpq_font_load("rom:/RetroComputer.font64");
    fontStyle.color = RGBA32(0xED, 0xAE, 0x49, 0xFF);
    rdpq_font_style(font, 0, &fontStyle);

    // Register font
    rdpq_text_register_font(1, font);
}

MainMenu::~MainMenu() {

    delete (audioManager);    
    audioManager = nullptr;
    font = nullptr;
}

void MainMenu::update(joypad_inputs_t &controller_state) {

    // Play audio
    audioManager->playAudio();

    // Check for input
    if (controller_state.btn.start == 1) {
        currentGameState = states::GAMESCREEN; // Exit the main menu and start the game
    }
}

void MainMenu::draw(surface_t *display_surface) {

    fontStyle.color = RGBA32(getRandomNumberInRange(0, 255), getRandomNumberInRange(0, 255), getRandomNumberInRange(0, 255), 0xFF);
    rdpq_font_style(font, 0, &fontStyle);

    //rdpq_attach_clear(display_surface, NULL);
    rdpq_attach(display_surface, NULL);
    rdpq_text_print(NULL, 1, 100.0f, 100.0f, "[COIN GETTER]\0");

    rdpq_detach_show();
}

uint8_t MainMenu::getRandomNumberInRange(uint8_t min, uint8_t max) {
    // Ensure the range is valid
    if (min > max) {
        return -1; // Error value, you can handle it as you like
    }

    // Generate a random number in the range [min, max]
    return rand() % (max - min + 1) + min;
}
