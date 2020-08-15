#include "saveload.h"

#ifdef __linux__
    std::string getSavePath() {
        return std::string(getenv("HOME"))+"/.AlexRPG";
    }
#endif
#ifdef _WIN32
    std::string getSavePath() {
        std::string path{getenv("APPDATA")};
        std::cout << path;
        path = path + "\\AlexRPG\\.AlexRPG";
        std::cout << path;
        return path;
    }
#endif

void saveGame(std::vector<std::string> dataList) {
    getSavePath();
    std::ofstream saveFile{ getSavePath() };
    for (int i{ 0 }; i < dataList.size(); i++) {
        saveFile << dataList[i] << '\n';
    }
    saveFile.close();
}