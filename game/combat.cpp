#include "combat.h"

Enemy::Enemy(std::string name, int health, int wit, int stoneface, int xpGiven, std::vector<std::string> lines) {
    m_name = name;
    m_health = health;
    m_wit = wit;
    m_stoneface = stoneface;
    m_xpGiven = xpGiven;
    enemyLines = lines;
}

std::string Enemy::getName() {
    return m_name;
}

int Enemy::getHealth() {
    return m_health;
}

int Enemy::getWit() {
    return m_wit;
}

int Enemy::getStoneface() {
    return m_stoneface;
}

int Enemy::getXpGiven() {
    return m_xpGiven;
}

GameData Enemies::fight(Enemy enemy, GameData data) {
    using Random = effolkronium::random_static;

    int enemyHealth = enemy.getHealth();

    while (enemyHealth > 0 && data.getCurrentHealth() > 0) {

    }

    std::cout << enemy.enemyLines[Random::get(0, int(enemy.enemyLines.size()))];
    return data;
}