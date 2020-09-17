#ifndef __GAME_H__
#define __GAME_H__

#include "../systems/savehandler.h"
#include "init.h"
#include "../systems/items.h"
#include "../systems/combat.h"

GameData gameLoop(GameData data);
static bool isEven(int number);

#endif // __GAME_H__