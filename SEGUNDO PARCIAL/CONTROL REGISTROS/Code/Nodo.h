/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Nodo.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <stdio.h>
#include "Empleado.h"

using namespace std;

template <typename T>
class Nodo
{
public:
	Nodo();
	T getValor();
	Nodo<T>*& getDerecha();
	Nodo<T>*& getIzquierda();
	Nodo<T>*& getNivel();
	void setValor(T);
	void setDerecha(Nodo<T>*);
	void setIzquierda(Nodo<T>*);

private:
	T valor;
	Nodo<T>* derecha;
	Nodo<T>* izquierda;
	Nodo<T>* nivel;
};

#endif