#ifndef __COMBAT_H__
#define __COMBAT_H__

#include <vector>
#include <string>

class Enemy {
private:
    int m_name;
    int m_health;
    int m_wit;
    int m_stoneface;
    int m_xpGiven;
public:
    std::vector<std::string> enemyLines;
    Enemy(int name, int health, int wit, int stoneface, std::vector<std::string> lines);
    int getName();
    int getHealth();
    int getWit();
    int getStoneface();
    int getXpGiven();
};

#endif // __COMBAT_H__