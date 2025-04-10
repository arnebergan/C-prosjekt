#include "maze.h"
#include "std_lib_facilities.h"
#include "gamewindow.h"

#include "maze.h"

int main() {
    cout << "Hello, World! hei" << endl;
    Maze maze1 (43); // Create maze size 43x43
    cout << "halla gamers" << endl;
    cout << "FErdig med vente" << endl;
    TDT4102::Point point = {50, 50}; //Starting point of animationwindow
    Map map (point, 1024, 768, "HALLEE", 43, maze1);
    bool isMoving = false;
    while(!map.should_close()){
        
        map.drawMaze();
        map.drawPosition();
        // _sleep(500);
        
        if (map.is_key_down(KeyboardKey::LEFT)){
            if (!isMoving) {
                map.moveLeft();
                isMoving = true;
            }
        
            // while(map.is_key_down(KeyboardKey::LEFT)) {continue;}
        }
        if (map.is_key_down(KeyboardKey::RIGHT)){
            if (!isMoving){
                map.moveRight();
                isMoving = true;
            }
        } 
         if (map.is_key_down(KeyboardKey::UP)){
            if (!isMoving) {
                map.moveUp();
                isMoving = true;
            }
        
        }
        if (map.is_key_down(KeyboardKey::DOWN)){
            if (!isMoving) {
                map.moveDown();
                isMoving = true;
            }
        
        }
        if (!map.is_key_down(KeyboardKey::LEFT) && !map.is_key_down(KeyboardKey::RIGHT) && !map.is_key_down(KeyboardKey::UP) && !map.is_key_down(KeyboardKey::DOWN)){
            isMoving = false;
        }
        map.next_frame();
    } 
    // cout << maze1 << endl;
    
    
    //     if (map.is_key_down(KeyboardKey::R)){
    //     cout << "RR \t";    
    //     }

    
    return 0;
}