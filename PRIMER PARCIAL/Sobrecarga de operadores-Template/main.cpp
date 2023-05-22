/***********************************************************************
 * UFA-ESPE
 *Module:  Sobrecarga.cpp
 * Author:  Kevin Amaguña, Alexander Guaman, Ronny Ibarra
 * Modified: Wednesday, May 17, 2023 7:43:08 AM
 * Purpose: Implementation of the class Sobrecarga
 ***********************************************************************/



#include <iostream>
#include "Sobrecarga.cpp"
#include "Imprimir.h"


int main() {

    Validacion valido;
	Sobrecarga<int> sobrecarga;
    
    cout<<"Ingrese el primer numero: ";
    int num1 = valido.ingresarDatosEnteros();
    cout<<"Ingrese el segundo numero: ";
    int num2 = valido.ingresarDatosEnteros();
    
    sobrecarga.imprimir(num1, num2);

    return 0;
}