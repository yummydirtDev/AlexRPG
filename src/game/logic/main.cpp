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
#include "main.h"

int main() {
    // Intro and initialize
    #ifdef _WIN32
    EnableVTMode();
    #endif
    GameData data{ initGame() };
    while (data.gameStatus == 0) {
        if (data.gameStatus == 1) {
            std::cout << "dope";
        }
        data = gameLoop(data);
    }
    // Game loop
        // check state
        // do move
        // save game
    return 0;
}