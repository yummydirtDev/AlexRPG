#ifndef __SAVELOAD_H__
#define __SAVELOAD_H__

#include <vector>
#include <string>

void saveGame(std::vector<std::string> dataList);
std::vector<std::string> loadGame();

#endif // __SAVELOAD_H__