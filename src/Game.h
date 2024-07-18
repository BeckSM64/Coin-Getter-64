#include <libdragon.h>
#include "AudioManager.h"
#include "MainMenu.h"
#include "MainGameScreen.h"
#include "Globals.h"

class Game {

    private:
        MainMenu *mainMenu = nullptr;
        MainGameScreen *mainGameScreen = nullptr;
        int currentGameState;
        void checkGameState();

    public:
        Game();
        void run();
};