//
//  ArbolB.h
//  binaryTree
//
//  Created by Javier Curiel on 9/7/15.
//  Copyright (c) 2015 Javier Curiel. All rights reserved.
//

#ifndef __binaryTree__ArbolB__
#define __binaryTree__ArbolB__

#include "NodoArbolB.h"

#include <fstream>

template <class T>
class ArbolB {
private:
    
    int currentID;
    int orden;
    void setData();
    fstream data;
    T datoInserta;
    
public:
    
    ArbolB(int);
    ~ArbolB();
    void Insertar(T);
    void Borrar(T);
    
    void updateTotal(int);
    int getRoot();
    void setRoot(int);
    
//    void saveNodo(NodoArbolB<T>);
//    void cargaNodo(NodoArbolB<T> *,int);
    //T primerDato(int); //Regresa primer dato de nodo en la posicion int
    int cantidadNodos(); // Checa cantidad de nodos
};

template <class T>
ArbolB<T>::ArbolB(int orden){
    this->orden = orden;
    currentID = 0;
    setData();
    NodoArbolB<T> nodo(orden);
    nodo.llave = currentID;
    nodo.leaf = true;
    nodo.save(data);
    currentID++;
    updateTotal(1);
}



template <class T>
void ArbolB<T>::Insertar(T dato){

    datoInserta = dato;
    NodoArbolB<T> root(orden,getRoot(),data);
    cout << getRoot();
    if(root.checkFull()){
        cout << getRoot();
        NodoArbolB<T> nodoPadre(orden);
        nodoPadre.llave = currentID;
        setRoot(currentID);
        nodoPadre.leaf = false;
        nodoPadre.espaciosUsados = 0;
        nodoPadre.setChild(root.llave,1);
        root.setParent(nodoPadre.llave);
        currentID++;
        root.divideNodo(nodoPadre,1,data,currentID);
        nodoPadre.insertarDato(datoInserta,data,currentID);
    }
    else{
        root.insertarDato(datoInserta,data,currentID);
        cout << "Root:" << endl;
        root.print();
        
    }

}



template <class T>
void ArbolB<T>::setData(){
    int totalNodos = 0;
    int root = 0;
    data.open("/Users/javiercuriel/Documents/XCODE/Algoritmos/binaryTree/binaryTree/data.dat", ios::out|ios::in| ios::binary);
    data.seekp(0);
    data.write(reinterpret_cast<char*>(&totalNodos), sizeof(int));
    data.write(reinterpret_cast<char*>(&root), sizeof(int));
}

template <class T>
int ArbolB<T>::getRoot(){
    int root;
    data.seekg(sizeof(int));
    data.read(reinterpret_cast<char*>(&root), sizeof(int));
    return root;
}

template <class T>
void ArbolB<T>::setRoot(int rootID){
    data.seekp(sizeof(int));
    data.write(reinterpret_cast<char*>(&rootID), sizeof(int));
}

template <class T>
int ArbolB<T>::cantidadNodos(){
    int totalNodos;
    data.seekg(0);
    data.read(reinterpret_cast<char*>(&totalNodos), sizeof(int));
    return totalNodos;
}


template <class T>
void ArbolB<T>::updateTotal(int cantidad){
    int total;
    data.seekg(0);
    data.read(reinterpret_cast<char*>(&total), sizeof(int));
    total += cantidad;
    data.seekp(0);
    data.write(reinterpret_cast<char*>(&total), sizeof(int));
}


//template <class T>
//void ArbolB<T>::saveNodo(NodoArbolB<T>  nodo){
//    int tamArreglo = sizeof(T)*orden*2;
//    int tamHijos = sizeof(int)*orden*2+sizeof(int);
//    int tamNums = sizeof(int)*3;
//    int header = sizeof(int)*2;
//    int total = tamArreglo + tamNums + sizeof(bool);
//    data.seekp(header+nodo.llave*total);
//    data.write(reinterpret_cast<char*>(&nodo.llave), sizeof(int));
//    data.write(reinterpret_cast<char*>(&nodo.espaciosUsados), sizeof(int));
//    data.write(reinterpret_cast<char*>(&nodo.padre), sizeof(int));
//    data.write(reinterpret_cast<char*>(&nodo.leaf), sizeof(bool));
//    data.write(reinterpret_cast<char*>(&nodo.info), tamArreglo);
//    data.write(reinterpret_cast<char*>(&nodo.hijos), tamHijos);
//}
//
//template <class T>
//void ArbolB<T>::cargaNodo(NodoArbolB<T> * nodo,int llaveDeCarga){
//    int tamArreglo = sizeof(T)*orden*2;
//    int tamHijos = sizeof(int)*orden*2+sizeof(int);
//    int tamNums = sizeof(int)*3;
//    int header = sizeof(int)*2;
//    int total = tamArreglo + tamNums + sizeof(bool);
//    data.seekg(header+llaveDeCarga*total);
//    data.read(reinterpret_cast<char*>(&nodo->llave), sizeof(int));
//    data.read(reinterpret_cast<char*>(&nodo->espaciosUsados), sizeof(int));
//    data.read(reinterpret_cast<char*>(&nodo->padre), sizeof(int));
//    data.read(reinterpret_cast<char*>(&nodo->leaf), sizeof(bool));
//    data.read(reinterpret_cast<char*>(&nodo->info), tamArreglo);
//    data.read(reinterpret_cast<char*>(&nodo->hijos), tamHijos);
//}


template <class T>
ArbolB<T>::~ArbolB(){
    //No se
}

#endif /* defined(__binaryTree__ArbolB__) */
