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
		cout << "Insertar" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Insertar" << endl;
	}
	if (selectedItem == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
		cout << "Buscar" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Buscar" << endl;
	}
	if (selectedItem == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
		cout << "Eliminar" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
	}
	else {
		cout << "   Eliminar" << endl;
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
				listaEmpleados = GestorArchivos<Empleado>::cargarListaEmpleadoDesdeArchivo("empleados.txt");
				system("cls");
				printf("\tInsertar\n");
				dni = validacion.validarDni();
				while (dni == "-1") {	
					printf("\033[1;33mDNI ingresada no valido, intente de nuevo\033[0m\n");
					dni = validacion.validarDni();
				}
				//registrar
				bool_buscar = listaEmpleados->buscar(dni);
				if (bool_buscar) {
					// implementar el registro de cada persona que ya este registrada
					listaRegistro = GestorArchivos<Registro>::cargarListaRegistroDesdeArchivo("registros.txt");
					bool edad = false;
					system("cls");
					std::cout << "Relizar registro de la hora" << std::endl;
					time_t tiempoActual = time(nullptr);
					tm* fechaActual = localtime(&tiempoActual);

					int diaActual = fechaActual->tm_mday;
					int mesActual = fechaActual->tm_mon + 1;
					int anioActual = fechaActual->tm_year + 1900;
					int horaActual = fechaActual->tm_hour;
					int minutosActual = fechaActual->tm_min;
					int segundosActual = fechaActual->tm_sec;
					Fecha fecha1(diaActual, mesActual, anioActual, horaActual, minutosActual, segundosActual);
					Registro registro1;
					registro1.setDni(dni);
					registro1.setFecha(fecha1);
					listaRegistro->insertar(registro1);
					printf("hora   %d:%d:%d", horaActual, minutosActual, segundosActual);
					// Guardar la lista actualizada en el archivo
					GestorArchivos<Registro>::guardarListaRegistroEnArchivo("registros.txt", listaRegistro);
					printf("\nGuardado con exito...\n\n");

				}
				else {
					bool edad = false;
					system("cls");
					printf("\tInsertar\n\n");
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
					listaEmpleados->insertar(empleado1);
					// Guardar la lista actualizada en el archivo
					GestorArchivos<Empleado>::guardarListaEmpleadoEnArchivo("empleados.txt", listaEmpleados);
					printf("\nGuardado con exito...\n\n");

				}

				selectedItem--;
				system("PAUSE");
				break;
			case 2:
				listaEmpleados = GestorArchivos<Empleado>::cargarListaEmpleadoDesdeArchivo("empleados.txt");
				system("cls");
				printf("\tBuscar\n");
				dni = validacion.validarDni();
				while (dni == "-1") {
					printf("DNI ingresada no valido, intente de nuevo\n");
					dni = validacion.validarDni();
				}
				bool_buscar = listaEmpleados->buscar(dni);
				if (bool_buscar) {
					cout << "La persona con el DNI " << dni << " si se encuentra registrada" << endl;
				}
				else {
					cout << "La persona con el DNI " << dni << " no se pudo encontrar" << endl;
				}
				selectedItem--;
				system("PAUSE");
				break;
			case 3:
				listaEmpleados = GestorArchivos<Empleado>::cargarListaEmpleadoDesdeArchivo("empleados.txt");
				system("cls");
				printf("\tEliminar\n");
				dni = validacion.validarDni();
				while (dni == "-1") {
					printf("DNI ingresada no valido, intente de nuevo\n");
					dni = validacion.validarDni();
				}
				bool_eliminar = listaEmpleados->buscar(dni);
				if (bool_eliminar) {
					listaEmpleados->eliminar(dni);
					// Guardar la lista actualizada en el archivo
					GestorArchivos<Empleado>::guardarListaEmpleadoEnArchivo("empleados.txt", listaEmpleados);

					printf("\nSe elimino correctamante...\n");
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
				listaRegistro->mostrar();
				selectedItem--;
				system("PAUSE");
				break;
			case 6:
				printf("Ordenar Por Apellido (Radix)\n\n");
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