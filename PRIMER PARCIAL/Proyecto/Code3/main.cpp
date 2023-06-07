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
	ListaDoble<Persona>* listaPersonas = GestorArchivos<Persona>::cargarListaDesdeArchivo("datos.dat");
	listaPersonas->mostrar();
	Validacion validacion;
	long int cedula;
	bool bool_buscar = false;
	int d, m, y;
	string nombre, apellido;
	
	system("PAUSE");
	system("cls");
	printf("\t****************************\n\tSISTEMA CONTROL DE REGISTROS\n\t****************************\n\n");
	do{
		cedula = validacion.validarCedula();
	}while(cedula == -1 );	
	
	bool_buscar = listaPersonas->buscar(cedula);
	if(bool_buscar){
		system("cls");
		printf("\n\t***CONTROL***\n");
		Registro registro1;
		registro1.setHoraEntradaFromSystem();
		listaPersonas->modificarHoraEntrada(*listaPersonas, cedula, registro1.getHoraEntrada());
		printf("hora registrada\n");
		GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaPersonas);
		listaPersonas->mostrar();
		
	}else{
		system("cls");
		printf("\n\t***REGISTRO***\n");
		printf("Cedula: %ld\n",cedula);
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
		Registro registro2;
		registro2.setHoraEntradaFromSystem();
		int sw = 0;
		Persona persona1(cedula,nombre,apellido,sw,fechaNacimiento, registro2);
		listaPersonas->insertarPorCola(persona1); 
		GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaPersonas);
	}
	

	//fin del programa
	return 0;
}
