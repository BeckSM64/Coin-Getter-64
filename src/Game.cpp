#include <libdragon.h>
#include "Game.h"

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

    // Init audio subsystem
    audio_init(44100, 20);
	mixer_init(32);
	mixer_ch_set_limits(6, 0, 128000, 0);

    // Load WAV file and play it
    wav64_open(&level_music, "rom:/endo.wav64");
    wav64_play(&level_music, 0);
}

void Game::update() {

    // Play audio, poll the mixer
    if (audio_can_write()) {
        short *buf = audio_write_begin();
        mixer_poll(buf, audio_get_buffer_length());
        audio_write_end();
    }

    // Get controller input
    controller_scan();
    SI_controllers_state_t controller_state = get_keys_pressed();

    // Update entities
    player->update(controller_state);
    enemy->update();
}

void Game::draw() {

    // Create a background color to fill screen
    uint32_t background_color = graphics_make_color(20, 15, 36, 0);

    // Get the display input
    surface_t *display_surface = display_get();

    // Fill the screen with a solid color
    graphics_fill_screen(display_surface, background_color);

    // Draw entities
    player->draw(display_surface);
    enemy->draw(display_surface);

    // Show the display surface
    display_show(display_surface);
}

void Game::run() {

    update();
    draw();
}
