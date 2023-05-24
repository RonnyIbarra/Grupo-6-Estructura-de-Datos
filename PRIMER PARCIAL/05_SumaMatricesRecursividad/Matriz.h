/***********************************************************************
 * UFA-ESPE
 * Module:  Matriz.h
 * Author: Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
  * Created: Sunday, May 21, 2023 2:04:59 PM
 * Purpose: Declaration of the class Matriz
 ***********************************************************************/

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

template <typename T>
class Matriz{
	private:
		T **matriz;
		int dim;
		
	public:
		Matriz();
		~Matriz();
		Matriz(int);
		int getDim();
		void setDim(int);
		T **getMatriz();
		void setMatriz(T **);
};

template <typename T>
Matriz<T>::Matriz() {
	
}

template <typename T>
Matriz<T>::Matriz(int dim){
	this->dim=dim;
	matriz = (T**)malloc(dim * sizeof(T*));
	for(int j = 0; j < dim; j++){
		*(matriz+j) = (T*)malloc(dim * sizeof(T));
	}
}

template <typename T>
Matriz<T>::~Matriz() {
    for (int i = 0; i < dim; i++) {
        free(*(matriz + i));
    }
    free(matriz);
}

template <typename T>
int Matriz<T>::getDim(){
	return dim;
}

template <typename T>
void Matriz<T>::setDim(int dim){
	this->dim=dim;
}

template <typename T>
T** Matriz<T>::getMatriz(){
	return matriz;
}

template <typename T>
void Matriz<T>::setMatriz(T **matriz1){
	this-> matriz=matriz;
}


#endif