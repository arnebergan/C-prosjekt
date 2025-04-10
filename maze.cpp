#include "maze.h"
#include <iostream>
int Maze::rand(int lowerlimit, int upperlimit){
    std::random_device rd;
    std:: default_random_engine generator(rd());
    std:: uniform_int_distribution<int> distribution(lowerlimit, upperlimit);
    int n = distribution(generator);
    return n;
}

int Maze::getStart_position (){
    return start_position;
}


Maze::Maze(int size):size(size), maze(size, std::vector<int>(size, 0)), start_position(rand(0, size)) {// fyller først hele matrisen med 0  
    
    // int start_position = rand(0, size);
    maze.at(0).at(start_position) = 1; //Velger en start plass tilfeldig
    
    bool a = true;
    int i = 0;
    int n = 0;
    std::vector<std::pair<int, int>> index_integers; 

    // i og start_position er nå med på å holde styr over hvor vi er i matrisen. skal være indexen vår
    cout << "starting to make maze: " << endl;
    while(a){
        
        n = rand(0, 8);
        try{
        if(n == 0 || n == 4 || n == 5 || n == 8){ //et steg fram
                maze.at(i+1).at(start_position)= 1;
                i += 1;
                index_integers.push_back(std::pair<int, int>(i, start_position));
        }else if(n == 1|| n == 6){  // et steg til høyre
                maze.at(i).at(start_position+1) = 1;
                start_position += 1;
                index_integers.push_back(std::pair<int, int>(i, start_position));
           
        }else if(n == 2 ||  n == 7){ // et steg til venstre
            
                maze.at(i).at(start_position-1) = 1;
                start_position -= 1;
                index_integers.push_back(std::pair<int, int>(i, start_position));
           
        }else if(n == 3 ){ // et steg tilbake
                maze.at(i-1).at(start_position) = 1;
                i -= 1;
                index_integers.push_back(std::pair<int, int>(i, start_position));
        } 
        }
        
        catch(...){ // Hvis den er ute av indeksene skal den bare fortsette og prøve på nytt
            cout << "Gikk utenfor mappet\t";
          continue;  
        }
       
        
        for(int k=0; k<size; k++){//sjekker om vi har kommet i mål ved at en rute i siste rad er blitt 1
            if(maze.at(size-1).at(k) == 1){
                a = false;
            }
        } 
    }
  
        for(int i = 0; i < size; ++i){ //Forslag til tilfeldig generering 
            for(int j = 0; j < size; ++j){
                if(maze.at(i).at(j) == 1){
                    continue;
                }
                int n = rand(1, 5);
                if(n == 1 || n == 2){
                    maze.at(i).at(j) = 1;
                }
            }
        }  

        // for(int a = 0; a < index_integers.size(); a += rand(1,3)){
        //     std::vector<std::pair<int , int>> index_branch;
        //     int Row = index_integers.at(a).first;
        //     int Colum = index_integers.at(a).second;
        //     if(box_iteration(Row, Colum) <= 1){
        //         AddToPath(Row, Colum);

        //     }
        // }
        cout << " Fornuftig??:: " << start_position << endl; 
            
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

int Maze::box_iteration(int Row, int Colum){
    this-> maze;
    int n = 0;
    for(int k = Row - 1; k <= Row + 1; ++k){
        for(int l = Colum - 1; l <= Colum + 1; ++l){
            if( k >= 0 && k < Row && l >= 0 && l < Colum){
                if( k == Row && l == Colum) continue;
                if( maze.at(k).at(l) == 1){
                    n += 1;
                }
            }
        }
    }
    return n;
}

void Maze::AddToPath(int Row, int Colum) {
    bool a = true;
    while (a) {
        int n = rand(1, 8); // tilfeldig tall fra 1 til 7

        try {
            if (n == 1) {
                maze.at(Row + 1).at(Colum) = 1;
                Row += 1;
            } else if (n == 2 || n == 6 || n == 7 ) {
                maze.at(Row).at(Colum + 1) = 1;
                Colum += 1;
            } else if (n == 3 || n == 7) {
                maze.at(Row - 1).at(Colum) = 1;
                Row -= 1;
            } else if (n == 4 ) {
                maze.at(Row).at(Colum - 1) = 1;
                Colum -= 1;
            }

        }
        catch (...) {
            // Hvis vi går utenfor grensene, bare hopp til neste iterasjon
            continue;
        }
        if(box_iteration(Row, Colum) >= 2 or Row == 1 or Colum == 1 or Row == (size - 1) or Colum ==(size - 1)){
            a = false;
        }
    }
}

bool Maze::checkIfOne(int x_pos, int y_pos) const{
    if (maze.at(x_pos).at(y_pos) == 1){
        return true;
    }
    return false;
}
