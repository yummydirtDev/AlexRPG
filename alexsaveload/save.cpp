#include "saveload.h"

void saveGame(std::vector<boost::variant<float, int>> dataList) {
    for (int i{0}; i < dataList.size(); i++) {
        std::cout << dataList[i] << '\n';
    }
}

int main() {
    int thingy{12};
    float f{0.233};
    std::vector<boost::variant<float, int>> list{thingy, f};
    saveGame(list);
}