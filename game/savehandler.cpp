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

int GameData::getWit() {
    return m_wit;
}

int GameData::getStoneface() {
    return m_stoneface;
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

int GameData::loadFromVector(std::vector<std::string> saveData) {
    
}