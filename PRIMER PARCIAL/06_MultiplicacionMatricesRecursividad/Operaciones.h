/***********************************************************************
 * UFA-ESPE
 * Module:  Operaciones.h
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Created: Sunday, May 21, 2023 2:04:59 PM
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#if !defined OPERACIONES_H
#define OPERACIONES_H

#include "Operaciones.h"
#include "Matriz.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

template <typename T> 
class Operaciones{
	public:
		Operaciones();
		Operaciones(Matriz<T>&);
		~Operaciones();	
		void encerar();
		void generar();
		void multiplicacionMatrices(T** , T** , T** , int , int , int );
		void multiplicacion(Matriz<T>& , Matriz<T>& );
		void imprimir();
		
	private:
		Matriz<T> _matriz;
};

#endif

