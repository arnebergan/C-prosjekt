#pragma once
#include "character.h"
#include "maze.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "gamewindow.h"


void move(Character &character, Map &map, Maze maze, std::pair<int, int> index_character, bool &isMoving);

