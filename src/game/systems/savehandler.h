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
#ifndef __SAVEHANDLER_H__
#define __SAVEHANDLER_H__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "items.h"
#include "../lib/color.h"

class GameData {
private:
    /*
    Explanation of member variables:
    userName: the user's name
    turns: the number of turns that has passed
    maxHealth: the user's max health
    currentHealth: the user's current health
    wit: the user's "wit" or combat ability
    stoneface: the user's defense capability
    xp: the user's xp amount
    level: the number of level's the user has acheived
    */
    std::string m_userName;
    int m_turns;
    int m_maxHealth;
    int m_currentHealth;
    int m_wit;
    int m_stoneface;
    int m_xp;
    int m_level;
    int m_cash;
public:
    // A lot of constructors and get/set
    GameData(std::string userName, int turns, std::vector<int> items,
            int maxHealth, int currentHealth, int wit, int stoneface, int xp, int level);
    GameData();
    int gameStatus{ 0 };
    std::vector<int> m_items;
    std::string getUserName();
    int getTurns();
    int getMaxHealth();
    int getCurrentHealth();
    int getWit();
    int getStoneface();
    int getXp();
    int getLevel();
    int getCash();
    void setUserName(std::string userName);
    void setTurns(int turns);
    void setMaxHealth(int maxHealth);
    void setCurrentHealth(int currentHealth);
    void setWit(int wit);
    void setStoneface(int stoneface);
    void setXp(int xp);
    void setLevel(int level);
    void setCash(int cash);
    void addItem(Item item);
    void removeItem(Item item);
    Item getWeapon(Items items);
    // Save/Load mechanism
    int loadFromVector(std::vector<std::string> saveData);
    std::vector<std::string> saveToVector();
    // Check the players status
    void checkStatus();
    void checkInventory(Items items);
    char checkInventory(Items items, bool usableInventory);
};

#endif // __SAVEHANDLER_H__