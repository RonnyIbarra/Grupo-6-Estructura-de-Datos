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
	listaNueva->mostrar();
	Validacion validacion;
	long int val_ced;
	bool bool_buscar = false;
	int d, m, y;
	string nombre, apellido;
	
	system("PAUSE");
	system("cls");
	printf("\t****************************\n\tSISTEMA CONTROL DE REGISTROS\n\t****************************\n\n");
	do{
		val_ced = validacion.validarCedula();
	}while(val_ced == -1 );	
	
	bool_buscar = listaNueva->buscar(val_ced);
	if(bool_buscar){
		system("cls");
		printf("\n\t***CONTROL***\n");
	}else{
		system("cls");
		printf("\n\t***REGISTRO***\n");
		printf("Cedula: %ld\n",val_ced);
		printf("Nombre: ");
		nombre = validacion.ingresarLetras();
		printf("Apellido: ");
		apellido = validacion.ingresarLetras();
		printf("Fecha de Nacimiento: ");
		printf("\ndia: ");
		d = validacion.ingresarDatosEnteros();
		printf("mes: ");
		m = validacion.ingresarDatosEnteros();
		printf("anio: ");
		y = validacion.ingresarDatosEnteros();
		Fecha fechaNacimiento(d,m,y);
		Persona persona1(val_ced,nombre,apellido,fechaNacimiento);
		listaNueva->insertarPorCola(persona1); 
		GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaNueva);
	}
	

	//fin del programa
	return 0;
}
