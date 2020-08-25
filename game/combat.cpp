#include "combat.h"

Enemy::Enemy(std::string name, int health, int wit, int stoneface, std::vector<std::string> lines) {
    m_name = name;
    m_health = health;
    m_wit = wit;
    m_stoneface = stoneface;
    enemyLines = lines;
}

std::string Enemy::getName() {
    return m_name;
}