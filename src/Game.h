#include <libdragon.h>
#include "Player.h"
#include "Enemy.h"
#include "AudioManager.h"
#include "MainMenu.h"

class Game {

    private:
        Player *player = nullptr;
        Enemy *enemy = nullptr;
        AudioManager *audioManager = nullptr;
        MainMenu *mainMenu = nullptr;

        void update();
        void draw();

    public:
        Game();
        void run();
};