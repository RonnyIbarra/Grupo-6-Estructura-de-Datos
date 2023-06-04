/***********************************************************************
 * UFA-ESPE
 * Module:  main.cpp
 * Author: Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
  * Created: Sunday, May 28, 2023 7:00:00 PM
 * Purpose: Resolver Torres de Hanoi con 'n' discos
 ***********************************************************************/
 
#include <iostream>
#include <stack>
#include "TorresHanoi.h"
#include "TorresHanoi.cpp"
#include "Validacion.h"

using namespace std;

int main() {
    TorresDeHanoi<int> torres;
    Validacion validacion;
    int numDiscos;

    cout << "Ingrese el numero de discos: ";
    numDiscos = validacion.ingresarDatosEnteros();
	
	cout << "Resolviendo las torres de Hanoi... " << endl << endl;
    torres.resolver(numDiscos);

    return 0;
}
