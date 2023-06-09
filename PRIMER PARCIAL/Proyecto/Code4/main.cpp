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
		printf("\t****************************\n\tSISTEMA CONTROL DE REGISTROS\n\t****************************\n\n");
        std::cout << "1. Mostrar registros\n";
        std::cout << "2. Control de Registros\n";
        std::cout << "3. Eliminar por cedula\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese su opcion: ";
        opcion = validacion.ingresarDatosEnteros();
		
        switch (opcion) {
            case 1:
                	system("cls");
                	printf("\t****************************\n\t    LISTA DE REGISTROS   \n\t****************************\n\n");
					listaPersonas->mostrar();
                	system("PAUSE");
                break;
            case 2:
				listaPersonas = GestorArchivos<Persona>::cargarListaDesdeArchivo("datos.dat");
				printf("\n");
				system("cls");
				printf("\t****************************\n\tSISTEMA CONTROL DE REGISTROS\n\t****************************\n\n");
				do{
					cedula = validacion.validarCedula();
				}while(cedula == -1 );	
				
				bool_buscar = listaPersonas->buscar(cedula);
				if(bool_buscar){
					int sw;
					system("cls");
					printf("\t****************************\n\t          CONTROL          \n\t****************************\n\n");
					
					Nodo<Persona>* nodo = listaPersonas->buscarNodo(cedula);
					if (nodo != nullptr) {
				        Persona personaActual = nodo->getDato();
				        //salida o entrada segun la bandera 'sw'
				    	if(personaActual.getSw() == 0){
				    		int swAux = 1;
							Registro registro3;
				    		registro3.setHoraEntrada(personaActual.getRegistro().getHoraEntrada());		
				    		registro3.setHoraSalidaFromSystem();
				        	Persona nuevoPersona(personaActual.getCedula(),personaActual.getNombre(),personaActual.getApellido(),swAux,personaActual.getFechaNacimiento(),registro3);
							// Modificar los atributos de Registro
				        	personaActual.setRegistro(nuevoPersona.getRegistro());
				        	personaActual.setSw(nuevoPersona.getSw());
				
				        	// Actualizar el nodo
				        	nodo->setDato(personaActual);
				        	// Guardar la lista actualizada en el archivo
				        	GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaPersonas);
							
							registro3.toStringSalida();
				       		std::cout << "Hora de SALIDA Registrada...." << std::endl;
						}else if(personaActual.getSw() == 1){
							int swAux1 = 0;
							std::tm Hora0 = {};
							Registro registro1;
							registro1.setHoraEntradaFromSystem();
							registro1.setHoraSalida(Hora0);
							Persona nuevoPersona(personaActual.getCedula(),personaActual.getNombre(),personaActual.getApellido(),swAux1,personaActual.getFechaNacimiento(),registro1);
							// Modificar los atributos de Registro
				        	personaActual.setRegistro(nuevoPersona.getRegistro());
				        	personaActual.setSw(nuevoPersona.getSw());
				
				        	// Actualizar el nodo
				        	nodo->setDato(personaActual);
							// Guardar la lista actualizada en el archivo
				        	GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaPersonas);
							
							registro1.toStringEntrada();
				        	std::cout << "Hora de ENTRADA Registrada...." << std::endl;	
						}else{
							printf("Se produjo un error, lo sentimos...\ninfo : ningun dato fue modificado\n");
						}
						
				    } else {
				        std::cout << "Persona no encontrada." << std::endl;
				    }
					
					system("PAUSE");
					
				}else{
					bool edad = false;
					system("cls");
					printf("\t****************************\n\t          REGISTRO          \n\t****************************\n\n");
					printf("Cedula: %ld\n",cedula);
					printf("Nombre: ");
					nombre = validacion.ingresarLetras();
					printf("Apellido: ");
					apellido = validacion.ingresarLetras();
					printf("Fecha de Nacimiento");
					printf("\n\tdia: ");
					d = validacion.validarDia();
					printf("\tmes: ");
					m = validacion.validarMes();
					printf("\tanio: ");
					y = validacion.validarYear();
					Fecha fechaNacimiento(d,m,y);

					Registro registro2;
					registro2.setHoraEntradaFromSystem();
					int sw=0;
					Persona persona1(cedula,nombre,apellido,sw,fechaNacimiento, registro2);
					listaPersonas->insertarPorCola(persona1); 
					// Guardar la lista actualizada en el archivo
					GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaPersonas);
    				printf("Guardado con exito ...\n\nINFORMACION\n");
    				registro2.toStringEntrada();
				    std::cout << "Hora de ENTRADA Registrada...." << std::endl;	
    				
					system("PAUSE");
				}
				
				break;
			case 3:
                	listaPersonas = GestorArchivos<Persona>::cargarListaDesdeArchivo("datos.dat");
					printf("\n");
					system("cls");
					printf("\t****************************\n\t    ELIMINAR POR CEDULA    \n\t****************************\n\n");
					do{
					cedula = validacion.validarCedula();
					}while(cedula == -1 );
					listaPersonas->eliminar(cedula);
					 // Guardar la lista actualizada en el archivo
					GestorArchivos<Persona>::guardarListaEnArchivo("datos.dat", listaPersonas);
					printf("Se elimino correctamante...");
					
                	system("PAUSE");
            break;
                
                break;
            case 0:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}