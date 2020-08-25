#ifndef __COMBAT_H__
#define __COMBAT_H__

#include <vector>
#include <string>

class Enemy {
private:
    std::string m_name;
    int m_health;
    int m_wit;
    int m_stoneface;
    int m_xpGiven;
public:
    std::vector<std::string> enemyLines;
    std::vector<std::string> userLines;
    Enemy(std::string name, int health, int wit, int stoneface, int xpGiven, std::vector<std::string> lines);
    std::string getName();
    int getHealth();
    int getWit();
    int getStoneface();
    int getXpGiven();
};

class Enemies {
public:
    std::vector<std::string> userLines {
        "Let me get my sharpie",
        "Gangnam Style!",
        "You look like someone who would leave their hot pockets in the microwave"
    };
    std::vector<std::string> samELines {
        "Yo mama so fat that she is over 150 pounds!",
        "Two guys walk into a bar, they get a concussion",
        "Mah dog!"
    };
};

#endif // __COMBAT_H__