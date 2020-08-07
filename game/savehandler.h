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
        GameData(int turns, std::vector<int> items, int maxHealth, int wit, int stoneface);
};

#endif // __SAVEHANDLER_H__