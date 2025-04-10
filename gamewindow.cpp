#include "gamewindow.h"


Map::Map(TDT4102::Point position, int width, int height, const string& title, int size, Maze maze):
    AnimationWindow (position.x, position.y, width, height, title), 
    quitBtn({width-100, 10}, 80, 30, "QUIT!"),
    maze(maze),
    size(size),
    circle_pointer({168+8+(16)*maze.getStart_position(), 688+40-8})
   
{
    add(quitBtn);
    quitBtn.setCallback(std::bind(&Map::quitBtn_2, this));
}

void Map::quitBtn_2(){
    close();
}

void Map::drawMaze() {
    // Draw the square around the maze
TDT4102::Point point_up_left {167, 39};
TDT4102::Point point_up_right {168+688, 39};
TDT4102::Point point_down_left {167, 40+688};
TDT4102::Point point_down_right {168+688, 40+688};
draw_line(point_up_left, point_down_left);
draw_line(point_down_left, point_down_right);
draw_line(point_down_right, point_up_right);
draw_line(point_up_right, point_up_left);

int square_size = 16; 
TDT4102::Color fill_color_zero = TDT4102::Color::black;
TDT4102::Color fill_color_one = TDT4102::Color::white;

const int x_position_start = 168;
const int y_position_start = 40;
const int delta = 688/43; //16

int x_position = x_position_start; 
int y_position = y_position_start; 

for (int i = 0; i<maze.getsize(); i++){
    for (int j = 0; j<maze.getsize(); j++){
        TDT4102::Point pos {x_position, y_position};

        if (maze.checkIfOne(i, j)){
            draw_rectangle(pos, square_size, square_size, fill_color_one);
        }else{
            draw_rectangle(pos, square_size, square_size, fill_color_zero);
        }
        x_position += delta;
    
    }
    x_position = x_position_start; 
    y_position += delta;
}
}

void Map::drawPosition(){
    TDT4102::Color circle_color = TDT4102::Color::cornflower_blue;
    // start_position = maze.getStart_position();
    // cout << "startposition:  " << start_position << "    ";
    // TDT4102::Point circle_pointer {168+8+(16)*start_position, 688+40-8};
    draw_circle(circle_pointer, 8, circle_color);
    
}

void Map::moveLeft(){
    circle_pointer = {circle_pointer.x-16, circle_pointer.y};

}

void Map::moveRight(){
    circle_pointer = {circle_pointer.x+16, circle_pointer.y};
    
}

void Map::moveUp(){
    circle_pointer = {circle_pointer.x, circle_pointer.y-16};
    
}

void Map::moveDown(){
    circle_pointer = {circle_pointer.x, circle_pointer.y+16};

}