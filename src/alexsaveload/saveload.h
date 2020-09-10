#ifndef __SAVELOAD_H__
#define __SAVELOAD_H__

// Replace AlexRPG with your game's name as you want it on the disk
#define SAVENAME "AlexRPG"

// Used for input and output in the save/load function
#include <iostream>
// Used to save and load the data from the file
#include <fstream>
// Used to store the save data
#include <vector>
// Define directories
#include <stdlib.h>
#include <string>

void saveGame(std::vector<std::string> dataList);
std::vector<std::string> loadGame();
std::string getSavePath();

#endif // __SAVELOAD_H__