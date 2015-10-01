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
    
    
    for(int i = 1; i< 19;i++){
        arbol->Insertar(i);
    }
    
    
    arbol->Borrar(15);
    
    cout <<  "==============================" << endl;
    
    arbol->print();
    
//    arbol->Insertar(0);
//    arbol->Insertar(4);
//    arbol->Insertar(11);
//    arbol->Insertar(12);
//    arbol->Insertar(13);
//    arbol->Insertar(14);
//    arbol->Insertar(15);
//    arbol->Insertar(16);
//    arbol->Insertar(17);
//    arbol->Insertar(18);
//    arbol->Buscar(5);
//    arbol->Buscar(9);
//    arbol->Buscar(3);
//    arbol->Buscar(7);
//    arbol->Buscar(1);
//    arbol->Buscar(2);
//    arbol->Buscar(8);
//    arbol->Buscar(6);
//    arbol->Buscar(0);
//    arbol->Buscar(4);
    //arbol->print();

    delete arbol;
    
    
    return 0;

}
