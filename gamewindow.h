#pragma once
#include "AnimationWindow.h"
#include "maze.h"
#include "character.h" // just in case
#include "widgets/Button.h" 

class Map : public TDT4102::AnimationWindow{

    public:
    
    // static constexpr int x_start_window = 50;
    // static constexpr int y_start_window = 50;
    // static constexpr int width = 1024;
    // static constexpr int height = 768;
    // static constexpr string title = "Mashalla";
    
    Map(TDT4102::Point position, int width, int height, const string& title); // Constructer

    TDT4102::Button quitBtn;

    void quitBtn_2 ();

};


