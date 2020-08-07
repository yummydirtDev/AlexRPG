#include "savehandler.h"

GameData::GameData(int turns, std::vector<int> items, int maxHealth, int currentHealth, int wit, int stoneface) {
    m_turns = turns;
    m_items = items;
    m_maxHealth = maxHealth;
    m_currentHealth = currentHealth;
    m_wit = wit;
    m_stoneface = stoneface;
}

int GameData::getTurns() {
    return m_turns;
}

std::vector<int> GameData::getItems() {
    return m_items;
}

int GameData::getMaxHealth() {
    return m_maxHealth;
}

int GameData::getCurrentHealth() {
    return m_currentHealth;
}
/*class GameData {
    private:
        int m_turns;
        std::vector<int> m_items;
        int m_maxHealth;
        int m_currentHealth;
        int m_wit;
        int m_stoneface;
    public:
        GameData(int turns, std::vector<int> items, int maxHealth, int wit, int stoneface) {
            m_turns = turns;
            m_items = items;
            m_maxHealth = maxHealth;
            m_wit = wit;
            m_stoneface = stoneface;
        }
        int getTurns() {
            return m_turns;
        }
        std::vector<int> getItems() {
            return m_items;
        }
        int getMaxHealth() {
            return m_maxHealth;
        }
        int getCurrentHealth() {
            return m_currentHealth;
        }
        int getWit() {
            return m_wit;
        }
        int getStoneface() {
            return m_stoneface;
        }
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
}; */