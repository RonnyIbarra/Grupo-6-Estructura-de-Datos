/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  main.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Control Registos
 ***********************************************************************/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <locale>
#include "GestorArchivos.h"
#include "ListaCircularDoble.cpp"
#include "NodoDoble.cpp"
#include "Arbol.cpp"
#include "Nodo.cpp"
#include "Empleado.h"
#include "Validacion.h"
#include "Registro.h"


using namespace std;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawMenu(int selectedItem) {
	system("cls");  // Limpia la pantalla en Windows

	cout << "=== Menu ===" << endl;
	if (selectedItem == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
		cout << "Control Registros" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Control Registros" << endl;
	}
	if (selectedItem == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
		cout << "Buscar Empleado" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Buscar Empleado" << endl;
	}
	if (selectedItem == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
		cout << "Eliminar Empleado" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Eliminar Empleado" << endl;
	}
	if (selectedItem == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
		cout << "Mostrar Empleados" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Mostrar Empleados" << endl;
	}
	if (selectedItem == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
		cout << "Mostrar Registros" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Mostrar Registros" << endl;
	}
	if (selectedItem == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
		cout << "Ordenar (Radix)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Ordenar (Radix)" << endl;
	}
}

int main() {
	ListaCircularDoble<Empleado>* listaEmpleados = GestorArchivos<Empleado>::cargarListaEmpleadoDesdeArchivo("empleados.txt");
	ListaCircularDoble<Registro>* listaRegistro = GestorArchivos<Registro>::cargarListaRegistroDesdeArchivo("registros.txt");
	Validacion validacion;
	Fecha fechaNacimiento;
	int selectedItem = 0;
	bool bool_buscar = false;
	bool bool_eliminar = false;
	bool salir = false;
	string dni, nombre, apellido;
	Nodo<Empleado>* raiz{ nullptr };
	Arbol<Empleado>* arbol = new Arbol<Empleado>();

	if (listaEmpleados->getCabeza()) {
		NodoDoble<Empleado>* actual = listaEmpleados->getCabeza();
		do {
			arbol->insertarNodo(raiz,actual->getDato());
			actual = actual->getSiguiente();
		} while (actual != listaEmpleados->getCabeza());
	}

	while (!salir) {
		drawMenu(selectedItem);

		int key = _getch();

		switch (key) {
		case 224:  // Código para teclas especiales en Windows
			key = _getch();
			switch (key) {
			case 72:  // Tecla flecha arriba
				selectedItem = (selectedItem - 1 + 6) % 6;
				break;
			case 80:  // Tecla flecha abajo
				selectedItem = (selectedItem + 1) % 6;
				break;
			}
			break;
		case 13:  // Tecla Enter
			system("cls");
			selectedItem++;

			switch (selectedItem) {
			case 1:
				printf("\t****************************\n\tSISTEMA CONTROL DE REGISTROS\n\t****************************\n\n");
				dni = validacion.validarDni();
				while (dni == "-1") {
					printf("\033[1;33mDNI ingresada no valido, intente de nuevo\033[0m\n");
					dni = validacion.validarDni();
				}

				// CONTROL
				bool_buscar = arbol->buscar(raiz, dni);
				if (bool_buscar) {
					system("cls");
					printf("\t****************************\n\t          CONTROL          \n\t****************************\n\n");
					NodoDoble<Registro>* nodoRegistro = listaRegistro->buscarNodoPorCola(dni);


					if (nodoRegistro != nullptr) {
						Registro registroActual = nodoRegistro->getDato();
						//salida o entrada segun la bandera 'sw'

						if (registroActual.getSw() == 0) { 	//SALIDA
							registroActual.setSalidaFromSystem();
							registroActual.setSw(1);
							// Actualizar el nodo
							nodoRegistro->setDato(registroActual);
							GestorArchivos<Registro>::guardarListaRegistroEnArchivo("registros.txt", listaRegistro);
							printf("\033[1;33mINFORMACION:\033[0m\n");
							registroActual.toStringSalida();

						}
						else if (registroActual.getSw() == 1) {	//ENTRADA
							Registro registro;
							registro.setDni(dni);
							registro.setEntradaFromSystem();
							registro.setSw(0);
							// Actualizar el nodo
							nodoRegistro->setDato(registroActual);
							listaRegistro->insertarPorCola(registro);
							GestorArchivos<Registro>::guardarListaRegistroEnArchivo("registros.txt", listaRegistro);
							printf("\033[1;33mINFORMACION:\033[0m\n");
							registro.toStringEntrada();
						}
						else {
							printf("Se produjo un error, lo sentimos...\ninfo : ningun dato fue modificado\n");
						}
					}
					else {
						printf("Se produjo un error\n");
					}

				}
				else {
					system("cls");
					printf("\t****************************\n\t          REGISTRO          \n\t****************************\n\n");
					std::cout << "DNI: " << dni << std::endl;
					printf("Nombre: ");
					nombre = validacion.ingresarLetras();
					printf("Apellido: ");
					apellido = validacion.ingresarLetras();
					printf("Fecha de Nacimiento");
					fechaNacimiento = validacion.validarFecha();
					while (fechaNacimiento.getDia() == 0 || fechaNacimiento.getDia() == -1) {
						if (fechaNacimiento.getDia() == -1) {
							printf("La fecha ingresada no existe");
							fechaNacimiento = validacion.validarFecha();
						}
						else {
							printf("Recuerde que usted debe ser mayor de edad para poder ser registrado");
							fechaNacimiento = validacion.validarFecha();
						}
					}
					float sueldo = validacion.validarSueldo();
					Empleado empleado1(dni, nombre, apellido, fechaNacimiento, sueldo);
					Registro registro2;
					registro2.setDni(dni);
					registro2.setEntradaFromSystem();
					registro2.setSw(0);
					listaRegistro->insertarPorCola(registro2);
					listaEmpleados->insertar(empleado1);
					arbol->insertarNodo(raiz, empleado1);
					// Guardar la lista actualizada en el archivo
					GestorArchivos<Empleado>::guardarListaEmpleadoEnArchivo("empleados.txt", listaEmpleados);
					GestorArchivos<Registro>::guardarListaRegistroEnArchivo("registros.txt", listaRegistro);
					printf("\033[1;33mINFORMACION:\033[0m\n");
					printf("Registrado con exito...\n");
					registro2.toStringEntrada();
				}

				selectedItem--;
				system("PAUSE");
				break;
			case 2:
				printf("\tBuscar\n");
				dni = validacion.validarDni();
				while (dni == "-1") {
					printf("DNI ingresada no valido, intente de nuevo\n");
					dni = validacion.validarDni();
				}
				bool_buscar = arbol->buscar(raiz,dni);
				if (bool_buscar) {
					Empleado empleadoBuscado = arbol->buscarNodo(raiz, dni);
					if (empleadoBuscado.getDni() != "") {
						empleadoBuscado.toString();
					}
					else {
						cout << dni << " No se encuentra registrada" << endl;
					}
				}
				else {
					cout << dni << " No se encuentra registrada" << endl;
				}
				selectedItem--;
				system("PAUSE");
				break;
			case 3:
				printf("\tEliminar Empleado\n\nDni\t	Nombre\n");
				arbol->inOrden(raiz);
				printf("\n");
				dni = validacion.validarDni();
				while (dni == "-1") {
					printf("DNI ingresada no valido, intente de nuevo\n");
					dni = validacion.validarDni();
				}
				bool_eliminar = arbol->buscar(raiz,dni);
				if (bool_eliminar) {
					listaEmpleados->eliminar(dni);
					raiz = arbol->eliminarNodo(raiz,dni);

					NodoDoble<Registro>* nodoRegistro = listaRegistro->buscarNodoPorCola(dni);
					if (nodoRegistro != nullptr) {
						Registro registroActual = nodoRegistro->getDato();
						if (registroActual.getSw() == 0) { 	//SALIDA
							registroActual.setSalidaFromSystem();
							registroActual.setSw(1);
							// Actualizar el nodo
							nodoRegistro->setDato(registroActual);
							GestorArchivos<Registro>::guardarListaRegistroEnArchivo("registros.txt", listaRegistro);
							printf("\033[1;33mINFORMACION:\033[0m\n");
							registroActual.toStringSalida();

						}
					}
					// Guardar la lista actualizada en el archivo
					GestorArchivos<Empleado>::guardarListaEmpleadoEnArchivo("empleados.txt", listaEmpleados);
					printf("Se elimino correctamante...\n");
				}
				else {
					printf("\nNo se encontro el DNI que deseaba eliminar\n");
				}
				selectedItem--;
				system("PAUSE");
				break;
			case 4:
				printf("\tMostrar Personal\n\n");
				printf("CEDULA   \t APELLIDO   \t NOMBRE   \t FECHA DE NACIMIENTO   \t SUELDO\n\n");
				listaEmpleados->mostrarTabla();
				selectedItem--;
				system("PAUSE");
				break;
			case 5:
				printf("\tMostrar Registros\n\n");
				listaRegistro->mostrarRegistros(listaEmpleados);
				selectedItem--;
				system("PAUSE");
				break;
			case 6:
				printf("\tOrdenar Por Apellido (Radix)\n\n");
				printf("CEDULA   \t APELLIDO   \t NOMBRE   \t FECHA DE NACIMIENTO\n\n");
				listaEmpleados->ordenarRadixPorApellido();
				listaEmpleados->mostrarTabla();
				GestorArchivos<Empleado>::guardarListaEmpleadoEnArchivo("empleados.txt", listaEmpleados);
				selectedItem--;
				system("PAUSE");
				break;
			}

			break;
		case 27:  // Tecla Escape
			salir = true;
			break;
		}
	}

	return 0;
}