/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  main.cpp
 * Author:  Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Aplicativo para control de registro utilizando listas dobles
 ***********************************************************************/

#include "Persona.h"
#include "ListaDoble.cpp"
#include "Nodo.cpp"
#include "Validacion.h"
#include "GestorArchivos.h"


using namespace std;

int main(int argc, char** argv) {
	ListaDoble<Persona>* listaNueva = GestorArchivos<Persona>::cargarListaDesdeArchivo("datos.dat");
	Validacion validacion;
	long int val_ced;
	printf("\n\t****************************\n\tSISTEMA CONTROL DE REGISTROS\n\t****************************\n\n");
	do{
		val_ced = validacion.validarCedula();
	}while(val_ced == -1 );	

	//fin del programa
	return 0;
}
