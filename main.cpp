#include "maze.h"
#include "std_lib_facilities.h"
#include "gamewindow.h"

#include "maze.h"

int main() {
    cout << "Hello, World! hei" << endl;
    
    Maze maze1 (43);
    cout << "halla gamers" << endl;
    TDT4102::Point point = {50, 50};
    Map map (point, 1024, 768, "HALLEE", 43);
    cout << maze1 << endl;
    map.wait_for_close();

    return 0;
}