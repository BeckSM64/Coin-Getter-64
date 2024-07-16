#include <libdragon.h>
#include "Player.h"

Player::Player() {
    posX = 100;
    posY = 100;
    velX = 0;
    velY = 0;
    player = sprite_load("rom:/player.sprite");
}

int Player::getPosX() {
    return posX;
}

int Player::getPosY() {
    return posY;
}

int Player::getVelX() {
    return velX;
}

int Player::getVelY() {
    return velY;
}

void Player::setPosX(int x) {
    posX = x;
}

void Player::setPosY(int y) {
    posY = y;
}


void Player::setVelX(int velX) {
    this->velX = velX;
}

void Player::setVelY(int velY) {
    this->velY = velY;
}

void Player::draw(surface_t *display_surface) {
    graphics_draw_sprite(display_surface, posX, posY, player);
}

void Player::update(SI_controllers_state_t &controller_state) {

    // Update player x velocity based on input
    if (controller_state.c->x > 10) {
        velX = 3;
    } else if (controller_state.c->x < -10) {
        velX = -3;
    } else {
        velX = 0;
    }

    // Update y velocity
    if (controller_state.c->y > 10) {
        velY = -3;
    } else if (controller_state.c->y < -10) {
        velY = 3;
    } else {
        velY = 0;
    }

    // Update player position
    posX += velX;
    posY += velY;

    // Constrain to screen
    if ((posX + player->width) > 640) {
        posX = 640 - player->width;
    } else if (posX < 0) {
        posX = 0;
    }

    if (posY + player->height > 480) {
        posY = 480 - player->height;
    } else if (posY < 0) {
        posY = 0;
    }
}
