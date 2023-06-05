/***********************************************************************
 * Module:  Main.cpp
 * Author:  Alexander Guaman, Ronny Ibarra, Kevin Amaguaña
 * Modified: miércoles, 13 de mayo de 2023 19:12:18
 * Purpose: Declaration of the class Main
 ***********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "Operaciones.cpp"
#include "Operaciones.h"
#include "Template.cpp"
#include "Imprimir.h"

using namespace std;

int main() {
	Validacion valido;
	Operaciones op;
    
	cout<<"Ingrese el numerador: ";
	float a = valido.ingresarDatosfloat();
	cout<<"Ingrese el denominador: ";
	float b = valido.ingresarDatosfloat();
	
	Fraccion<float> floatF1(a,b);
	op.imprimir(floatF1);
	
	cout<<"Ingrese el numerador: ";
	float c = valido.ingresarDatosfloat();
	cout<<"Ingrese el denominador: ";
	float d = valido.ingresarDatosfloat();
	
	Fraccion<float> floatF2(c,d);
	op.imprimir(floatF2);
	
	Fraccion<float> floatF3=op.calculo(floatF1,floatF2);
	cout<<"La respuesta de la suma de fracciones es: ";
	op.imprimir(floatF3);	
	
    system("pause");
}