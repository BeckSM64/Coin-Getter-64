#include <libdragon.h>

class Player {

    private:
        int posX;
        int posY;
        int velX;
        int velY;
        sprite_t *player;

    public:
        Player();
        int getPosX();
        int getPosY();
        int getVelX();
        int getVelY();
        void setPosX(int x);
        void setPosY(int y);
        void setVelX(int velX);
        void setVelY(int velY);
        void draw(surface_t *display_surface);
        void update(SI_controllers_state_t &controller_state);
};
