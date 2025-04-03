#pragma once
#include <vector>
#include <random>
class Maze{
    private:
    int size;
    std::vector<std::vector<int>> maze;


    public:
    Maze(int size);

    int rand(int lowerlimits, int upperlimits);
    ~Maze();
   
    Maze(const Maze&) = delete;
    int getsize() const;
 
    friend std::ostream& operator<<(std::ostream& os, const Maze& rhs);
};