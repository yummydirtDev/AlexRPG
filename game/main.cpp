#include "main.h"

int main() {
    std::vector<int> tems{0};
    GameData penis{1, tems, 1, 1, 1, 1};
    // Intro and initialize
    initGame();
    std::cout << penis.getCurrentHealth();
    // Game loop
        // check state
        // do move
        // save game
    return 0;
}