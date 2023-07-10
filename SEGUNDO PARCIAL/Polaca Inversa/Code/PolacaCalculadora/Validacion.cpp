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


char* Validacion::ingresoExpresion()
{
    char* a = new char[0];
    char c;
    int i = 0;
    while ((c = _getch()) != 13)
    {
        if (c >= '0' && c <= '9' || c == 113 || c == 114 || c == 115 || c == 116 || c == 99
            || c == 47 || c == 42 || c == 43 || c == 45 || c == 46
            || c == 94)
        {
            cout << c;
            a[i++] = c;
        }
        else if (c == '\b')
        {
            i--;
            cout << "\b \b";
        }
    }
    a[i] = '\0';
    return a;
}