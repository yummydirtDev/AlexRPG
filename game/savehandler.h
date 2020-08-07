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
        void setTurns(int turns) {
            m_turns = turns;
        }
        void setItems(std::vector<int> items) {
            m_items = items;
        }
        void setMaxHealth(int maxHealth) {
            m_maxHealth = maxHealth;
        }
        void setCurrentHealth(int currentHealth) {
            m_currentHealth = currentHealth;
        }
        void setWit(int wit) {
            m_wit = wit;
        }
        void setStoneface(int stoneface) {
            m_stoneface = stoneface;
        }
};

#endif // __SAVEHANDLER_H__