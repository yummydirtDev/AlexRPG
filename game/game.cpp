#include "game.h"

GameData gameLoop(GameData data) {
    switch (data.getTurns()) {
    case 0:
        std::cout << "You appear to be new to AlexRPG, would you like to hear how things work? (Y or N) ";
    }
    return data;
}