#include "init.h"

static int newGame(GameData* data);

GameData initGame() {
    // This function (as the name suggests) initializes the game

    char newOrOld;
    std::vector<std::string> blankVector{ "0" };
    bool inputRecognized{ false };
    GameData data{};

    std::cout << "Welcome to AlexRPG" << '\n';
    while (!inputRecognized) {
        std::cout << "Would you like to " << red << "(l)" << magenta
        << "oad a save" << reset << " or" << magenta << " start a " << red
        << "(n)" << magenta << "ew adventure" << reset << "? ";
        std::cin >> newOrOld;
        std::cout << '\n';
        switch (newOrOld) {
        case 'l':
        case 'L':
            std::cout << "Attempting to load the save file..." << std::endl;
            inputRecognized = true;
            if (data.loadFromVector(loadGame()) == 1) {
                std::cout << "Game data could not be loaded, would you like to start a new game?\n";
                if (newGame(&data) == 0) {
                    break;
                }
            } else {
                std::cout << "Game loaded successfully!\n";
                break;
            }
        case 'n':
        case 'N':
            if (newGame(&data) == 0) {
                inputRecognized = true;
                break;
            }
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input not recognized, trying again." << std::endl;
        }
    }
    return data;
}

static int newGame(GameData* data) {
    std::string confirm;
    std::string newName;

    std::cout << "This will erase your current save data. \nType confirm to confirm. \n";
    std::cin >> confirm;
    if (confirm == "confirm" || confirm == "Confirm") {
        std::cout << "What do you want to name your player? (Blank for default) ";
        std::cin.ignore();
        std::getline(std::cin, newName);
        if (newName == "") {
            newName = "Alex";
        }
        data->setUserName(newName);
        saveGame(data->saveToVector());
        std::cout << "Successfully overwrote the save file!\n";
        return 0;
    } else {
        std::cout << "Confirm not typed" << '\n';
        return 1;
    }
}