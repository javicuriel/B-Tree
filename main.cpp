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
//
//    
    arbol->Borrar(15);
    arbol->print();
    
    for(int i = 1; i< 19;i++){
        arbol->Buscar(i);
    }
//
//    cout <<  "==============================" << endl;

    // A B-Tree with minium degree 3
//    
//    t->Insertar(1);
//    t->Insertar(3);
//    t->Insertar(7);
//    t->Insertar(10);
//    t->Insertar(11);
//    t->Insertar(13);
//    t->Insertar(14);
//    t->Insertar(15);
//    t->Insertar(18);
//    t->Insertar(16);
//    t->Insertar(19);
//    t->Insertar(24);
//    t->Insertar(25);
//    t->Insertar(26);
//    t->Insertar(21);
//    t->Insertar(4);
//    t->Insertar(5);
//    t->Insertar(20);
//    t->Insertar(22);
//    t->Insertar(2);
//    t->Insertar(17);
//    t->Insertar(12);
//    t->Insertar(6);
//    
//    cout << "Traversal of tree constructed is\n";
//    t->print();
//    cout << endl;
//    
//    
//    cout <<  "==============================" << endl;
//    t->Borrar(6);
//    cout << "Traversal of tree after removing 6\n";
//    t->print();
//    
//    cout << endl;
//    cout <<  "==============================" << endl;
//    t->Borrar(13);
//    cout << "Traversal of tree after removing 13\n";
//    t->print();
//    
//    cout << endl;
//    cout <<  "==============================" << endl;
//    t->Borrar(7);
//    cout << "Traversal of tree after removing 7\n";
//    t->print();
//    
//    cout << endl;
//    cout <<  "==============================" << endl;
//    t->Borrar(4);
//    cout << "Traversal of tree after removing 4\n";
//    t->print();
//    
//    cout << endl;
//    cout <<  "==============================" << endl;
//    t->Borrar(2);
//    cout << "Traversal of tree after removing 2\n";
//    t->print();
//    
//    cout << endl;
//    cout <<  "==============================" << endl;
//    t->Borrar(16);
//    cout << "Traversal of tree after removing 16\n";
//    t->print();
//    cout << endl;
//    return 0;
    
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

    //delete arbol;
    
    
    return 0;

}
