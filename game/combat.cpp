#include "combat.h"

Enemy::Enemy(int name, int health, int wit, int stoneface, std::vector<std::string> lines) {
    m_name = name;
    m_health = health;
    m_wit = wit;
    m_stoneface = stoneface;
    enemyLines = lines;
}