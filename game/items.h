#ifndef __ITEMS_H__
#define __ITEMS_H__

#include <string>

class Item {
private:
    int m_id;
    int m_type;
    std::string m_name;
    int m_healing;
    int m_damage;
    int m_cost;
public:
    Item(std::string name, int id, int type, int healing, int damage, int cost);
    int getID();
    std::string getName();
    int getHealing();
    int getDamage();
    int getCost();
};

class Items {
    public:
    Item toyMic{ "Toy Microphone", 0, 1, 0, 5, 0 };
};

#endif // __ITEMS_H__