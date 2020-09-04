#include "savehandler.h"

// Constructors

GameData::GameData(std::string userName, int turns, std::vector<int> items, int maxHealth, int currentHealth, int wit, int stoneface, int xp, int level) {
    m_userName = userName;
    m_turns = turns;
    m_items = items;
    m_maxHealth = maxHealth;
    m_currentHealth = currentHealth;
    m_wit = wit;
    m_stoneface = stoneface;
    m_xp = xp;
    m_level = level;
}

GameData::GameData() {
    std::vector<int> items{};

    m_userName = "Alex";
    m_turns = 0;
    m_items = items;
    m_maxHealth = 30;
    m_currentHealth = 30;
    m_wit = 5;
    m_stoneface = 5;
    m_xp = 0;
    m_level = 0;
    m_cash = 0;
}

// After this is a set of standard set/get functions

std::string GameData::getUserName() {
    return m_userName;
}

int GameData::getTurns() {
    return m_turns;
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

int GameData::getXp() {
    return m_xp;
}

int GameData::getLevel() {
    return m_level;
}

int GameData::getCash() {
    return m_cash;
}

void GameData::setUserName(std::string userName) {
    m_userName = userName;
}

void GameData::setTurns(int turns) {
    m_turns = turns;
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

void GameData::setXp(int xp) {
    m_xp = xp;
}

void GameData::setLevel(int level) {
    m_level = level;
}

void GameData::setCash(int cash) {
    m_cash = cash;
}

void GameData::addItem(Item item) {
    m_items.resize(m_items.size() + 1, item.getID());
    switch (item.getType()) {
    case 1:
        std::cout << "You have acquired " << green << item.getName() << reset << "!\n";
    }
}

void GameData::removeItem(Item item) {
    std::vector<int>::iterator it = std::find(m_items.begin(), m_items.end(), item.getID());
    m_items.erase(it);
}

Item GameData::getWeapon(Items items) {
    int topWeapon{ -1 };

    for (long unsigned int x{ 0 }; x < m_items.size(); x++) {
        Item currentItem{ items.searchID(m_items[x]) };
        if (currentItem.getType() == 1) {
            if (currentItem.getID() > topWeapon) {
                topWeapon = currentItem.getID();
            }
        }
    }
    return items.searchID(topWeapon);
}

/*
This function essentially takes the save data from the vector and
loads it into the object
*/

int GameData::loadFromVector(std::vector<std::string> saveData) {
    m_userName = saveData[0];

    // Most of these have to be converted from string to integer with the stoi function
    if (saveData.size() < 8) {
        // Just in case the save file is too small
        return 1;
    }
    m_turns = std::stoi(saveData[1]);
    m_maxHealth = std::stoi(saveData[2]);
    m_currentHealth = std::stoi(saveData[3]);
    m_wit = std::stoi(saveData[4]);
    m_stoneface = std::stoi(saveData[5]);
    m_xp = std::stoi(saveData[6]);
    m_level = std::stoi(saveData[7]);
    m_cash = std::stoi(saveData[8]);

    // This is a bit more complex since it is a vector to be loaded

    if ((saveData.size() - 1) > 9) {
        // Skip line 9 for future compatibility
        m_items.resize(saveData.size() - 10);
        for (long unsigned int i{ 0 }; i < m_items.size(); i++) {
            m_items[i] = std::stoi(saveData[10 + i]);
        }
    }
    return 0;
}

std::vector<std::string> GameData::saveToVector() {
    std::vector<std::string> saveData;
    int si{ 10 };
    saveData.resize(10 + m_items.size());
    saveData[0] = m_userName;
    saveData[1] = std::to_string(m_turns);
    saveData[2] = std::to_string(m_maxHealth);
    saveData[3] = std::to_string(m_currentHealth);
    saveData[4] = std::to_string(m_wit);
    saveData[5] = std::to_string(m_stoneface);
    saveData[6] = std::to_string(m_xp);
    saveData[7] = std::to_string(m_level);
    saveData[8] = std::to_string(m_cash);
    saveData[9] = "Items";
    for (long unsigned int i{ 0 }; i < m_items.size(); i++) {
        saveData[si] = std::to_string(m_items[i]);
        si++;
    }
    return saveData;
}

void GameData::checkStatus() {
    std::cout << blue << "Name: " << reset << m_userName << '\n';
    std::cout << blue << "Health: " << reset << m_currentHealth
    << " / " << m_maxHealth << '\n';
    std::cout << blue << "Wit: " << reset << m_wit << '\n';
    std::cout << blue << "Stoneface: " << reset << m_stoneface << '\n';
    std::cout << blue << "Cash: " << reset << m_cash << " DirtBux\n";
}

void GameData::checkInventory(Items items) {
    std::vector<std::string> weaponList{};
    std::vector<std::string> healList{};
    std::cout << blue << "Cash: " << reset << m_cash << '\n';
    for (long unsigned int i{ 0 }; i < m_items.size(); i++) {
        Item currentItem = items.searchID(m_items[i]);
        switch (currentItem.getType()) {
        case 1:
            if (!(std::find(weaponList.begin(), weaponList.end(), currentItem.getName()) != weaponList.end())) {
                weaponList.resize(weaponList.size() + 1, currentItem.getName());
            }
            break;
        case 2:
            healList.resize(healList.size() + 1, currentItem.getName());
            break;
        }
    }
    std::cout << green << "Weapons:\n" << reset;
    for (long unsigned int i{ 0 }; i < weaponList.size(); i++) {
        std::cout << blue << weaponList[i] << '\n' << reset;
    }
    std::cout << green << "Healing Items:\n" << reset;
    for (long unsigned int i{ 0 }; i < healList.size(); i++) {
        std::cout << blue << healList[i] << '\n' << reset;
    }
}

char GameData::checkInventory(Items items, bool usableInventory) {
    if (usableInventory) {
        std::vector<std::string> weaponList{};
        std::vector<std::string> healList{};
        std::vector<Item> usableItems{};
        // Input choice
        unsigned char userChoice;
        bool inputRecognized{ false };
        std::cout << blue << "Cash: " << reset << m_cash << '\n';
        for (long unsigned int i{ 0 }; i < m_items.size(); i++) {
            Item currentItem = items.searchID(m_items[i]);
            switch (currentItem.getType()) {
            case 1:
                if (!(std::find(weaponList.begin(), weaponList.end(), currentItem.getName()) != weaponList.end())) {
                    weaponList.resize(weaponList.size() + 1, currentItem.getName());
                }
                break;
            case 2:
                healList.resize(healList.size() + 1, currentItem.getName());
                usableItems.resize(usableItems.size() + 1, currentItem);
                break;
            }
        }
        std::cout << green << "Weapons:\n" << reset;
        for (long unsigned int i{ 0 }; i < weaponList.size(); i++) {
            std::cout << blue << weaponList[i] << '\n' << reset;
        }
        std::cout << green << "Healing Items:\n" << reset;
        for (long unsigned int i{ 0 }; i < healList.size(); i++) {
            std::cout << i << " " << blue << healList[i] << '\n' << reset;
        }
        while (!inputRecognized) {
            std::cout << "What item would you like to use? " << red << "(Enter Number or q to quit) " << reset;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> userChoice;
            if (userChoice < usableItems.size()) {
                Item currentItem{ usableItems[userChoice] };
                // Please work holy crap
                removeItem(currentItem);
                m_currentHealth += currentItem.getHealing();
                // Make sure the user doesn't go over max health
                if (m_currentHealth > m_maxHealth) {
                    m_currentHealth = m_maxHealth;
                }
                std::cout << "You used " << blue << currentItem.getName() << reset << '\n';
                std::cout << "Health is now: " << blue << m_currentHealth
                << "/" << m_maxHealth << reset << '\n';
                inputRecognized = true;
                return 1;
            } else if (userChoice == 'q' || userChoice == 'Q') {
                return 0;
            } else {
                std::cout << "Input not recognized, try again\n";
            }
        }
    } else {
        checkInventory(items);
        return 0;
    }
    return 0;
}