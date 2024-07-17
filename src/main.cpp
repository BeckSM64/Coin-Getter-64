#include <iostream>
#include <libdragon.h>
#include <ctime>
#include "Game.h"

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
    // Seed the random number generator
    srand(time(0));

    // Create game object to manage game
    Game *game = new Game();

    while(true) {
        game->run();
    }
}
