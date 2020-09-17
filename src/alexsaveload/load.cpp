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
#include "saveload.h"

std::vector<std::string> loadGame() {
    // This vector contains the items
    std::vector<std::string> loadList{};
    // String where current line of the file is stored
    std::string currentItem{ "" };
    // Select the same item from the save path
    std::ifstream saveFile{ getSavePath() };
    // Iterates through file and adds each line to the vector
    int i{ 0 };
    while (getline(saveFile, currentItem)) {
        loadList.resize(loadList.size() + 1);
        loadList[i] = currentItem;
        i++;
    }
    // Return the loaded information
    return loadList;
}