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
#ifndef __COMBAT_H__
#define __COMBAT_H__

#include <vector>
#include <string>
#include <cmath>
#ifdef __linux__
#include <unistd.h>
#include <termios.h>
#endif
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>

#define ESC "\x1b"
#define CSI "\x1b["
bool EnableVTMode();
#endif
#include "savehandler.h"
#include "../lib/random.hpp"
#include "../lib/color.h"
#include "items.h"
#include "../../alexsaveload/saveload.h"

#ifdef __linux__
char getch(void);
#endif

class Enemy {
private:
    std::string m_name;
    int m_health;
    int m_wit;
    int m_stoneface;
    int m_xpGiven;
    int m_weaponStrength;
    int m_cashReward;
public:
    std::vector<std::string> enemyLines;
    std::vector<std::string> userLines;
    Enemy(std::string name, int health, int wit, int stoneface, int xpGiven, 
        std::vector<std::string> lines, int weaponStrength, int cashReward);
    std::string getName();
    int getHealth();
    int getWit();
    int getStoneface();
    int getXpGiven();
    int getWeaponStrength();
    int getCashReward();
};

class Enemies {
public:
    GameData fight(Enemy enemy, GameData data, Items items);
    std::vector<std::string> painLines {
        "kneecaps pop off and land 50 miles away",
        "leg breaks in two",
        "neck says bye bye",
        "elbows go inverted",
        "eyes are stuck crossed",
        "appendix is scratched",
        "toes collapse"
    };
    std::vector<std::string> hurtLines {
        "Ow, my knees! My spindly, spindly knees!",
        "ZOINKS!",
        "Owie!",
        "The pain is immense",
        "Oh crap my nose fell off"
    };
    std::vector<std::string> userLines {
        "Let me get my sharpie",
        "Gangnam Style!",
        "You look like someone who would leave their hot pockets in the microwave",
        "Piggy goes oink. *OINK OINK*",
        "What's the deal with sunglasses?",
        "Mickey, my friend!",
        "Enough! Absolutely no more!",
        "Complete and utter silence",
        "You have small thighs",
        "*Vroom vroom* Sorry, that's my very expensive car!",
        "*Coughs* Sorry but I've got a case of the 'vid",
        "As Bill Cosby once said:"
    };
    std::vector<std::string> samELines {
        "Yo mama so fat that she is over 150 pounds!",
        "Two guys walk into a bar, they get a concussion",
        "Mah dog!",
        "The bar had to be shut down after CTE concerns",
        "Yo mama got brain trauma from a bar"
    };
    std::vector<std::string> jonELines {
        "I bet your company doesn't match 401k",
        "You're wrong: here's why",
        "Do you even budget bro?",
        "Sounds rather UNPRODUCTIVE!"
    };
    Enemy sam{ "Sam", 20, 2, 2, 50, samELines, 5, 10 };
    Enemy jon{ "Jon", 20, 2, 2, 5, jonELines, 5, 10 };
};

#endif // __COMBAT_H__
