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

    int getsize() const;
    int box_iteration(int Row, int Colum);
    void AddToPath(int Row, int Colum);
    bool checkIfOneOrZero(int x_pos, int y_pos) const;
 
    friend std::ostream& operator<<(std::ostream& os, const Maze& rhs);
};