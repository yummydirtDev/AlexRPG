/*
    Copyright 2020 Alex Frutkin

    This file is part of alexsaveload.

    alexsaveload is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    alexsaveload is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with alexsaveload.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef __SAVELOAD_H__
#define __SAVELOAD_H__

// Replace AlexRPG with your game's name as you want it on the disk
#define SAVENAME "AlexRPG"

// Used for input and output in the save/load function
#include <iostream>
// Used to save and load the data from the file
#include <fstream>
// Used to store the save data
#include <vector>
// Define directories
#include <stdlib.h>
#include <string>

// Saves a vector to the file
void saveGame(std::vector<std::string> dataList);
// Returns a vector from the file
std::vector<std::string> loadGame();
// Gets the path of the file
std::string getSavePath();

#endif // __SAVELOAD_H__