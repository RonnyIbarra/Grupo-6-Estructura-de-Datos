/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  main.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified: Monday, June 19, 2023 8:24:36 AM
 * Purpose: Control de Registros
 ***********************************************************************/

#include <iostream>
#include <conio.h>
#include <windows.h>

#include "ListaCircularDoble.cpp"
#include "Nodo.cpp"
#include "Persona.h"
#include "Validacion.h"
#include "GestorArchivos.h"

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
    } else {
        cout << "   Insertar" << endl;
    }
    if (selectedItem == 1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
        cout << "Buscar" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
    } else {
        cout << "   Buscar" << endl;
    }
    if (selectedItem == 2) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
        cout << "Eliminar" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
    } else {
        cout << "   Eliminar" << endl;
    }
    if (selectedItem == 3) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
        cout << "Mostrar" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
    } else {
        cout << "   Mostrar" << endl;
    }
    if (selectedItem == 4) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
        cout << "Ordenar (Radix)" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color normal
    } else {
        cout << "   Ordenar (Radix)" << endl;
    }
}

int main() {
    ListaCircularDoble<Persona>* listaPersonas = GestorArchivos<Persona>::cargarListaPersonaDesdeArchivo("personas.txt");
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
                        selectedItem = (selectedItem - 1 + 5) % 5;
                        break;
                    case 80:  // Tecla flecha abajo
                        selectedItem = (selectedItem + 1) % 5;
                        break;
                }
                break;
            case 13:  // Tecla Enter
                system("cls");
                selectedItem ++;
                
                switch(selectedItem){
                	case 1:
                		listaPersonas = GestorArchivos<Persona>::cargarListaPersonaDesdeArchivo("personas.txt");
                		system("cls");
						printf("\tInsertar\n");
                		dni = validacion.validarDni();
						while(dni == "-1" ){
							printf("DNI ingresada no valido, intente de nuevo\n");
							dni = validacion.validarDni();
						}
                		//registrar
                		bool_buscar = listaPersonas->buscar(dni);
						if(bool_buscar){
							system("cls");					
							// implementar el registro de cada persona que ya este registrada
							std::cout << "Relizar registro de la hora" << std::endl;
							
						}else{
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
							while(fechaNacimiento.getDia() == 0 || fechaNacimiento.getDia() == -1){
								if(fechaNacimiento.getDia() == -1){
									printf("La fecha ingresada no existe");
									fechaNacimiento = validacion.validarFecha();
								}else{
									printf("Recuerde que usted debe ser mayor de edad para poder ser registrado");
									fechaNacimiento = validacion.validarFecha();
								}
							}
							Persona persona1(dni,nombre,apellido,fechaNacimiento);
							listaPersonas->insertar(persona1); 
							// Guardar la lista actualizada en el archivo
							GestorArchivos<Persona>::guardarListaPersonaEnArchivo("personas.txt", listaPersonas);
							printf("\nGuardado con exito...\n\n");
						
						}
                		
                		selectedItem --;
                		system("PAUSE");
						break;
					case 2:
						//listaPersonas = GestorArchivos<Persona>::cargarListaPersonaDesdeArchivo("datos.dat");
						system("cls");
						printf("\tBuscar\n");
						dni = validacion.validarDni();
						while(dni == "-1" ){
							printf("DNI ingresada no valido, intente de nuevo\n");
							dni = validacion.validarDni();
						}						
						bool_buscar = listaPersonas->buscar(dni);
						if(bool_buscar){							
							cout << "La persona con el DNI " << dni << " si se encuentra registrada" << endl;
						}else{
							cout << "La persona con el DNI " << dni << " no se pudo encontrar" << endl;
						}
						selectedItem --;
						system("PAUSE");
						break;		
					case 3:
						//listaPersonas = GestorArchivos<Persona>::cargarListaPersonaDesdeArchivo("datos.dat");
						system("cls");
						printf("\tEliminar\n");
						dni = validacion.validarDni();
						while(dni == "-1" ){
							printf("DNI ingresada no valido, intente de nuevo\n");
							dni = validacion.validarDni();
						}						
						bool_eliminar = listaPersonas->buscar(dni);
						if(bool_eliminar){
							listaPersonas->eliminar(dni);
							// Guardar la lista actualizada en el archivo
							GestorArchivos<Persona>::guardarListaPersonaEnArchivo("personas.txt", listaPersonas);
							
							printf("\nSe elimino correctamante...\n");
						}else{
							printf("\nNo se encontro el DNI que deseaba eliminar\n");	
						}
						selectedItem --;
						system("PAUSE");
						break;
					case 4:
						printf("\tMostrar Personal\n\n");
						listaPersonas->mostrar();
						selectedItem --;
						system("PAUSE");
						break;
					case 5:
						printf("Ordenar Por Apellido (Radix)\n\n");
						listaPersonas->ordenarRadixPorApellido();
						listaPersonas->mostrar();
						GestorArchivos<Persona>::guardarListaPersonaEnArchivo("personas.txt", listaPersonas);
						selectedItem --;
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

