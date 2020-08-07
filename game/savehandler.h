#ifndef __SAVEHANDLER_H__
#define __SAVEHANDLER_H__

#include <iostream>
#include <vector>
#include <string>

class GameData {
    private:
        int m_turns;
        std::vector<int> m_items;
        int m_maxHealth;
        int m_currentHealth;
        int m_wit;
        int m_stoneface;
    public:
        GameData(int turns, std::vector<int> items, int maxHealth, int currentHealth, int wit, int stoneface);
        int getTurns();
        std::vector<int> getItems();
        int getMaxHealth();
        int getCurrentHealth();
        int getWit();
        int getStoneface();
        void setTurns(int turns);
        void setItems(std::vector<int> items);
        void setMaxHealth(int maxHealth);
        void setCurrentHealth(int currentHealth);
        void setWit(int wit);
        void setStoneface(int stoneface);
        int loadFromVector(std::vector<std::string> saveData);
};

#endif // __SAVEHANDLER_H__