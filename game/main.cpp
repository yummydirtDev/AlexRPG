#include "main.h"

int main() {
    // Intro and initialize
    GameData data{ initGame() };
    data = gameLoop(data);
    // Game loop
        // check state
        // do move
        // save game
    return 0;
}