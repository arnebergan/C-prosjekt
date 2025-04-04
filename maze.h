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
 
    friend std::ostream& operator<<(std::ostream& os, const Maze& rhs);
};