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
	Validacion validacion;
	long int cedula;
	bool bool_buscar = false;
	int d, m, y;
	string nombre, apellido;
	
	int opcion;

    do {
        system("color a");
		system("cls");
		std::cout << "MENU\n";
        std::cout << "1. Mostrar registros\n";
        std::cout << "2. Control de Registros\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                	listaPersonas->mostrar();
                	system("PAUSE");
                break;
            case 2:
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
					registro1.toString();
					
					listaPersonas->modificarHoraEntrada( cedula, registro1.getHoraEntrada());
					GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaPersonas);
					
					system("PAUSE");
					
				}else{
					bool edad = false;
					Fecha fechaNacimiento;
					system("cls");
					printf("\n\t***REGISTRO***\n");
					printf("Cedula: %ld\n",cedula);
					printf("Nombre: ");
					nombre = validacion.ingresarLetras();
					printf("Apellido: ");
					apellido = validacion.ingresarLetras();
					
					while(edad==false){
						printf("Fecha de Nacimiento");
					    printf("\n\tdia: ");
						d = validacion.ingresarDatosEnteros();
						printf("\tmes: ");
						m = validacion.ingresarDatosEnteros();
						printf("\tanio: ");
						y = validacion.ingresarDatosEnteros();
						Fecha fechaNacimiento(d,m,y);
						edad = validacion.esMayorDeEdad(fechaNacimiento);
					}

					Registro registro2;
					registro2.setHoraEntradaFromSystem();
					int sw = 0;
					Persona persona1(cedula,nombre,apellido,sw,fechaNacimiento, registro2);
					listaPersonas->insertarPorCola(persona1); 
					GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaPersonas);
					
					system("PAUSE");
				}
	
                
                break;
            case 0:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcinn invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}