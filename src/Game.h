#include <libdragon.h>
#include "Player.h"
#include "Enemy.h"
#include "AudioManager.h"

class Game {

    private:
        Player *player = nullptr;
        Enemy *enemy = nullptr;
        AudioManager *audioManager = nullptr;

        void update();
        void draw();

    public:
        Game();
        void run();
};