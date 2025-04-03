#include "maze.h"
#include <iostream>
int Maze::rand(int lowerlimit, int upperlimit){
    std::random_device rd;
    std:: default_random_engine generator(rd());
    std:: uniform_int_distribution<int> distribution(lowerlimit, upperlimit);
    int n = distribution(generator);
    return n;


}


Maze::Maze(int size):size(size), maze(size, std::vector<int>(size, 0)){// fyller først hele matrisen med 0
    
    std::cout << "matrix made/n";
    
    int j = rand(0, size);
    maze.at(0).at(j) = 1; //Velger en start plass tilfeldig
    std::cout << "filled with 0/n";
   

    bool a = true;
    int i = 0;
    int n = 0;
    //i og j er nå med på å holde styr over hvor vi er i matrisen. skal være indexen vår
    while(a){
        std::cout << "Start generating path" << endl;
        n = rand(0, 5);
        try{
        if(n == 0 or n == 4 or n == 5){ //et steg fram
                maze.at(i+1).at(j)= 1;
                i += 1;
        }else if(n == 1){  // et steg til høyre
                maze.at(i).at(j +1) = 1;
                j += 1;
           
        }else if(n == 2){ // et steg til venstre
            
                maze.at(i).at(j-1) = 1;
                j -= 1;
           
        }else if(n == 3){ // et steg tilbake
                maze.at(i-1).at(j) = 1;
                i -= 1;
        } }
        catch(...){
          continue;  
        }
        cout << "Generating path"<< endl;

        for(int k; k<size; k++){//sjekker om vi har kommet i mål ved at en rute i siste rad er blitt 1
            if(maze.at(size).at(k) == 1){
                a = false;
            }
        } 
        
    }
    // int m = 0;
    // for(int i = 0; i < rand(20, 50); i++){
    //      m = rand(3, 20);   
    // }



}



int Maze::getsize() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const Maze& rhs){
    int size = rhs.getsize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            os << rhs.maze.at(i).at(j) << " ";  
            
        }
        os << std::endl;  
    }
    return os;  
}