#pragma once
#include <vector>
#include <random>
#include "std_lib_facilities.h"
// #include "map.h"
// #include "character.h"

class Maze{
    private:
    int size;
    int start_position;
    
    public:
    std::vector<std::vector<int>> maze;
    Maze(int size);


    int rand(int lowerlimits, int upperlimits);
    int getStart_position ();
    int getsize() const;
    int box_iteration(int Row, int Colum);
    void AddToPath(int Row, int Colum);
    bool checkIfOne(int x_pos, int y_pos) const;
 
    friend std::ostream& operator<<(std::ostream& os, const Maze& rhs); // overwrite to print out maze
};