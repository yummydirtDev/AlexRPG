#include "init.h"

void initGame() {
    // TODO: Load a save file

    char newOrOld;
    std::string confirm;
    std::vector<std::string> blankVector{"0"};
    bool inputRecognized{false};

    std::cout << "Welcome to AlexRPG" << '\n';
    while (!inputRecognized) {
        std::cout << "Would you like to (l)oad a save or start a (n)ew adventure? ";
        std::cin >> newOrOld;
        std::cout << '\n';
        switch (newOrOld) {
            case 'l':
            case 'L':
                std::cout << "This feature has not been implemented yet, come back soon!" << std::endl;
                break;
            case 'n':
            case 'N':
                std::cout << "This will erase your current save data. \nType confirm to confirm. \n";
                std::cin >> confirm;
                if (confirm == "confirm" || confirm == "Confirm") {
                    saveGame(blankVector);
                    std::cout << "Successfully overwrote the save file!\n";
                    inputRecognized = true;
                    break;
                }
                std::cout << "Confirm not typed" << '\n';
            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input not recognized, trying again." << std::endl;
        }
    }
}