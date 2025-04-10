#include "maze.h"
#include "std_lib_facilities.h"
#include "gamewindow.h"
#include "game_functions.h"
#include "fil.h"

int main() {
    cout << "Hello, World! hei" << endl;
    cout << "halla gamers" << endl;
    cout << "FErdig med vente" << endl;
    Maze maze1 (43); // Create maze size 43x43
    TDT4102::Point point = {50, 50}; //Starting point of animationwindow
    Map map (point, 1024, 768, "HALLEE", 43, maze1);
    bool isMoving = false;
    Character character (maze1);
    Stopwatch stopwatch;
    Fil fil;
    string username;
    cout << "Write your username: ";
    cin >> username;
    fil.addNerds(username, 0.0);
    stopwatch.start();



    while(!map.should_close()){
        
        map.drawMaze();
        map.drawPosition();
        // cout << "caracterindex: " << character.getIndexCharacter().first, character.getIndexCharacter().second;
        // cout << "   Chec if one: " << maze1.checkIfOne(character.getIndexCharacter().first, character.getIndexCharacter().second);
        
        move(character, map, maze1, character.getIndexCharacter(), isMoving);
        if (character.checkIfWin(maze1, character.getIndexCharacter().second)){
            cout << "GRATULERER DU VANT!" << endl;
            double end_time = stopwatch.stop();
            cout << "Du brukte " << end_time << " sekunder, taper!" << endl;
            fil.addNerds(username, end_time);
            fil.saveToFile("results.txt");
            return 0;
        }
        
        cout << "x=" << character.getIndexCharacter().first << "  y=" << character.getIndexCharacter().second << endl;
        map.next_frame();
    } 
    // cout << maze1 << endl;

    return 0;
}