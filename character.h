#pragma once
#include "std_lib_facilities.h"
#include "maze.h"


class Character{

    private:
    int x;
    int y;    // Posisjon 2, i og j.
    public:
    Character (Maze maze, int x, int y);
    int getX ();
    int getY();
    bool checkIfOutsideMaze (Maze maze, int x, int y);
    bool checkIfWin (Maze maze, int y);
    void draw();
    
    
};
