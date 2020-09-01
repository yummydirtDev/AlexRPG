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

GameData Enemies::fight(Enemy enemy, GameData data, Items items) {
    using Random = effolkronium::random_static;

    int enemyHealth = enemy.getHealth();
    char userChoice;

    std::cout << "Battle between " << blue << data.getUserName() << " " << red <<
    "(Level " << data.getLevel() << ") " << reset << "and " << blue <<
    enemy.getName() << reset << ".\n";

    while (enemyHealth > 0 && data.getCurrentHealth() > 0) {
        std::cout << "Would you like to " <<
        red << "(J) " << magenta << "Joke" << reset << ", " <<
        red << "(C) " << magenta << "Prepare for comeback" << reset << ", " <<
        red << "(I) " << magenta << "Inventory" << reset << ", " <<
        red << "(S) " << magenta << "Check Status " << reset;
        std::cin.ignore();
        std::cin >> userChoice;
	    switch (userChoice) {
	    case 'J':
	    case 'j':
            // TODO: Add joke telling ability
            enemyHealth -= (data.getWit() + items.toyMic.getDamage());
            std::cout << userLines[Random::get(0, int(userLines.size()))] << '\n';
            break;
        case 'C':
        case 'c':
            // Same TODO as before
        case 'I':
        case 'i':
            // TODO: Add item using ability
            data.checkInventory(items);
            break;
        case 'S':
        case 's':
            data.checkStatus();
            break;
	    }
	    // TODO: Do enemy turn and make them tell a joke
    }

    std::cout << enemy.enemyLines[Random::get(0, int(enemy.enemyLines.size()))];
    return data;
}
