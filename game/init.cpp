#include "init.h"

void initGame() {
    // TODO: Load a save file

    char newOrOld;
    std::string confirm;
    std::vector<std::string> blankVector{"0"};

    std::cout << "Welcome to AlexRPG" << '\n';
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
            std::cout << "This will erase your current save data. \n Type confirm to confirm. \n";
            std::cin >> confirm;
            if (confirm == "confirm") {
                saveGame(blankVector);
            }
    }
}