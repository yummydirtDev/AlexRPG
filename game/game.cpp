#include "game.h"

GameData gameLoop(GameData data) {
    if (data.getTurns() == 0) {
        std::cout << "You appear to be new to AlexRPG, would you like to hear how things work? (Y or N) ";
    }
    return data;
}