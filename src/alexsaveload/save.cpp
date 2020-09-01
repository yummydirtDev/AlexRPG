#include "saveload.h"

// Set directory based on operating system
#ifdef __linux__
    std::string getSavePath() {
        return std::string(getenv("HOME"))+"/.AlexRPG";
    }
#endif
#ifdef _WIN32
    std::string getSavePath() {
        return std::string(getenv("APPDATA")) + "\\.AlexRPG";
    }
#endif

void saveGame(std::vector<std::string> dataList) {
    getSavePath();
    std::ofstream saveFile{ getSavePath() };
    for (long unsigned int i{ 0 }; i < dataList.size(); i++) {
        saveFile << dataList[i] << '\n';
    }
    saveFile.close();
}