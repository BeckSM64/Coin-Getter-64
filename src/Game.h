#include <libdragon.h>
#include "AudioManager.h"
#include "MainMenu.h"
#include "MainGameScreen.h"

class Game {

    private:
        MainMenu *mainMenu = nullptr;
        MainGameScreen *mainGameScreen = nullptr;

        void update();
        void draw();

    public:
        Game();
        void run();
};