/***********************************************************************
 * UFA-ESPE
 * Module:  Operaciones.h
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Created: Sunday, May 21, 2023 2:04:59 PM
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matriz.h"

template <typename T> 
class Operaciones{
	public:
		Operaciones();
		Operaciones(Matriz<T>&);
		~Operaciones();	
		void encerar();
		void generar();
		void sumaRecursivaMatrices(T**, T**, T**, int, int);
		void sumaRecursiva(Matriz<T>&, Matriz<T>&);
		void imprimir();
		
	private:
		Matriz<T> _matriz;
};



#endif