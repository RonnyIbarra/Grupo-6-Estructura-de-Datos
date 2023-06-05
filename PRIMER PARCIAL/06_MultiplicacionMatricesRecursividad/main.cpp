/***********************************************************************
 * UFA-ESPE
 * Module:  Operaciones.cpp
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Created: Sunday, May 21, 2023 2:04:59 PM
 * Purpose: Implementation of the class Operaciones
 ***********************************************************************/
 
#include <iostream>
#include "Matriz.h"
#include "Operaciones.h"
#include "Validacion.h"
#include "Operaciones.cpp"

void iniciar(int);

void iniciar(int dim){
	Matriz<int> matriz1(dim), matriz2(dim), matrizR(dim);		
	
	Operaciones<int> operaciones1(matriz1);			
	operaciones1.encerar();
	operaciones1.generar();
	printf("\nLa matriz A es:");
	operaciones1.imprimir();
	
	Operaciones<int> operaciones2(matriz2);			
	operaciones2.encerar();         
	operaciones2.generar();
	printf("\nLa matriz B es:");
	operaciones2.imprimir();
		
	Operaciones<int> operaciones3(matrizR);			 
	operaciones3.encerar();
	operaciones3.multiplicacion(matriz1,matriz2);
	printf("\nLa multiplicacion de las dos matrices es:");
	operaciones3.imprimir();	                       						
}                                   
	
int main() {
	Validacion validacion;                         
	int dim;
	dim = validacion.ingresarDimension();
	
	iniciar(dim);
	
	return 0;
}