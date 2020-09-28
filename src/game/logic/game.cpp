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
#include "game.h"

// The game logic along with the main loop

// I had to do this inline but honestly, this probably wasn't neccessary
static inline void tutorial(GameData *data);

static char turnChoice();

static inline GameData endChoice(GameData data, Items items);

GameData gameLoop(GameData data) {
    // Define the items and enemies
    Items items;
    Enemies enemies;
    // Char used when user needs to decide yes or no
    char yOrN;
    bool elseVar{ false };
    // bool used to avoid recursion (for whatever reason)
    bool inputRecognized{ false };
    // Main turn checker
    switch (data.getTurns()) {
    // If it is turn 0 give the user a tutorial
    case 0:
        std::cout << "You appear to be new to AlexRPG, would you like to hear a tutorial? "
        << red << "(Y or N) " << reset;
        while (!inputRecognized) {
            std::cin >> yOrN;
            switch (yOrN) {
            case 'y':
            case 'Y':
                inputRecognized = true;
                tutorial(&data);
                break;
            case 'n':
            case 'N':
                inputRecognized = true;
                break;
            default:
                std::cout << "Input not recognized, try again\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
        std::cout << '\n';
        std::cout << "Alright then! Let's begin. You find yourself in a ditch near downtown Phoenix, "
        << "the city skyline in the horizon.\n";
        std::cout << "You spot a crappy microphone near you on the ground, "
        << "you pick it up just in case it might help.\n";
        // The starting mic for the game
        data.addItem(items.toyMic);
        data = endChoice(data, items);
        break;
    case 1:
        data = enemies.fight(enemies.sam, data, items);
        break;
    default:
        elseVar = true;
    }
    if (elseVar) {
        if (isEven(data.getTurns())) {
            data = endChoice(data, items);
        } else if (!isEven(data.getTurns())) {
            if (data.getLevel() <= 2) {
                data = enemies.fight(enemies.sam, data, items);
            } else if (data.getLevel() <= 4) {
                data = enemies.fight(enemies.jon, data, items);
            }
        }
    }
    return data;
}

static char turnChoice() {
    char input{ ' ' };
    bool inputRecognized{ false };
    while (!inputRecognized) {
        std::cout << "Would you like to " << red << "(N)" << magenta 
        << " Next Turn" << reset << ", " << red << "(I)" << magenta
        << " Inventory" << reset << "," << red << " (S)" << magenta
        << " Status" << reset << ", or " << red << "(Q)" << magenta
        << " Quit " << reset;
        std::cin >> input;
        switch (input) {
        case 'N':
        case 'n':
            inputRecognized = true;
            return 'N';
            break;
        case 'I':
        case 'i':
            // Check inventory
            inputRecognized = true;
            return 'I';
            break;
        case 'S':
        case 's':
            // Check status
            inputRecognized = true;
            return 'S';
            break;
        case 'Q':
        case 'q':
            // Quit
            inputRecognized = true;
            break;
        default:
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            std::cout << "Input not recognized! Please try again.\n";
            break;
        }
    }
    return 'y';
}

static inline GameData endChoice(GameData data, Items items) {
    bool inputRecognized{false};
    char decision;
    while (!inputRecognized) {
        decision = turnChoice();
        switch (decision) {
        case 'N':
            inputRecognized = true;
            data.setTurns(data.getTurns() + 1);
            saveGame(data.saveToVector());
            break;
        case 'I':
            // todo: check inventory
            data.checkInventory(items);
            break;
        case 'S':
            data.checkStatus();
            break;
        case 'y':
            inputRecognized = true;
            std::cout << "Come back soon!\n";
            saveGame(data.saveToVector());
            data.gameStatus = 1;
            break;
        }
    }
    return data;
}

static inline void tutorial(GameData *data) {
    std::cout << "Alright! AlexRPG is an RPG where you play as Alex, on a journey to "
    << "destroy Googular, a biting allegory for corporate America.\n";
    std::cout << "Rather than fight with weapons, you tell jokes. "
    << "The measure of joke-telling ability is called wit. To start out you have "
    << data->getWit() << " wit.\n";
    std::cout << "While there is no real violence from the attacking side, these jokes cause real damage. "
    << "The defending side will have real and gruesome injuries from these jokes.\n";
    std::cout << "The defending side can attempt a comeback to reverse the damage, "
    << "but if it fails they lose the turn and take the damage.\n";
}

bool isEven(int number) {
    if ( number % 2 == 0) {
        return true;
    }
    return false;
}