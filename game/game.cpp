#include "game.h"

GameData gameLoop(GameData data) {
    char yOrN;
    bool inputRecognized{ false };
    switch (data.getTurns()) {
    case 0:
        std::cout << "You appear to be new to AlexRPG, would you like to hear how things work? (Y or N) ";
        while (!inputRecognized) {
            std::cin >> yOrN;
            switch (yOrN) {
            case 'y':
            case 'Y':
                inputRecognized = true;
                break;
            case 'n':
            case 'N':
                inputRecognized = true;
                break;
            default:
                break;
            }
        }
    }
    return data;
}