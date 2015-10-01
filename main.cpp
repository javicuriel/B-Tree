//
//  main.cpp
//  Arbol-B
//
//  Created by Javier Curiel on 9/28/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//

#include <iostream>
#include "ArbolB.h"
#include <ctime>
#include <chrono>

int main(int argc, const char * argv[]) {
    
    int orden = 3;
     srand((int)time(NULL));
    
    ArbolB<int> * arbol = new ArbolB<int>(orden);
    
    for(int i = 0; i< 100000;i++){
        arbol->Insertar(rand()%10000);
    }
    
    auto begin = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto tiempo = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);
    
    for (int i = 0; i < 10;i++){
        begin = std::chrono::high_resolution_clock::now();
        arbol->Buscar(rand() % 1000);
        end = std::chrono::high_resolution_clock::now();
        tiempo = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);
        std::cout << "Busqueda " << i+1 << ": "<< tiempo.count() << " ms"<< std::endl << endl;
    }
    
//    Imprime:
//    arbol->printAsc();
//    arbol->printDesc();
    
    
    
    
    return 0;

}
