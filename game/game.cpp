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
                std::cout << "Alright! AlexRPG is an RPG where you play as Alex, on a journey to " <<
                    "destroy Googular, a biting allegory for corporate America.\n";
                std::cout << "Rather than fight with weapons, you tell jokes. " <<
                    "The measure of joke-telling ability is called wit. To start out you have " <<
                    data.getWit() << " wit.\n";
                break;
            case 'n':
            case 'N':
                inputRecognized = true;
                break;
            default:
                std::cout << "Input not recognized, try again\n";
                break;
            }
        }
    }
    return data;
}