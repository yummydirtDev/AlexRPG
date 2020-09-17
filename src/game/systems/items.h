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
#ifndef __ITEMS_H__
#define __ITEMS_H__

#include <string>

// This defines items
class Item {
private:
    // This is the ID of the item, used to identify and store it
    int m_id;
    // The type of the item, such as weapon or healer
    int m_type;
    // This is the name of the item, it is what is shown to the user
    std::string m_name;
    // The amount the item heals (0 means it doesn't heal)
    int m_healing;
    // The amount of damage the item deals (0 means it doesn't deal damage)
    int m_damage;
    // How much the item costs/sells for (0 means unsellable)
    int m_cost;
public:
    // Constructor for the item
    Item(std::string name, int id, int type, int healing, int damage, int cost);
    // A bunch of get functions
    int getID();
    std::string getName();
    int getType();
    int getHealing();
    int getDamage();
    int getCost();
};

// This aggregates all the items into one object
class Items {
    public:
    Item toyMic{ "Toy Microphone", 0, 1, 0, 5, 0 };
    Item bandaid{ "Bandaid", 1, 2, 15, 0, 5};
    Item searchID(int id);
};

#endif // __ITEMS_H__