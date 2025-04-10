#include "game_functions.h"
#include "Stopwatch.h"



void move(Character &character, Map &map, Maze maze, std::pair<int, int> index_character, bool &isMoving){
    
    if (map.is_key_down(KeyboardKey::LEFT)){
        if (!isMoving && maze.checkIfOne(index_character.second ,index_character.first-1)) { //and maze.checkIfOne((index_character.first-1), index_character.second)) {
        
            map.moveLeft();
            isMoving = true;
            character.left();
    }
    
    }
    if (map.is_key_down(KeyboardKey::RIGHT)){
        if (!isMoving && maze.checkIfOne(index_character.second ,index_character.first+1)){
            map.moveRight();
            isMoving = true;
            character.right();
        }
    } 
     if (map.is_key_down(KeyboardKey::UP)){
        if (!isMoving && maze.checkIfOne(index_character.second-1 ,index_character.first)) {
            map.moveUp();
            isMoving = true;
            character.up();
        }
    
    }
    if (map.is_key_down(KeyboardKey::DOWN)){
        if (!isMoving && maze.checkIfOne(index_character.second+1, index_character.first)) {
            map.moveDown();
            isMoving = true;
            character.down();
        }
    
    }
    if (!map.is_key_down(KeyboardKey::LEFT) && !map.is_key_down(KeyboardKey::RIGHT) && !map.is_key_down(KeyboardKey::UP) && !map.is_key_down(KeyboardKey::DOWN)){
        isMoving = false;
    }

}


void Stopwatch::start() {
    startTime = std::chrono::steady_clock::now();
}

double Stopwatch::stop() {
    std::chrono::time_point endTime = std::chrono::steady_clock::now();
    long durationInMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    double durationInSeconds = double(durationInMicroseconds)/1000000.0;
    return durationInSeconds;
}