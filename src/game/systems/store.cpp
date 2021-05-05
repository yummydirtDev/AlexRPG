/*
    Copyright 2020 Alex Frutkin
    
    This file is part of AlexRPG.

    AlexRPG is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AlexRPG is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with AlexRPG.  If not, see <https://www.gnu.org/licenses/>.

*/
#include "store.h"

GameData weaponShop(GameData data, Items items, int storeNumber) {
    // the same code as below
    bool inputRecognized{ false };

    std::string input;

    bool purchasing{ true };
    std::cout << "Select a " << red << "weapon" << reset << ":\n";
    while (purchasing) {
        if (storeNumber == 1) {
            while (!inputRecognized) {
                std::cout << red << "(1)" << magenta << " Toy Microphone\n" << red
                << "(Q)" << magenta << " Quit ";
                std::cin >> input;
                if (input == "1") {
                    data.addItem(items.toyMic);
                    inputRecognized = true;
                } else if (input == "Q" || input == "q") {
                    purchasing = false;
                    inputRecognized = true;
                }
            }
        }
    }
    return data;
}

GameData store(GameData data, Items items, int storeNumber) {
    // Good old bool inputRecognized{ false };
    bool inputRecognized{ false };
    // Only in a char because it isn't going to be very big
    char input;
    // is the user done?
    bool purchasing{ true };
    std::cout << "Welcome to the " << green << "shop\n" << reset;
    while (purchasing) {
        while (!inputRecognized) {
            std::cout << "Choose an option:\n" << red << "(1)" << magenta
            << " Weapons\n" << red << "(2)" << magenta << " Healing Items "
            << reset << red << "(Q)" << magenta << " Quit ";
            std::cin >> input;
            switch (input) {
            case 1:
                std::cout << red << "Weapons\n" << reset;
                inputRecognized = true;
                break;
            case 2:
                std::cout << red << "Healing Items\n" << reset;
                inputRecognized = true; 
                break;           
            default:
                std::cout << "Input not recognized\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        inputRecognized = false;
        // Use the input variable to select the list
        if (input == 1){
            data = weaponShop(data, items, storeNumber);
        }
    }
    return data;
}