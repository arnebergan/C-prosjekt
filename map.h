#pragma once
#include "AnimationWindow.h"
#include "maze.h"
#include "widgets/Button.h" 
#include "character.h"
#include "fil.h"
#include "game_functions.h"



class Map : public TDT4102::AnimationWindow{

    private:
    Maze maze;
    int size;
    TDT4102::Point circle_pointer;

    public:
    
    
    // static constexpr int x_start_window = 50;
    // static constexpr int y_start_window = 50;
    // static constexpr int width = 1024;
    // static constexpr int height = 768;
    // static constexpr string title = "Mashalla";
    
    Map(TDT4102::Point position, int width, int height, const string& title, int size, Maze maze); // Constructer

    void drawMaze ();
    TDT4102::Button quitBtn;

    void drawPosition();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void quitBtn_2 ();

};


