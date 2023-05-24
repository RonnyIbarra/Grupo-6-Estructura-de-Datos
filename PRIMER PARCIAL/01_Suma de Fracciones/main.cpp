#include<iostream>
#include "Operaciones.cpp"
#include "Operaciones.h"
#include "Fraccion.cpp"
#include "Imprimir.h"
using namespace std;

int main(){
	
	Validacion valido;
	Operaciones op;
	
	
	cout<<"Ingrese el numerador: ";
	float a = valido.ingresarDatosfloat();
	cout<<"Ingrese el denominador: ";
	float b = valido.ingresarDatosfloat();
	Fraccion floatF1(a,b);
	op.imprimir(floatF1);
	
	cout<<"Ingrese el numerador: ";
	float c = valido.ingresarDatosfloat();
	cout<<"Ingrese el denominador: ";
	float d = valido.ingresarDatosfloat();
	Fraccion floatF2(c,d);
	op.imprimir(floatF2);

	Fraccion floatF3=op.calculo(floatF1,floatF2);
	cout<<"La respuesta de la suma de fracciones es: ";
	op.imprimir(floatF3);
	
	system("pause");
		
}