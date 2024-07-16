#include <iostream>
#include <libdragon.h>
#include <ctime>
#include "Player.h"

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
    display_init( RESOLUTION_640x480, DEPTH_32_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE_ANTIALIAS );

    // Color for player
    //uint32_t player_color = graphics_make_color(255, 0, 0, 0);

    // Draw the player box
    //graphics_draw_box(display_surface, 100, 100, 10, 10, player_color);

    // Initialize DFS
    dfs_init(DFS_DEFAULT_LOCATION);

    // Load sprite for player
    // sprite_t *player = sprite_load("rom:/player.sprite");
    Player *player = new Player();

    // Load sprite for enemy
    sprite_t *enemy = sprite_load("rom:/enemy.sprite");

    int posX = 0;
    int posY = 0;

    // Initialize controller subsystem
    controller_init();

    while(1) {
        
        controller_scan();
        SI_controllers_state_t controller_state = get_keys_pressed();

        player->update(controller_state);

        // Get the display input
        surface_t *display_surface = display_get();

        // Fill the screen with a solid color
        graphics_fill_screen(display_surface, background_color);

        // Use the sprite
        player->draw(display_surface);

        //graphics_draw_sprite_trans(display_surface, posX++, posY++, enemy);

        // Show the display surface
        display_show(display_surface);
    }
}