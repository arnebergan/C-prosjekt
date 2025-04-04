#pragma once
#include "std_lib_facilities.h"
#include "maze.h"


class Character{

    private:
    std::vector<int> character_posisjon;    // Posisjon 2, i og j.
    public:
    Character (Maze maze, std::vector<int> character_posisjon);
    bool checkIfOutsideMaze (Maze maze);
    void draw();
    void move();

};
