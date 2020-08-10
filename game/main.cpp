#include "main.h"

int main() {
    // Intro and initialize
    GameData data{ initGame() };
    while (data.gameStatus == 0) {
        data = gameLoop(data);
    }
    // Game loop
        // check state
        // do move
        // save game
    return 0;
}