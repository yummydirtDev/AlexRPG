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
#include "items.h"

// These are all the member functions for the Item class

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

int Item::getDamage() {
    return m_damage;
}

int Item::getCost() {
    return m_cost;
}

int Item::getType() {
    return m_type;
}

Item Items::searchID(int id) {
    switch (id) {
    case 0:
        return toyMic;
        break;
    case 1:
        return bandaid;
        break;
    }
    return toyMic;
}