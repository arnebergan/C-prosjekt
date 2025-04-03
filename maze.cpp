#include "maze.h"
#include <iostream>
int Maze::rand(int lowerlimit, int upperlimit){
    std::random_device rd;
    std:: default_random_engine generator(rd());
    std:: uniform_int_distribution<int> distribution(lowerlimit, upperlimit);
    int n = distribution(generator);
    return n;


}


Maze::Maze(int size):size(size){
    maze = new int*[size];
    for(int i = 0; i <size; i++){
        maze[i] = new int[size];
        for(int j = 0; j < size; j++){
            maze[i][j] = 0;
        }
    }
    std::cout << "matrix made/n";
    // fyller først hele matrisen med 0
    int j = rand(0, size);
    maze[0][j] = 1; //Velger en start plass tilfeldig
    std::cout << "filled with 0/n";
   

    bool a = true;
    int i = 0;
    int n = 0;
    //i og j er nå med på å holde styr over hvor vi er i matrisen. skal være indexen vår
    while(a){
        std::cout << "Start generating path/n";
        n = rand(0, 5);
    
        if(n == 0 or n == 4 or n == 5){ //et steg fram
                maze[i+1][j]= 1;
                i += 1;
        }else if(n == 1){  // et steg til høyre
                maze[i][j + 1] = 1;
                j += 1;
           
        }else if(n == 2){ // et steg til venstre
            
                maze[i][j-1] = 1;
                j -= 1;
           
        }else if(n == 3){ // et steg tilbake
                maze[i-1][j] = 1;
                i -= 1;
        }

        for(int k; k<size; k++){//sjekker om vi har kommet i mål ved at en rute i siste rad er blitt 1
            if(maze[size][k] == 1){
                a = false;
            }
        } 
        std::cout<< maze[i][j] << std::endl;     
    }
    int m = 0;
    for(int i = 0; i < rand(20, 50); i++){
         m = rand(3, 20);   
    }



}

Maze::~Maze(){
    for(int i = 0; i < size; i++){
        delete[] maze[i];
    }
    delete[] maze;
    
}


int Maze::getsize() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const Maze& rhs){
    int size = rhs.getsize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            os << rhs.maze[i][j] << " ";  
            
        }
        os << std::endl;  
    }
    return os;  
}