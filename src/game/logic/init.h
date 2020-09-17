/*
    Copyright 2020 Alex Frutkin
    
    This file is part of AlexRPG.

    AlexRPG is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AlexRPG is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with AlexRPG.  If not, see <https://www.gnu.org/licenses/>.

*/
#ifndef __INIT_H__
#define __INIT_H__

#define MAX_NAME_LENGTH 50

#include <iostream>
#include <string>

#include <limits>
#include "../../alexsaveload/saveload.h"
#include "../systems/savehandler.h"
#include "../lib/color.h"

GameData initGame();

#endif // __INIT_H__