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
#include "levelhandler.h"

GameData checkLevelUp(GameData data) {
    #define UPCOMING_LEVEL ((data.getXp() - (data.getXp() % 100)) / 100)
    if (UPCOMING_LEVEL > data.getLevel()) {
        char upgradeChoice;
        bool inputRecognized{ false };
        data.setLevel(UPCOMING_LEVEL);
        std::cout << "You have leveled up to " << red << "Level " << data.getLevel() 
        << '\n' << reset;
        while (!inputRecognized) {
            std::cout << "Would you like to upgrade " << red << "(w)" << blue << "it" 
            << reset << " or " << red << "(s)" << blue << "toneface " << reset;
            std::cin >> upgradeChoice;
            switch (upgradeChoice) {
            case 'w':
            case 'W':
                data.setWit(data.getWit() + 1);
                inputRecognized = true;
                std::cout << blue << "Your wit is now at " << reset << data.getWit() 
                << '\n';
                break;
            case 's':
            case 'S':
                data.setStoneface(data.getStoneface() + 1);
                inputRecognized = true;
                break;
            default:
                // Clear bad input flag
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    #undef UPCOMING_LEVEL
    return data;
}
