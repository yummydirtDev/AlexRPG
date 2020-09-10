#include "saveload.h"

std::vector<std::string> loadGame() {
    std::vector<std::string> loadList{};
    std::string currentItem{ "" };
    std::ifstream saveFile{ getSavePath() };
    int i{ 0 };
    while (getline(saveFile, currentItem)) {
        loadList.resize(loadList.size() + 1);
        loadList[i] = currentItem;
        i++;
    }
    return loadList;
}