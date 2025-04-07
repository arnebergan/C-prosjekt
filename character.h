#pragma once
#include "std_lib_facilities.h"
#include "maze.h"


class Character{

    private:
    std::vector<int> character_posisjon; 
    int pos_x;
    int pos_y;   // Posisjon 2, i og j.
    public:
    Character (Maze maze, std::vector<int> character_posisjon);
    int getPos_x() const;
    int getPos_y() const;
    bool checkIfOutsideMaze (Maze maze,  const int& pos_x, const int& pos_y);
    void draw();
    void move();

};
