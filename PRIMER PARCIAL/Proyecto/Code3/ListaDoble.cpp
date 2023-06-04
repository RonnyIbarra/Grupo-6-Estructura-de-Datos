/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  ListaDoble.cpp
 * Author:  Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Implementation of the class ListaDoble
 *******************************************************************************/
 
#include <iostream>
#include "ListaDoble.h"

template <typename T>
ListaDoble<T>::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

template <typename T>
Nodo<T>* ListaDoble<T>::getCabeza() {
    return cabeza;
}

template <typename T>
Nodo<T>* ListaDoble<T>::getCola() {
    return cola;
}

template <typename T>
void ListaDoble<T>::insertarPorCabeza(T valor) {
	
	Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        nuevoNodo->setAnterior(cola);
        cola->setSiguiente(nuevoNodo);
        cola = nuevoNodo;
    }
}

template <typename T>
void ListaDoble<T>::insertarPorCola(T valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    
    if (cola == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        nuevoNodo->setAnterior(cola);
        cola->setSiguiente(nuevoNodo);
        cola = nuevoNodo;
    }
}


template <typename T>
void ListaDoble<T>::eliminar(T valor) {
    Nodo<T>* actual = cabeza;
    
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == valor.getCedula()) {
            if (actual == cabeza) {
                cabeza = actual->getSiguiente();
                if (cabeza != nullptr)
                    cabeza->setAnterior(nullptr);
            } else if (actual == cola) {
                cola = actual->getAnterior();
                if (cola != nullptr)
                    cola->setSiguiente(nullptr);
            } else {
                Nodo<T>* anterior = actual->getAnterior();
                Nodo<T>* siguiente = actual->getSiguiente();
                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior);
            }
            
            delete actual;
            return;
        }
        
        actual = actual->getSiguiente();
    }
}

//buscar por cedula
template <typename T>
bool ListaDoble<T>::buscar(long int cedula) {
    Nodo<T>* actual = cabeza;
    bool encontrado = false;
    
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == cedula) {
            encontrado = true;
            break;
        }
        
        actual = actual->getSiguiente();
    }
    
    if (encontrado) {
        return true;
    } else {
        return false;
    }
}

//mostar todo
template <typename T>
void ListaDoble<T>::mostrar() {
    Nodo<T>* actual = cabeza;
    
    std::cout << "Contenido de la lista:" << std::endl;
    
    while (actual != nullptr) {
        actual->getDato().toString();
        actual = actual->getSiguiente();
    }
}


