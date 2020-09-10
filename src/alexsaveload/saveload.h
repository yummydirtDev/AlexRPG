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

// Saves a vector to the file
void saveGame(std::vector<std::string> dataList);
// Returns a vector from the file
std::vector<std::string> loadGame();
// Gets the path of the file
std::string getSavePath();

#endif // __SAVELOAD_H__