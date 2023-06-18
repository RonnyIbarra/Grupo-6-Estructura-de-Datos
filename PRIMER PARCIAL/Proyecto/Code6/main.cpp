/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  main.cpp
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
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
	ListaDoble<Persona>* listaPersonas = GestorArchivos<Persona>::cargarListaPersonaDesdeArchivo("personas.txt");
	ListaDoble<Registro>* listaRegistros = GestorArchivos<Registro>::cargarListaRegistroDesdeArchivo("registros.txt"); 
	Validacion validacion;
	Fecha fechaNacimiento;
	long int cedula;
	bool bool_buscar = false;
	bool bool_eliminar = false;
	int d, m, y;
	string nombre, apellido;
	
	int opcion;

    do {
        system("color a");
		system("cls");
		printf("\t****************************\n\tSISTEMA CONTROL DE REGISTROS\n\t****************************\n\n");
        std::cout << "1. Mostrar personal\n";
        std::cout << "2. Mostrar registros\n";
        std::cout << "3. Control de Registros\n";
        std::cout << "4. Eliminar por cedula\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese su opcion: ";
        opcion = validacion.ingresarDatosEnteros();
		
        switch (opcion) {
            case 1:
                	system("cls");
                	printf("\t****************************\n\t    LISTA DEL PERSONAL   \n\t****************************\n\n\n\n");
                	printf("CEDULA   \t NOMBRE   \t APELLIDO   \t FECHA DE NACIMIENTO\n\n");
					listaPersonas->mostrarPersonas();
					printf("\n\n");
                	system("PAUSE");
                break;
            case 2:
                	system("cls");
                	printf("\t****************************\n\t    LISTA DE REGISTROS   \n\t****************************\n\n");
					listaRegistros->mostrarRegistros(listaPersonas);
                	system("PAUSE");
                break;
            case 3:
				listaPersonas = GestorArchivos<Persona>::cargarListaPersonaDesdeArchivo("personas.txt");
				listaRegistros = GestorArchivos<Registro>::cargarListaRegistroDesdeArchivo("registros.txt"); 
				printf("\n");
				system("cls");
				printf("\t****************************\n\tSISTEMA CONTROL DE REGISTROS\n\t****************************\n\n");
				cedula = validacion.validarCedula();
				while(cedula == -1 ){
					printf("Cedula ingresada no valida, intente de nuevo\n");
					cedula = validacion.validarCedula();
				}
				
				bool_buscar = listaPersonas->buscar(cedula);
				if(bool_buscar){
					int sw;
					system("cls");
					printf("\t****************************\n\t          CONTROL          \n\t****************************\n\n");
					
					Nodo<Persona>* nodo = listaPersonas->buscarNodo(cedula);
					Nodo<Registro>* nodoRegistro = listaRegistros->buscarNodoPorCola(cedula);
					if (nodo != nullptr) {
				        Persona personaActual = nodo->getDato();
				        Registro registroActual = nodoRegistro->getDato();
				        //salida o entrada segun la bandera 'sw'
				        
				    	if(personaActual.getSw() == 0){ 	//SALIDA
				    		int swAux = 1;	
				        	Persona nuevoPersona(personaActual.getCedula(),personaActual.getNombre(),personaActual.getApellido(),swAux,personaActual.getFechaNacimiento());
							// Modificar los atributos de Registro
				        	personaActual.setSw(nuevoPersona.getSw());
							registroActual.setHoraSalidaFromSystem();
				        	// Actualizar el nodo
				        	nodo->setDato(personaActual);
				        	nodoRegistro->setDato(registroActual);

				        	// Guardar la lista actualizada en el archivo
				        	GestorArchivos<Persona>::guardarListaPersonaEnArchivo("personas.txt", listaPersonas);
				        	GestorArchivos<Registro>::guardarListaRegistroEnArchivo("registros.txt", listaRegistros);
							
							registroActual.toStringSalida();
				       		std::cout << "Hora de SALIDA Registrada...." << std::endl;
				       		
						}else if(personaActual.getSw() == 1){	//ENTRADA
							int swAux1 = 0;
							std::tm tiempo = {};
							tiempo.tm_year = 1900 - 1900; // Año: resta 1900
							tiempo.tm_mon = 0; // Mes: índice 0 representa enero
							tiempo.tm_mday = 1; // Día: 1
							tiempo.tm_hour = 0; // Hora: 0
							tiempo.tm_min = 0; // Minuto: 0
							tiempo.tm_sec = 0; // Segundo: 0
							Registro registro1;
							registro1.setCedula(personaActual.getCedula());
							registro1.setHoraEntradaFromSystem();
							registro1.setHoraSalida(tiempo);
							Persona nuevoPersona(personaActual.getCedula(),personaActual.getNombre(),personaActual.getApellido(),swAux1,personaActual.getFechaNacimiento());
							// Modificar los atributos de Registro
				        	personaActual.setSw(nuevoPersona.getSw());
				
				        	// Actualizar el nodo
				        	nodo->setDato(personaActual);
							
							// Guardar en la lista de registros
							listaRegistros->insertarPorCola(registro1);
							
							// Guardar la lista actualizada en el archivo
							GestorArchivos<Persona>::guardarListaPersonaEnArchivo("personas.txt", listaPersonas);
							GestorArchivos<Registro>::guardarListaRegistroEnArchivo("registros.txt", listaRegistros);
							
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
					fechaNacimiento = validacion.validarFecha();
					while(fechaNacimiento.getDia() == 0 || fechaNacimiento.getDia() == -1){
						if(fechaNacimiento.getDia() == -1){
							printf("La fecha ingresada no existe");
							fechaNacimiento = validacion.validarFecha();
						}else{
							printf("Recuerde que usted debe ser mayor de edad para poder ser registrado");
							fechaNacimiento = validacion.validarFecha();
						}
					}
					
					std::tm tiempo = {};
					tiempo.tm_year = 1900 - 1900; // Año: resta 1900
					tiempo.tm_mon = 0; // Mes: índice 0 representa enero
					tiempo.tm_mday = 1; // Día: 1
					tiempo.tm_hour = 0; // Hora: 0
					tiempo.tm_min = 0; // Minuto: 0
					tiempo.tm_sec = 0; // Segundo: 0
					Registro registro2;
					registro2.setCedula(cedula);
					registro2.setHoraEntradaFromSystem();
					registro2.setHoraSalida(tiempo);
					int sw=0;
					Persona persona1(cedula,nombre,apellido,sw,fechaNacimiento);
					listaPersonas->insertarPorCola(persona1); 
					listaRegistros->insertarPorCola(registro2);
					// Guardar la lista actualizada en el archivo
					GestorArchivos<Persona>::guardarListaPersonaEnArchivo("personas.txt", listaPersonas);
					GestorArchivos<Registro>::guardarListaRegistroEnArchivo("registros.txt", listaRegistros);
					
    				printf("INFORMACION\n");
    				registro2.toStringEntrada();
    				printf("Hora de ENTRADA Registrada...\n\nGuardado con exito ...\n");
					system("PAUSE");
				}
				
				break;
			case 4:
                	listaPersonas = GestorArchivos<Persona>::cargarListaPersonaDesdeArchivo("datos.dat");
					printf("\n");
					system("cls");
					printf("\t****************************\n\t    ELIMINAR POR CEDULA    \n\t****************************\n\n");
					cedula = validacion.validarCedula();
					while(cedula == -1 ){
						printf("Cedula ingresada no valida, intente de nuevo\n");
						cedula = validacion.validarCedula();
					}
					bool_eliminar = listaPersonas->buscar(cedula);
					if(bool_eliminar){
						listaPersonas->eliminar(cedula);
						 // Guardar la lista actualizada en el archivo
						GestorArchivos<Persona>::guardarListaPersonaEnArchivo("personas.txt", listaPersonas);
						printf("\nSe elimino correctamante...\n");
					}else{
						printf("\nNo se encontro la cedula que deseaba eliminar\n");	
					}
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