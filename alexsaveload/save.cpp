#include "saveload.h"

void saveGame(std::vector<std::string> dataList) {
    std::ofstream saveFile{std::string(getenv("HOME"))+"/.AlexRPG"};
    for (int i{0}; i < dataList.size(); i++) {
        saveFile << dataList[i] << '\n';
    }
    saveFile.close();
}