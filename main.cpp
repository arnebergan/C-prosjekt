#include "maze.h"
#include "std_lib_facilities.h"
#include "map.h"
#include "game_functions.h"
#include "fil.h"
#include "character.h"

int main() {
    Fil fil;
    string username;
    cout << "Write your username: "; //User write username to terminal
    cin >> username; 
    Maze maze1 (43); // Create maze size 43x43
    TDT4102::Point point = {50, 50}; //Starting point of animationwindow
    Map map (point, 1024, 768, "HALLEE", 43, maze1); //Create the window
    bool isMoving = false;
    Character character (maze1); //create the blue dot
    Stopwatch stopwatch; // Timer
    stopwatch.start();

    while(!map.should_close()){

        map.drawMaze(); // Draws the maze
        map.drawPosition();
        move(character, map, maze1, character.getIndexCharacter(), isMoving); //moving the character
        if (character.checkIfWin(maze1, character.getIndexCharacter().second)){ //If you win
            double end_time = stopwatch.stop();
            cout << "Congratulations, you beat the maze!" << endl;
            cout << "You used " << end_time << " Seconds!" << endl;
            fil.addNerds(username, end_time);
            fil.saveToFile("results.txt");
            return 0;
        }
        
    map.next_frame();
    } 
    return 0;
}