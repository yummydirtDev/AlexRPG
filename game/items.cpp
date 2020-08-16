#include "items.h"

Item::Item(int id, int type, std::string name, int healing, int damage, int cost) {
    m_id = id;
    m_type = type;
    m_name = name;
    m_healing = healing;
    m_damage = damage;
    m_cost = cost;
}