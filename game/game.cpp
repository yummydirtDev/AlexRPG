#include "game.h"

static inline void tutorial(GameData *data) {
    std::cout << "Alright! AlexRPG is an RPG where you play as Alex, on a journey to " <<
        "destroy Googular, a biting allegory for corporate America.\n";
    std::cout << "Rather than fight with weapons, you tell jokes. " <<
        "The measure of joke-telling ability is called wit. To start out you have " <<
        data->getWit() << " wit.\n";
    std::cout << "While there is no real violence from the attacking side, these jokes cause real damage. " <<
        "The defending side will have real and gruesome injuries from these jokes.\n";
    std::cout << "The defending side can attempt a comeback to reverse the damage, " <<
    "but if it fails they lose the turn and take the damage.\n";
}

GameData gameLoop(GameData data) {
    Item toyMic{ "Toy Microphone", 0, 1, 0, 5, 0 };
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
                tutorial(&data);
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
        std::cout << "Alright then! Let's begin. You find yourself in a ditch near downtown Phoenix, " <<
        "the city skyline in the horizon.\n";
        std::cout << "You spot a crappy microphone near you on the ground, " <<
        "you pick it up just in case it might help.\n";
        data.addItem(toyMic);
    }
    return data;
}