#include <libdragon.h>
#include "Enemy.h"

Enemy::Enemy() {
    posX = 100;
    posY = 100;
    velX = 4;
    velY = 4;
    enemy = sprite_load("rom:/enemy.sprite");
}

int Enemy::getPosX() {
    return posX;
}

int Enemy::getPosY() {
    return posY;
}

int Enemy::getVelX() {
    return velX;
}

int Enemy::getVelY() {
    return velY;
}

void Enemy::setPosX(int x) {
    posX = x;
}

void Enemy::setPosY(int y) {
    posY = y;
}


void Enemy::setVelX(int velX) {
    this->velX = velX;
}

void Enemy::setVelY(int velY) {
    this->velY = velY;
}

void Enemy::draw(surface_t *display_surface) {
    graphics_draw_sprite(display_surface, posX, posY, enemy);
}

void Enemy::update() {

    // Update enemy position
    posX += velX;
    posY += velY;

    // Constrain to screen
    if ((posX + enemy->width) >= 640) {
        velX *= -1;
    } else if (posX <= 0) {
        velX *= -1;
    }

    if (posY + enemy->height >= 480) {
        velY *= -1;
    } else if (posY <= 0) {
        velY *= -1;
    }
}
