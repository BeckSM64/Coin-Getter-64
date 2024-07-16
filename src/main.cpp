#include <iostream>
#include <libdragon.h>
#include <ctime>
#include "Player.h"
#include "Enemy.h"

int getRandomNumberInRange(int min, int max) {
    // Ensure the range is valid
    if (min > max) {
        return -1; // Error value, you can handle it as you like
    }

    // Generate a random number in the range [min, max]
    return rand() % (max - min + 1) + min;
}

int main(void)
{
    // Debug console code
    //console_init();

    // Seed the random number generator
    srand(time(0));
    //printf("%d", getRandomNumberInRange(0, 400));

    // Create a background color to fill screen
    uint32_t background_color = graphics_make_color(20, 15, 36, 0);

    // Create display input
    display_init( RESOLUTION_640x480, DEPTH_32_BPP, 3, GAMMA_NONE, FILTERS_DISABLED );

    // Color for player
    //uint32_t player_color = graphics_make_color(255, 0, 0, 0);

    // Draw the player box
    //graphics_draw_box(display_surface, 100, 100, 10, 10, player_color);

    // Initialize DFS
    dfs_init(DFS_DEFAULT_LOCATION);

    // Create player
    Player *player = new Player();

    // Create enemy
    Enemy *enemy = new Enemy();

    // Initialize controller subsystem
    controller_init();

    // Init audio subsystem
    audio_init(44100, 20);
	mixer_init(32);
	mixer_ch_set_limits(6, 0, 128000, 0);

    // Load WAV file and play it
    wav64_t level_music;
    wav64_open(&level_music, "rom:/endo.wav64");
    wav64_play(&level_music, 0);

    while(1) {

        // Play audio, poll the mixer
        if (audio_can_write()) {
            short *buf = audio_write_begin();
            mixer_poll(buf, audio_get_buffer_length());
            audio_write_end();
        }
        
        controller_scan();
        SI_controllers_state_t controller_state = get_keys_pressed();

        player->update(controller_state);
        enemy->update();

        // Get the display input
        surface_t *display_surface = display_get();

        // Fill the screen with a solid color
        graphics_fill_screen(display_surface, background_color);

        // Use the sprite
        player->draw(display_surface);
        enemy->draw(display_surface);

        //graphics_fill_screen(display_surface, background_color);

        // Show the display surface
        display_show(display_surface);

        // Stop a WAV file, will only need this if level is changed or something
        //mixer_ch_stop(0);
    }
}