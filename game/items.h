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
    int getHealing();
    int getDamage();
    int getCost();
};

// This aggregates all the items into one object
class Items {
    public:
    Item toyMic{ "Toy Microphone", 0, 1, 0, 5, 0 };
};

#endif // __ITEMS_H__