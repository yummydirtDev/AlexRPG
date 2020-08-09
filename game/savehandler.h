#ifndef __SAVEHANDLER_H__
#define __SAVEHANDLER_H__

#include <iostream>
#include <vector>
#include <string>

class GameData {
    private:
        std::string m_userName;
        int m_turns;
        int m_maxHealth;
        int m_currentHealth;
        int m_wit;
        int m_stoneface;
        int m_xp;
        int m_level;
    public:
        GameData(std::string userName, int turns, std::vector<int> items, int maxHealth, int currentHealth, int wit, int stoneface, int xp, int level);
        GameData();
        std::vector<int> m_items;
        std::string getUserName();
        int getTurns();
        int getMaxHealth();
        int getCurrentHealth();
        int getWit();
        int getStoneface();
        int getXp();
        int getLevel();
        void setUserName(std::string userName);
        void setTurns(int turns);
        void setMaxHealth(int maxHealth);
        void setCurrentHealth(int currentHealth);
        void setWit(int wit);
        void setStoneface(int stoneface);
        void setXp(int xp);
        void setLevel(int level);
        int loadFromVector(std::vector<std::string> saveData);
        std::vector<std::string> saveToVector();
};

#endif // __SAVEHANDLER_H__