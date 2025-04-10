#include "game_functions.h"


void move(Character character, Map map, bool isMoving){
    
    if (map.is_key_down(KeyboardKey::LEFT)){
        if (!isMoving) {
            map.moveLeft();
            isMoving = true;
            character.left();
        }
    
    }
    if (map.is_key_down(KeyboardKey::RIGHT)){
        if (!isMoving){
            map.moveRight();
            isMoving = true;
            character.right();
        }
    } 
     if (map.is_key_down(KeyboardKey::UP)){
        if (!isMoving) {
            map.moveUp();
            isMoving = true;
            character.up();
        }
    
    }
    if (map.is_key_down(KeyboardKey::DOWN)){
        if (!isMoving) {
            map.moveDown();
            isMoving = true;
            character.down();
        }
    
    }
    if (!map.is_key_down(KeyboardKey::LEFT) && !map.is_key_down(KeyboardKey::RIGHT) && !map.is_key_down(KeyboardKey::UP) && !map.is_key_down(KeyboardKey::DOWN)){
        isMoving = false;
    }
}


