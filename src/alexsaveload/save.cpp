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

// Set directory based on operating system
#ifdef __linux__
    // On linux save the game to the home path
    std::string getSavePath() {
        return std::string(getenv("HOME"))+ "/." + SAVENAME;
    }
#endif
#ifdef _WIN32
    // On windows save the game to the appdata path
    std::string getSavePath() {
        return std::string(getenv("APPDATA")) + "\\." + SAVENAME;
    }
#endif

void saveGame(std::vector<std::string> dataList) {
    std::ofstream saveFile{ getSavePath() };
    // Iterate through the vector and put each item on its own line
    for (long unsigned int i{ 0 }; i < dataList.size(); i++) {
        saveFile << dataList[i] << '\n';
    }
    // Close the file when finished
    saveFile.close();
}