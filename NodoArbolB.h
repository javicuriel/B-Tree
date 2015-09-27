//
//  NodoArbolB.h
//  binaryTree
//
//  Created by Javier Curiel on 9/7/15.
//  Copyright (c) 2015 Javier Curiel. All rights reserved.
//

#ifndef __binaryTree__NodoArbolB__
#define __binaryTree__NodoArbolB__

#include <fstream>



using namespace std;
template <class T>
struct NodoArbolB {
    
    int orden;
    int llave = NULL;
    int espaciosUsados;
    T *info;
    int padre = NULL;
    int *hijos;
    bool leaf = false;
    

    
   

    
    NodoArbolB(int);
    NodoArbolB(int,int,fstream &);
    virtual ~NodoArbolB();
    
    void insertarDato(T,fstream &,int &);
    void divideNodo(NodoArbolB<T>&,int,fstream &,int &);
    int checkInsert(T);
    bool checkFull();
    
    
    void save(fstream &);
    void carga(int,fstream &);

    void print();
    
    int getParent() const { return padre; }
    void setParent(int padreID) {
        padre = padreID;
    }
    
    void setChild(int childID, int x) {
        hijos[x] = childID;
    }
    
};

template <class T>
void NodoArbolB<T>::print(){
    for(int i = 0; i < espaciosUsados;i++){
        cout << info[i] << " ";
    }
}


template <class T>
bool NodoArbolB<T>::checkFull(){
    return espaciosUsados==orden*2;
}


template <class T>
NodoArbolB<T>::NodoArbolB(int orden){
    this->orden = orden;
    espaciosUsados = 0;
    info = new T[2*orden];
    hijos = new int[2*orden+1];
   
}

template <class T>
NodoArbolB<T>::NodoArbolB(int orden,int nodoID,fstream & data){
    this->orden = orden;
    espaciosUsados = 0;
    info = new T[2*orden];
    hijos = new int[2*orden+1];
    carga(nodoID, data);
}

template <class T>
void NodoArbolB<T>::insertarDato(T dato,fstream & data,int & currentID){
    int i = espaciosUsados-1;
    
    if(leaf){
        while (i >= 0 && dato < info[i]){
            info[i+1] = info[i];
            i--;
        }
        info[i+1] = dato;
        espaciosUsados++;
        save(data);
        
    }
    else{
        while (i >= 0 && dato < info[i]){
            i--;
        }
        i ++;
        NodoArbolB<T> nodoHijo(orden,hijos[i],data);
        if(nodoHijo.checkFull()){
            nodoHijo.divideNodo(*this,i,data,currentID);
            if(dato > info[i])
                i++;
        }
        nodoHijo.insertarDato(dato, data,currentID);
        
        
    }
}


template <class T>
int NodoArbolB<T>::checkInsert(T dato){
    for (int i = 0; i<= espaciosUsados; i++) {
        if (i == espaciosUsados)
            return i + 1;
        else{
            if (dato > info[i] && dato < info[i+1]){
                return i+1;
            }
            else if (dato < info[i]){
                return i;
            }
        }
    }
//    int i = 0;
//    while (i <= espaciosUsados){
//        if (i == espaciosUsados){
//            return i + 1;
//        }
//        else{
//            if (dato > info[i] && dato < info[i+1]){
//                return i+1;
//            }
//            else if (dato < info[i]){
//                return i;
//            }
//            else{
//                i++;
//            }
//        }
//
//    }
    return 0;
}



template <class T>
void NodoArbolB<T>::divideNodo(NodoArbolB<T> & nodoPadre,int i,fstream & data,int & currentID){
    NodoArbolB nodoHermano(orden);
    nodoHermano.llave = currentID;
    nodoHermano.padre = nodoPadre.llave;
    currentID++;
    nodoHermano.leaf = leaf;
    int div = espaciosUsados/2;
    nodoHermano.espaciosUsados = div;
    
    for(int j = div; j < espaciosUsados; j++){
        nodoHermano.info[j-div] = info[j];
    }
    if (!leaf){
        for(int j = div; j < espaciosUsados+1; j++){
            nodoHermano.hijos[j-div] = hijos[j];
        }
    }
    espaciosUsados = div;
    
    for (int j = nodoPadre.espaciosUsados+1; j >= i+1;j--){
        nodoPadre.hijos[j+1] = nodoPadre.hijos[j];
    }
    
    nodoPadre.hijos[i] = nodoHermano.llave;
    
    for (int j = nodoPadre.espaciosUsados; j >= i; j--){
        nodoPadre.info[j+1] = nodoPadre.info[j];
    }
    
    nodoPadre.info[i-1] = info[orden-1];
    nodoPadre.espaciosUsados++;
    espaciosUsados--;
    
    save(data);
    nodoPadre.save(data);
    nodoHermano.save(data);


}



template <class T>
void NodoArbolB<T>::save(fstream & data){
    int tamArreglo = sizeof(T)*orden*2;
    int tamHijos = sizeof(int)*orden*2+sizeof(int);
    int tamNums = sizeof(int)*3;
    int header = sizeof(int)*2;
    int total = tamArreglo + tamNums + sizeof(bool);
    data.seekp(header+llave*total);
    data.write(reinterpret_cast<char*>(&llave), sizeof(int));
    data.write(reinterpret_cast<char*>(&espaciosUsados), sizeof(int));
    data.write(reinterpret_cast<char*>(&padre), sizeof(int));
    data.write(reinterpret_cast<char*>(&leaf), sizeof(bool));
    data.write(reinterpret_cast<char*>(&info), tamArreglo);
    data.write(reinterpret_cast<char*>(&hijos), tamHijos);
 
}

template <class T>
void  NodoArbolB<T>::carga(int llaveDeCarga,fstream & data){
    int tamArreglo = sizeof(T)*orden*2;
    int tamHijos = sizeof(int)*orden*2+sizeof(int);
    int tamNums = sizeof(int)*3;
    int header = sizeof(int)*2;
    int total = tamArreglo + tamNums + sizeof(bool);
    data.seekg(header+llaveDeCarga*total);
    data.read(reinterpret_cast<char*>(&llave), sizeof(int));
    data.read(reinterpret_cast<char*>(&espaciosUsados), sizeof(int));
    data.read(reinterpret_cast<char*>(&padre), sizeof(int));
    data.read(reinterpret_cast<char*>(&leaf), sizeof(bool));
    data.read(reinterpret_cast<char*>(&info), tamArreglo);
    data.read(reinterpret_cast<char*>(&hijos), tamHijos);
}







template <class T>
NodoArbolB<T>::~NodoArbolB(){
}


#endif /* defined(__binaryTree__NodoArbolB__) */
