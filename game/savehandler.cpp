#include "savehandler.h"

// Constructors

GameData::GameData(int turns, std::vector<int> items, int maxHealth, int currentHealth, int wit, int stoneface) {
    m_turns = turns;
    m_items = items;
    m_maxHealth = maxHealth;
    m_currentHealth = currentHealth;
    m_wit = wit;
    m_stoneface = stoneface;
}

GameData::GameData() {

}

// After this is a set of standard set/get functions

std::string GameData::getUserName() {
    return m_userName;
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

int GameData::getWit() {
    return m_wit;
}

int GameData::getStoneface() {
    return m_stoneface;
}

void GameData::setUserName(std::string userName) {
    m_userName = userName;
}

void GameData::setTurns(int turns) {
    m_turns = turns;
}

void GameData::setItems(std::vector<int> items) {
    m_items = items;
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

/* 
This function essentially takes the save data from the vector and
loads it into the object
*/

int GameData::loadFromVector(std::vector<std::string> saveData) {
    m_userName = saveData[0];
    // Most of these have to be converted from string to integer with the stoi function
    m_turns = std::stoi(saveData[1]);
    m_maxHealth = std::stoi(saveData[2]);
    m_currentHealth = std::stoi(saveData[3]);
    m_wit = std::stoi(saveData[4]);
    m_stoneface = std::stoi(saveData[5]);
    // This is a bit more complex since it is a vector to be loaded
    if ((saveData.size() - 1) > 6) {
        // Skip line 6 for future compatibility
        m_items.resize(saveData.size() - 6);
        for (int i{0}; i < m_items.size(); i++) {
            m_items[i] = std::stoi(saveData[7 + i]);
        }
    }
    return 0;
}