#ifndef __COMBAT_H__
#define __COMBAT_H__

#include <vector>
#include <string>
#include <cmath>
#include <unistd.h>
#include <termios.h>
#include "savehandler.h"
#include "../lib/random.hpp"
#include "../lib/color.h"
#include "items.h"

char getch(void);

class Enemy {
private:
    std::string m_name;
    int m_health;
    int m_wit;
    int m_stoneface;
    int m_xpGiven;
    int m_weaponStrength;
public:
    std::vector<std::string> enemyLines;
    std::vector<std::string> userLines;
    Enemy(std::string name, int health, int wit, int stoneface, int xpGiven, std::vector<std::string> lines, int weaponStrength);
    std::string getName();
    int getHealth();
    int getWit();
    int getStoneface();
    int getXpGiven();
    int getWeaponStrength();
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
    Enemy sam{ "Sam", 20, 2, 2, 50, samELines, 5 };
};

#endif // __COMBAT_H__
