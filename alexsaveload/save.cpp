#include "saveload.h"

void saveGame(std::vector<std::string> dataList) {
    std::ofstream saveFile{std::string(getenv("HOME"))+"/.AlexRPG"};
    for (int i{0}; i < dataList.size(); i++) {
        saveFile << dataList[i] << '\n';
    }
    saveFile.close();
}

int main() {
    int thingy{12};
    float f{0.233};
    std::vector<std::string> list{std::to_string(thingy), std::to_string(f)};
    saveGame(list);
}