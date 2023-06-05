/***********************************************************************
 * UFA-ESPE
 *Module:  Sobrecarga.cpp
 * Author:  Kevin Amaguña, Alexander Guaman, Ronny Ibarra
 * Modified: Wednesday, May 17, 2023 7:43:08 AM
 * Purpose: Implementation of the class Sobrecarga
 ***********************************************************************/



#include <iostream>
#include "Sobrecarga.cpp"
#include "imprimir.h"

using namespace std;


int main(){
	
	int num1;
	int num2;

   Sobrecarga sobrecarga;
   Validacion valido;
	
	cout<<"Ingrese el primer nuemero: ";
	num1 = valido.ingresarDatosfloat();
	
	cout<<"Ingrese el primer nuemero: ";
	num2 = valido.ingresarDatosfloat(); 
	
	sobrecarga.imprimir(num1, num2);
	
	
}