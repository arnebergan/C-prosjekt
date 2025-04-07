#pragma once
#include <vector>
#include <random>
#include "std_lib_facilities.h"

class Maze{
    private:
    int size;
    
    public:
    std::vector<std::vector<int>> maze;
    Maze(int size);


    int rand(int lowerlimits, int upperlimits);

    Maze(const Maze&) = delete;
    int getsize() const;
    int getPos_x(std::vector<std::vector<int>> maze) const;
    int getPos_y(std::vector<std::vector<int>> maze) const;
    int box_iteration(int Row, int Colum);
    std::vector<std::pair<int, int>> AddToPath(int Row, int Colum, int m);
 
    friend std::ostream& operator<<(std::ostream& os, const Maze& rhs);
};