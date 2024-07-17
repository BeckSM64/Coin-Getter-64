#include <libdragon.h>
#include "Player.h"
#include "Enemy.h"

class Game {

    private:
        Player *player = nullptr;
        Enemy * enemy = nullptr;
        wav64_t level_music;

        void update();
        void draw();

    public:
        Game();
        void run();
};