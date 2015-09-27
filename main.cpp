//
//  main.cpp
//  BinaryTree
//
//  Created by Vicente Cubells Nonell on 26/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

#include "ArbolB.h"

using namespace std;

int main() {
    
    int orden = 2;
    
    ArbolB<int> * arbol = new ArbolB<int>(orden);
    
    //cout << arbol->cantidadNodos();
    
    arbol->Insertar(1);
    cout << endl;
    
    //cout << arbol->cantidadNodos();
    
    arbol->Insertar(2);
    cout << endl;
    arbol->Insertar(3);
    cout << endl;
    arbol->Insertar(4);
    cout << endl;
    arbol->Insertar(5);
    cout << endl;
    arbol->Insertar(0);
    cout << endl;


    
//    
//    NodoArbolB<int> * nodo = new NodoArbolB<int>(orden);
//    nodo->insertarDato(10);
//    nodo->insertarDato(20);
//    nodo->insertarDato(30);
//    nodo->insertarDato(40);
//    nodo->setLlave(0);
//    nodo->save(orden,true);
//    arbol->cantidadNodos();
//    NodoArbolB<int> * nuevo = new NodoArbolB<int>(orden);
//    nuevo->carga(0,orden);
//    nuevo->print();
//    cout << nodo->getUsed();
    //nodo->save();
    
    //BNode<int> * m_two = new BNode<int>(2);
    return 0;
}