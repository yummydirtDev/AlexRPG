#include "saveload.h"

std::vector<std::string> loadGame() {
    std::vector<std::string> loadList{};
    std::string currentItem{ "" };
    std::ifstream saveFile{ std::string(getenv("HOME"))+"/.AlexRPG" };
    int i{ 0 };
    while (getline(saveFile, currentItem)) {
        loadList.resize(loadList.size() + 1);
        loadList[i] = currentItem;
        i++;
    }
    return loadList;
}