/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  NodoDoble.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class NodoDoble
 ***********************************************************************/

#include "NodoDoble.h"

template <typename T>
T NodoDoble<T>::getDato(void){return dato;}

template <typename T>
void NodoDoble<T>::setDato(T newDato){dato = newDato;}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getSiguiente(void){return siguiente;}

template <typename T>
void NodoDoble<T>::setSiguiente(NodoDoble* newSiguiente){siguiente = newSiguiente;}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getAnterior(void){return anterior;}

template <typename T>
void NodoDoble<T>::setAnterior(NodoDoble* newAnterior){anterior = newAnterior;}

template <typename T>
NodoDoble<T>::NodoDoble(T dato){
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}
