#include "savehandler.h"

// Constructors

GameData::GameData(std::string userName, int turns, std::vector<int> items, int maxHealth, int currentHealth, int wit, int stoneface, int xp, int level) {
    m_userName = userName;
    m_turns = turns;
    m_items = items;
    m_maxHealth = maxHealth;
    m_currentHealth = currentHealth;
    m_wit = wit;
    m_stoneface = stoneface;
    m_xp = xp;
    m_level = level;
}

GameData::GameData() {
    std::vector<int> items{};

    m_userName = "Alex";
    m_turns = 0;
    m_items = items;
    m_maxHealth = 30;
    m_currentHealth = 30;
    m_wit = 5;
    m_stoneface = 5;
    m_xp = 0;
    m_level = 0;
    m_cash = 0;
}

// After this is a set of standard set/get functions

std::string GameData::getUserName() {
    return m_userName;
}

int GameData::getTurns() {
    return m_turns;
}

int GameData::getMaxHealth() {
    return m_maxHealth;
}

int GameData::getCurrentHealth() {
    return m_currentHealth;
}

int GameData::getWit() {
    return m_wit;
}

int GameData::getStoneface() {
    return m_stoneface;
}

int GameData::getXp() {
    return m_xp;
}

int GameData::getLevel() {
    return m_level;
}

int GameData::getCash() {
    return m_cash;
}

void GameData::setUserName(std::string userName) {
    m_userName = userName;
}

void GameData::setTurns(int turns) {
    m_turns = turns;
}

void GameData::setMaxHealth(int maxHealth) {
    m_maxHealth = maxHealth;
}

void GameData::setCurrentHealth(int currentHealth) {
    m_currentHealth = currentHealth;
}

void GameData::setWit(int wit) {
    m_wit = wit;
}

void GameData::setStoneface(int stoneface) {
    m_stoneface = stoneface;
}

void GameData::setXp(int xp) {
    m_xp = xp;
}

void GameData::setLevel(int level) {
    m_level = level;
}

void GameData::setCash(int cash) {
    m_cash = cash;
}

void GameData::addItem(Item item) {
    m_items.resize(m_items.size() + 1, item.getID());
    switch (item.getType()) {
        case 1:
            std::cout << "You have acquired " << green << item.getName() << reset << "!\n";
    }
}

/*
This function essentially takes the save data from the vector and
loads it into the object
*/

int GameData::loadFromVector(std::vector<std::string> saveData) {
    m_userName = saveData[0];

    // Most of these have to be converted from string to integer with the stoi function
    if (saveData.size() < 8) {
        // Just in case the save file is too small
        return 1;
    }
    m_turns = std::stoi(saveData[1]);
    m_maxHealth = std::stoi(saveData[2]);
    m_currentHealth = std::stoi(saveData[3]);
    m_wit = std::stoi(saveData[4]);
    m_stoneface = std::stoi(saveData[5]);
    m_xp = std::stoi(saveData[6]);
    m_level = std::stoi(saveData[7]);
    m_cash = std::stoi(saveData[8]);

    // This is a bit more complex since it is a vector to be loaded

    if ((saveData.size() - 1) > 9) {
        // Skip line 9 for future compatibility
        m_items.resize(saveData.size() - 10);
        for (long unsigned int i{ 0 }; i < m_items.size(); i++) {
            m_items[i] = std::stoi(saveData[10 + i]);
        }
    }
    return 0;
}

std::vector<std::string> GameData::saveToVector() {
    std::vector<std::string> saveData;
    int si{ 10 };
    saveData.resize(10 + m_items.size());
    saveData[0] = m_userName;
    saveData[1] = std::to_string(m_turns);
    saveData[2] = std::to_string(m_maxHealth);
    saveData[3] = std::to_string(m_currentHealth);
    saveData[4] = std::to_string(m_wit);
    saveData[5] = std::to_string(m_stoneface);
    saveData[6] = std::to_string(m_xp);
    saveData[7] = std::to_string(m_level);
    saveData[8] = std::to_string(m_cash);
    saveData[9] = "Items";
    for (long unsigned int i{ 0 }; i < m_items.size(); i++) {
        saveData[si] = std::to_string(m_items[i]);
        si++;
    }
    return saveData;
}

void GameData::checkStatus() {
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
    std::cout << blue << "Name: " << normal << m_userName << '\n';
    std::cout << blue << "Health: " << normal << m_currentHealth <<
    " / " << m_maxHealth << '\n';
    std::cout << blue << "Wit: " << normal << m_wit << '\n';
    std::cout << blue << "Stoneface: " << normal << m_stoneface << '\n';
    std::cout << blue << "Cash: " << normal << m_cash << " DirtBux\n";
}

void GameData::checkInventory(Items items) {
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
    std::vector<std::string> weaponList{};
    std::vector<std::string> healList{};
    std::cout << blue << "Cash: " << normal << m_cash << '\n';
    for (long unsigned int i{0}; i < m_items.size(); i++) {
        Item currentItem = items.searchID(m_items[i]);
        switch (currentItem.getType()) {
        case 1:
            if ( !(std::find(weaponList.begin(), weaponList.end(), currentItem.getName()) != weaponList.end()) ) {
                weaponList.resize(weaponList.size() + 1, currentItem.getName());
            }
            break;
        case 2:
            healList.resize(healList.size() + 1, currentItem.getName());
            break;
        }
    }
    std::cout << green << "Weapons:\n" << normal;
    for (long unsigned int i{0}; i < weaponList.size(); i++) {
        std::cout << blue << weaponList[i] << '\n' << normal;
    }
}