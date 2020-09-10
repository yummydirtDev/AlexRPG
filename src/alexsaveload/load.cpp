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