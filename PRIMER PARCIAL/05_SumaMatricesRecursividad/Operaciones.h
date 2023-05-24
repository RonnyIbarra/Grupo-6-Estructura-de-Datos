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
		void sumaRecursivaMatrices(T**, T**, T**, int, int);
		void sumaRecursiva(Matriz<T>&, Matriz<T>&);
		void imprimir();
		
	private:
		Matriz<T> _matriz;
};

template <typename T>
Operaciones<T>::Operaciones(){
}

template <typename T>
Operaciones<T>::~Operaciones(){
}

template <typename T> 
Operaciones<T>::Operaciones(Matriz<T>& m){
	this->_matriz=m;
}

template <typename T>
void Operaciones<T>::encerar() {
	int dim = _matriz.getDim();
	int **matriz = _matriz.getMatriz();
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){				
			*(*(matriz+i)+j)=0;
		}
	}
}

template <typename T>
void Operaciones<T>::imprimir(){
	printf("\n");
	int dim = _matriz.getDim();
	int **matriz = _matriz.getMatriz();
	for(int i=0;i<dim;i++){
		for(int j=0;j< dim;j++){
			printf("%d\t",*(*(matriz+i)+j));			
		}
		printf("\n");
	}
}

template <typename T>
void Operaciones<T>::sumaRecursivaMatrices(T** mat1, T** mat2, T** matR, int f, int c) {
    if ((f >= 0) && (c >= 0)) {
        *(*(matR + f) + c) = *(*(mat1 + f) + c) + *(*(mat2 + f) + c);
        sumaRecursivaMatrices(mat1, mat2, matR, f - 1, c);
        sumaRecursivaMatrices(mat1, mat2, matR, f, c - 1);
    }
}

template <typename T>
void Operaciones<T>::sumaRecursiva(Matriz<T>& objMatriz1, Matriz<T>& objMatriz2) {
    int dim = _matriz.getDim();
    T** mat1 = objMatriz1.getMatriz();
    T** mat2 = objMatriz2.getMatriz();
    T** matR = _matriz.getMatriz();

    if (dim > 0) {
        int f = dim - 1;
        int c = dim - 1;
        if ((f >= 0) && (c >= 0)) {
            *(*(matR + f) + c) = *(*(mat1 + f) + c) + *(*(mat2 + f) + c);
            sumaRecursivaMatrices(mat1, mat2, matR, f - 1, c);
            sumaRecursivaMatrices(mat1, mat2, matR, f, c - 1);
        }
    }
}

template <typename T>
void Operaciones<T>::generar(){
	srand(time(NULL));
	for(int i=0;i<_matriz.getDim();i++){
		for(int j=0;j<_matriz.getDim();j++){
			*(*(_matriz.getMatriz()+i)+j)=rand()%3;
		}
	}	
}
#endif