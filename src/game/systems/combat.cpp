#include "combat.h"

#ifdef __linux__
    char getch(void) {
        char buf = 0;
        struct termios old = {0};
        fflush(stdout);
        if(tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if(tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if(read(0, &buf, 1) < 0)
            perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if(tcsetattr(0, TCSADRAIN, &old) < 0)
            perror("tcsetattr ~ICANON");
        return buf;
    }
#endif
#ifdef _WIN32
// Code snippet taken from Microsoft to let cmd.exe use ANSI color
#define DEFINE_CONSOLEV2_PROPERTIES
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
    bool EnableVTMode() {
        // Set output mode to handle virtual terminal sequences
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE)
        {
            return false;
        }

        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode))
        {
            return false;
        }

        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        if (!SetConsoleMode(hOut, dwMode))
        {
            return false;
        }
        return true;
    }
#endif

Enemy::Enemy(std::string name, int health, int wit, int stoneface, int xpGiven,
            std::vector<std::string> lines, int weaponStrength) {
    m_name = name;
    m_health = health;
    m_wit = wit;
    m_stoneface = stoneface;
    m_xpGiven = xpGiven;
    enemyLines = lines;
    m_weaponStrength = weaponStrength;
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

int Enemy::getWeaponStrength() {
    return m_weaponStrength;
}

GameData Enemies::fight(Enemy enemy, GameData data, Items items) {
    using Random = effolkronium::random_static;

    int enemyHealth = enemy.getHealth();
    int damageDelivered;
    char userChoice;
    bool inputRecognized{ false };
    bool comebackSuccess{ false };

    std::cout << "Battle between " << blue << data.getUserName() << " " << red
    << "(Level " << data.getLevel() << ") " << reset << "and " << blue
    << enemy.getName() << reset << ".\n";

    while (enemyHealth > 0 && data.getCurrentHealth() > 0) {
        while (!inputRecognized) {
            std::cout << "Would you like to "
            << red << "(J) " << magenta << "Joke" << reset << ", "
            << red << "(C) " << magenta << "Prepare for comeback" << reset << ", "
            << red << "(I) " << magenta << "Inventory" << reset << ", "
            << red << "(S) " << magenta << "Check Status " << reset;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> userChoice;
            switch (userChoice) {
            case 'J':
            case 'j':
                // Joke telling ability
                damageDelivered = (std::round((static_cast<double>(data.getWit()) 
                    / static_cast<double>(enemy.getStoneface())) 
                    * data.getWeapon(items).getDamage()));
                enemyHealth -= damageDelivered;
                std::cout << "You hit them with a zinger: " << blue << '"'
                << userLines[Random::get(0, static_cast<int>(userLines.size() - 1))] 
                << '"' << '\n' << reset;
                std::cout << "It does " << red << damageDelivered << reset 
                << " damage. They have (" << red << enemyHealth << "/"
                << enemy.getHealth() << reset << ") health left.\n";
                std::cout << blue << '"' 
                << hurtLines[Random::get(0, static_cast<int>(hurtLines.size() - 1))]
                << "\"\n" << reset;
                std::cout << "Their " 
                << painLines[Random::get(0, static_cast<int>(painLines.size() - 1))] 
                << '\n';
                inputRecognized = true;
                break;
            case 'C':
            case 'c':
                /*
                This calculates a random value weighted by user stoneface
                and enemy wit. If successful it tells the AI to attack itself in its
                own turn.
                */
                if ((Random::get(0, 10)
                    * std::round((static_cast<double>(data.getStoneface())
                    / static_cast<double>(enemy.getWit()))) >= 5)) {
                    comebackSuccess = true;
                } else {
                    std::cout << "Comeback attempt unsuccessful\n";
                }
                inputRecognized = true;
                break;
            case 'I':
            case 'i':
                // TODO: Add item using ability
                if (data.checkInventory(items, true) == 1) {
                    inputRecognized = true;
                }
                break;
            case 'S':
            case 's':
                data.checkStatus();
                break;
            }
        }
        std::cout << "Press any key to continue...";
        #ifdef __linux__
        getch();
        #endif
        #ifdef _WIN32
        _getch();
        #endif
        std::cout << '\n';
        damageDelivered = std::round(((static_cast<double>(enemy.getWit()) 
            / static_cast<double>(data.getStoneface())) 
            * enemy.getWeaponStrength()));
        // TODO: Do enemy turn and make them tell a joke
        if (comebackSuccess == true) {
            // This is if the comeback worked
            comebackSuccess = false;
            enemyHealth -= damageDelivered;
            std::cout << green << "Comeback successful!\n" << reset;
        } else {
            // This is if there was no comeback
            data.setCurrentHealth(data.getCurrentHealth() - damageDelivered);
            std::cout << "They respond: " << blue << '"'
            << enemy.enemyLines[Random::get(0, int(enemy.enemyLines.size() - 1))]
            << '"' << '\n' << reset;
            std::cout << "It does " << red << damageDelivered << reset 
            << " damage. You have (" << red << data.getCurrentHealth() << "/"
            << data.getMaxHealth() << reset << ") health left.\n";
            std::cout << blue << '"' 
            << hurtLines[Random::get(0, static_cast<int>(hurtLines.size() - 1))]
            << "\"\n" << reset;
            std::cout << "Your " 
            << painLines[Random::get(0, static_cast<int>(painLines.size() - 1))] 
            << '\n';
        }
        inputRecognized = false;
    }
    return data;
}
