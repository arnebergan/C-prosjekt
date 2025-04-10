#include "character.h"


Character::Character (Maze maze){
    
    this->index_character.first = maze.getStart_position();
    this->index_character.second = maze.getsize()-1;
}


std::pair<int, int> Character::getIndexCharacter (){
    return index_character;
}


bool Character::checkIfOutsideMaze(Maze maze, std::pair<int, int> index_character){
    if (maze.checkIfOne (index_character.first, index_character.second)){
        return true;
    }
    return false;
}

bool Character::checkIfWin (Maze maze, int index_character_y){
    if (index_character_y == 0 ){
        return true;
    }
return false;
}

void Character::left (){
    index_character.first -=1;
}

void Character::right (){
    index_character.first +=1;

}
void Character::up (){
    index_character.second -=1;
}
void Character::down (){
    index_character.second +=1;
}

