#pragma once
#include <libdragon.h>

class Enemy {

    private:
        int posX;
        int posY;
        int velX;
        int velY;
        sprite_t *enemy;

    public:
        Enemy();
        int getPosX();
        int getPosY();
        int getVelX();
        int getVelY();
        void setPosX(int x);
        void setPosY(int y);
        void setVelX(int velX);
        void setVelY(int velY);
        void draw(surface_t *display_surface);
        void update();
};