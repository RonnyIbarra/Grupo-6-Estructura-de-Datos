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
}

int main() {
    int selectedItem = 0;
    bool salir = false;

    while (!salir) {
        drawMenu(selectedItem);

        int key = _getch();

        switch (key) {
            case 224:  // Código para teclas especiales en Windows
                key = _getch();
                switch (key) {
                    case 72:  // Tecla flecha arriba
                        selectedItem = (selectedItem - 1 + 4) % 4;
                        break;
                    case 80:  // Tecla flecha abajo
                        selectedItem = (selectedItem + 1) % 4;
                        break;
                }
                break;
            case 13:  // Tecla Enter
                system("cls");
                selectedItem ++;
                
                switch(selectedItem){
                	case 1:
                		printf("\tInsertar\n");
                		selectedItem --;
                		_getch();
						break;
					case 2:
						printf("\tBuscar\n");
						selectedItem --;
						_getch();
						break;		
					case 3:
						printf("\tEliminar\n");
						selectedItem --;
						_getch();
						break;
					case 4:
						printf("\tMostrar\n");
						selectedItem --;
						_getch();
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

