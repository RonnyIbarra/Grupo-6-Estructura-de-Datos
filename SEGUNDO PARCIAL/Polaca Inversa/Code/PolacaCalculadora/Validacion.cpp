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

char* Validacion::ingresoExpresion(char const *msj)
 {
 
           char* a = new char[0];
    char c;
    int i = 0;
    bool esPunto = false;
    
    cout << msj;
    while ((c = getch()) != 13) {
          if (c >= '0' && c <= '9' || c == 113|| c == 114 || c == 115 || c == 116|| c == 99
            || c == 47||c == 42 || c == 43|| c == 45 
            || c == 94 ) {
            cout << c;
            a[i++] = c;
            esPunto = false;
        }
        else if (c == '.' && !esPunto) {
            cout << c;
            a[i++] = c;
            esPunto = true;
        }
        else if (c == '\b') {
            i--;
            if (a[i] == '.') {
                esPunto = false;
            }
            cout << "\b \b";
        }
        if (i == 0 && (a[0] >= 'a' && a[0] <= 'z')) {
            a[0] = a[0] - 32;
        }
    }
    a[i] = '\0';
    return a;
    }
