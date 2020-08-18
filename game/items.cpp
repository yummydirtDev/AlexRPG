#include "items.h"

Item::Item(std::string name, int id, int type, int healing, int damage, int cost) {
    m_id = id;
    m_type = type;
    m_name = name;
    m_healing = healing;
    m_damage = damage;
    m_cost = cost;
}

int Item::getID() {
    return m_id;
}

std::string Item::getName() {
    return m_name;
}

int Item::getHealing() {
    return m_healing;
}

int Item::getCost() {
    return m_cost;
}