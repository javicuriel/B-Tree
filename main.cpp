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

int main(int argc, const char * argv[]) {
    int orden = 2;
     srand((int)time(NULL));
    
    ArbolB<int> * arbol = new ArbolB<int>(orden);
    
//    for(int i = 0; i < 100000; i++){
//        arbol->Insertar(rand()%1000);
//    }
    
    arbol->Insertar(5);
    arbol->Insertar(9);
    arbol->Insertar(3);
    arbol->Insertar(7);
    arbol->Insertar(1);
    arbol->Insertar(2);
    arbol->Insertar(8);
    arbol->Insertar(6);
    arbol->Insertar(0);
    arbol->Insertar(4);
//    arbol->Insertar(11);
//    arbol->Insertar(12);
//    arbol->Insertar(13);
//    arbol->Insertar(14);
//    arbol->Insertar(15);
//    arbol->Insertar(16);
//    arbol->Insertar(17);
//    arbol->Insertar(18);
    arbol->Buscar(8);
    arbol->print();


    
    
    return 0;

}
