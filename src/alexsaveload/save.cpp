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