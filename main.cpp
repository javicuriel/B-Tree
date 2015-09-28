//
//  main.cpp
//  Arbol-B
//
//  Created by Javier Curiel on 9/28/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//

#include <iostream>
#include "ArbolB.h"

int main(int argc, const char * argv[]) {
    int orden = 2;
    
    ArbolB<int> * arbol = new ArbolB<int>(orden);
    
    
    arbol->Insertar(5);
    cout << endl;
    arbol->print();
    cout << "==============" << endl;
    arbol->Insertar(9);
    cout << endl;
    
    arbol->print();
    cout << "==============" << endl;
    arbol->Insertar(3);
    cout << endl;
    arbol->print();
    cout << "==============" << endl;
    arbol->Insertar(7);
    cout << endl;
    arbol->print();
    cout << "==============" << endl;
    arbol->Insertar(1);
    cout << endl << endl;
    
    arbol->print();
    cout << "==============" << endl;
    
    arbol->Insertar(2);
    cout << endl;
    
    arbol->print();
    cout << "==============" << endl;
    arbol->Insertar(8);
    cout << endl;
    arbol->print();
    cout << "==============" << endl;
    
    arbol->Insertar(6);
    cout << endl;
    
    arbol->print();
    cout << "==============" << endl;
    
    arbol->Insertar(0);
    cout << endl;
    
    arbol->print();
    cout << "==============" << endl;
    return 0;

}
