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

GameData store(GameData data, Items items) {
    // Good old bool inputRecognized{ false };
    bool inputRecognized{ false };
    // Only in a char because it isn't going to be very big
    char input;
    std::cout << "Welcome to the " << green << "shop\n" << reset;
    while (!inputRecognized) {
        std::cout << "Choose an option:\n" << red << "(1)" << magenta
        << " Weapons\n" << red << "(2)" << magenta << " Healing Items "
        << reset;
        std::cin >> input;
    }
    return data;
}