#pragma once
#include "std_lib_facilities.h"
#include "maze.h"
#include "map.h"


class Character{

    private:
    std::pair<int, int> index_character; 

    public:
    Character (Maze maze);
    std::pair<int, int> getIndexCharacter ();
    bool checkIfOutsideMaze (Maze maze, std::pair<int, int> index_character);
    bool checkIfWin (Maze maze, int index_character_y);
    void left ();
    void right ();
    void up ();
    void down();
};
