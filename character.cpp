#include "character.h"


int Character::getX(){
    return x;
}

int Character::getY(){
    return y;
}

bool Character::checkIfOutsideMaze(Maze maze, int i, int j){
    if (maze.checkIfOne (i, j)){
        return true;
    }
    return false;
}

    bool Character::checkIfWin (Maze maze, int y){
        if (y == maze.getsize()){
            return true;
        }
    return false;
    }

