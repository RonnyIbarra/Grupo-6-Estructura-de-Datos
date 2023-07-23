/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Arbol.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Arbol
 ***********************************************************************/

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

template <typename T>
class Arbol
{
private:
    Nodo<T> *arbol = NULL;
public:
    void setArbol(Nodo<T> *);
    Nodo<T>*getArbol();
    Nodo<T>*crearNodo(T);
    void insertarNodo(Nodo<T>*&, T);
    void mostrar(Nodo<T>*, int);
    bool buscar(Nodo<T>*,string&);
    T buscarNodo(Nodo<T>*, string&);
    Nodo<T>* eliminarNodo(Nodo<T>*, string);
    void preOrden(Nodo<T>*);
    void inOrden(Nodo<T>*);
    void postOrden(Nodo<T>*);
};

#endif