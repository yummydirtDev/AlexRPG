#include "saveload.h"

std::vector<std::string> loadGame() {
    std::vector<std::string> loadList{};
    std::string currentItem{""};
    std::ofstream saveFile{std::string(getenv("HOME"))+"/.AlexRPG"};
}