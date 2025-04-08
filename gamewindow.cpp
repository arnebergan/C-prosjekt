#include "gamewindow.h"


Map::Map(TDT4102::Point position, int width, int height, const string& title):
    AnimationWindow (position.x, position.y, width, height, title), 

    quitBtn({width-100, 10}, 80, 30, "QUIT!"),
     

{
    add(quitBtn);
    quitBtn.setCallback(std::bind(&Map::quitBtn_2, this));
}

void Map::quitBtn_2(){
    close();
}