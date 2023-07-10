/***********************************************************************
 * Module:  Validar.h
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#include <iostream>
#include <conio.h>
#include "Validacion.h"


Validacion::Validacion()
{
}

string Validacion::validarExpresion(){
	int n = 0;

	return to_string(n);
}

char* Validacion::ingresoExpresion(char const *msj)
    {
        char *a = new char[0];
        char c;
        int i = 0;
        cout << msj;
        while ((c = getch()) != 13)
        {
            if (c >= '0' && c <= '9' || c == 113|| c == 114 || c == 115 || c == 116|| c == 99
            || c == 47||c == 42 || c == 43|| c == 45
            || c == 94 )
            {
                cout << c;
                a[i++] = c;
            }
            else if (c == '\b')
            {
                i--;
                cout << "\b \b";
            }
            if (a[0] >= 'a' && a[0] <= 'z')
            {
                a[0] = a[0] - 32;
            }
        }
        a[i] = '\0';
        return a;
    }
