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
    Enemy(std::string name, int health, int wit, int stoneface, int xpGiven, std::vector<std::string> lines);
    std::string getName();
    int getHealth();
    int getWit();
    int getStoneface();
    int getXpGiven();
};

#endif // __COMBAT_H__