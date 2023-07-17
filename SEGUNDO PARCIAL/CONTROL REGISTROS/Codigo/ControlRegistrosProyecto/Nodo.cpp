/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Nodo.cpp
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

template <typename T>
T Nodo<T>::getDato(void){return dato;}

template <typename T>
void Nodo<T>::setDato(T newDato){dato = newDato;}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente(void){return siguiente;}

template <typename T>
void Nodo<T>::setSiguiente(Nodo* newSiguiente){siguiente = newSiguiente;}

template <typename T>
Nodo<T>* Nodo<T>::getAnterior(void){return anterior;}

template <typename T>
void Nodo<T>::setAnterior(Nodo* newAnterior){anterior = newAnterior;}

template <typename T>
Nodo<T>::Nodo(T dato){
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}
