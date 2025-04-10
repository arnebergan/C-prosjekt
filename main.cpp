#include "maze.h"
#include "std_lib_facilities.h"
#include "gamewindow.h"
#include "game_functions.h"

int main() {
    cout << "Hello, World! hei" << endl;
    Maze maze1 (43); // Create maze size 43x43
    cout << "halla gamers" << endl;
    cout << "FErdig med vente" << endl;
    TDT4102::Point point = {50, 50}; //Starting point of animationwindow
    Map map (point, 1024, 768, "HALLEE", 43, maze1);
    bool isMoving = false;
    Character character (maze1);
    while(!map.should_close()){
        
        map.drawMaze();
        map.drawPosition();
        // move(maze1, map, isMoving);
        if (character.checkIfWin(maze1, character.getIndexCharacter().second)){
            cout << "GRATULERER DU VANT!" << endl;
            return 0;
        }

        // // _sleep(500);
        
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
        cout << "x=" << character.getIndexCharacter().first << "  y=" << character.getIndexCharacter().second << endl;
        map.next_frame();
    } 
    // cout << maze1 << endl;

    return 0;
}