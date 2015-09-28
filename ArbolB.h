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
    
    void insertarDato(NodoArbolB<T>,T);
    void save(NodoArbolB<T>&);
    NodoArbolB<T> carga(int);
    void divideNodo(NodoArbolB<T> &,int,NodoArbolB<T> &);
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
    save(nodo);
    currentID++;
    updateTotal(1);
}



template <class T>
void ArbolB<T>::Insertar(T dato){
    NodoArbolB<T> root= carga(getRoot());
    if(root.checkFull(orden)){
        NodoArbolB<T> nodoPadre(orden);
        nodoPadre.llave = currentID;
        setRoot(currentID);
        nodoPadre.leaf = false;
        nodoPadre.espaciosUsados = 0;
        nodoPadre.setChild(root.llave,1);
        root.padre = nodoPadre.llave;
        currentID++;
        divideNodo(nodoPadre, 1, root);
        insertarDato(nodoPadre, dato);
    }
    else{
        insertarDato(root, dato);
        cout << "Root:" << endl;
        root.print();
        
    }

}

template <class T>
void ArbolB<T>::insertarDato(NodoArbolB<T> nodo,T dato){
    int i = nodo.espaciosUsados-1;
    
    if(nodo.leaf){
        while (i >= 0 && dato < nodo.info[i]){
            nodo.info[i+1] = nodo.info[i];
            i--;
        }
        nodo.info[i+1] = dato;
        nodo.espaciosUsados++;
        save(nodo);
        
    }
    else{
        while (i >= 0 && dato < nodo.info[i]){
            i--;
        }
        i ++;
        NodoArbolB<T> nodoHijo = carga(nodo.hijos[i]);
        if(nodoHijo.checkFull(orden)){
            divideNodo(nodo, i, nodoHijo);
            if(dato > nodo.info[i])
                i++;
        }
        insertarDato(nodoHijo,dato);
        
    }
}

template <class T>
void ArbolB<T>::divideNodo(NodoArbolB<T> & nodoPadre,int i,NodoArbolB<T> & nodo){
    NodoArbolB<T> nodoHermano(orden);
    nodoHermano.llave = currentID;
    nodoHermano.padre = nodoPadre.llave;
    currentID++;
    nodoHermano.leaf = nodo.leaf;
    int div = orden-1;
    nodoHermano.espaciosUsados = div;
    
    for(int j = 0; j < div; j++){
        nodoHermano.info[j] = nodo.info[j+orden];
    }
    if (!nodo.leaf){
        for(int j = 0; j < div+1; j++){
            nodoHermano.hijos[j] = nodo.hijos[j+orden];
        }
    }
    nodo.espaciosUsados = div;
    
    for (int j = nodoPadre.espaciosUsados+1; j > i+1;j--){
        nodoPadre.hijos[j+1] = nodoPadre.hijos[j];
    }
    
    nodoPadre.hijos[i] = nodoHermano.llave;
    
    for (int j = nodoPadre.espaciosUsados; j > i; j--){
        nodoPadre.info[j+1] = nodoPadre.info[j];
    }
    
    nodoPadre.info[i-1] = nodo.info[orden-1];
    nodoPadre.espaciosUsados++;
    
    
    cout << "Nodo";
    
    
    save(nodo);
    save(nodoPadre);
    save(nodoHermano);
    
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


template <class T>
void ArbolB<T>::save(NodoArbolB<T> & nodo){
    int tamArreglo = sizeof(T)*orden*2-sizeof(T);
    int tamHijos = sizeof(int)*orden*2;
    int tamNums = sizeof(int)*3;
    int header = sizeof(int)*2;
    int total = tamArreglo + tamNums + sizeof(bool) + tamHijos;
    data.seekp(header+nodo.llave*total);
    data.write(reinterpret_cast<char*>(&nodo.llave), sizeof(int));
    data.write(reinterpret_cast<char*>(&nodo.espaciosUsados), sizeof(int));
    data.write(reinterpret_cast<char*>(&nodo.padre), sizeof(int));
    data.write(reinterpret_cast<char*>(&nodo.leaf), sizeof(bool));
    data.write(reinterpret_cast<char*>(&nodo.info), tamArreglo);
    data.write(reinterpret_cast<char*>(&nodo.hijos), tamHijos);
}

template <class T>
NodoArbolB<T>  ArbolB<T>::carga(int llaveDeCarga){
    NodoArbolB<T> nodo(orden);
    int tamArreglo = sizeof(T)*orden*2-sizeof(T);
    int tamHijos = sizeof(int)*orden*2;
    int tamNums = sizeof(int)*3;
    int header = sizeof(int)*2;
    int total = tamArreglo + tamNums + sizeof(bool) + tamHijos;
    data.seekg(header+llaveDeCarga*total);
    data.read(reinterpret_cast<char*>(&nodo.llave), sizeof(int));
    data.read(reinterpret_cast<char*>(&nodo.espaciosUsados), sizeof(int));
    data.read(reinterpret_cast<char*>(&nodo.padre), sizeof(int));
    data.read(reinterpret_cast<char*>(&nodo.leaf), sizeof(bool));
    data.read(reinterpret_cast<char*>(&nodo.info), tamArreglo);
    data.read(reinterpret_cast<char*>(&nodo.hijos), tamHijos);
    return nodo;
}




template <class T>
ArbolB<T>::~ArbolB(){
    //No se
}

#endif /* defined(__binaryTree__ArbolB__) */
