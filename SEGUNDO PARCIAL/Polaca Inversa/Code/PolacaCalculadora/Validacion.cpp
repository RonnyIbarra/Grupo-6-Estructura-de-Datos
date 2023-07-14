/***********************************************************************
 * Module:  Validar.h
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#include <iostream>
#include <conio.h>
#include "Validacion.h"


Validacion::Validacion(){}

string Validacion::validarExpresion(){
	int n = 0;

	return to_string(n);
}
   
bool Validacion::validarExpresion(const string& expresion)
{
    int contadorParentesis = 0;
    bool esOperadorPermitido = false;
    bool esDecimalPermitido = true;  // Variable para controlar la validez de los decimales

    for (size_t i = 0; i < expresion.length(); i++) {
        char c = expresion[i];

        if (c == '(') {
            contadorParentesis++;
            esOperadorPermitido = false;
            esDecimalPermitido = true;  // Reiniciar la validación de decimales al abrir un paréntesis

            // Verificar si el paréntesis es seguido por un signo de menos para permitir números negativos
            if (i + 1 < expresion.length() && expresion[i + 1] == '-') {
                esOperadorPermitido = true;
                i++;  // Saltar al siguiente carácter después del signo de menos
            }
        }
        else if (c == ')') {
            contadorParentesis--;
            esOperadorPermitido = true;
            esDecimalPermitido = false;  // Desactivar la validación de decimales al cerrar un paréntesis
        }
        else if (isdigit(c)) {
            esOperadorPermitido = true;
        }
        else if (c == '.') {
            if (!esDecimalPermitido) {
                return false;  // Decimal no permitido en esta posición
            }
            esDecimalPermitido = false;  // Desactivar la validación de decimales después del primer punto decimal
            esOperadorPermitido = true;
        }
        else if (isalpha(c)) {
            char letra = tolower(c);
            if (letra != 'q' && letra != 'r' && letra != 's' && letra != 't' && letra != 'c' && letra != 'y') {
                return false;  // Letra no permitida
            }
            esOperadorPermitido = true;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            if (!esOperadorPermitido) {
                // Verificar si el signo de menos es para un número negativo
                if (c == '-' && i + 1 < expresion.length() && (isdigit(expresion[i + 1]) || expresion[i + 1] == '.')) {
                    esOperadorPermitido = true;
                    i++;  // Saltar al siguiente carácter después del signo de menos
                }
                else {
                    return false;  // Operador sin número o letra previo
                }
            }
            else {
                esOperadorPermitido = false;
            }
        }
        else {
            return false;  // Carácter no permitido
        }

        if (contadorParentesis < 0) {
            return false;  // Hay un paréntesis ")" sin su correspondiente "(" previo
        }
    }

    if (contadorParentesis != 0) {
        return false;  // Hay un paréntesis "(" sin cerrar
    }

    // Verificar si hay paréntesis sin operador entre ellos
    size_t pos = expresion.find(")(");
    if (pos != string::npos) {
        return false; 
    }

    return expresion.length() > 0;
   
}

string Validacion::ingresoExpresion(const char* msj)
{
    string expresion;
    bool expresionValida = false;

    while (!expresionValida)
    {
        cout << msj;
        getline(cin, expresion);
        expresionValida = validarExpresion(expresion);

        if (!expresionValida)
        {
            cout << "Expresion mal escrita. Por favor, intenta nuevamente." << endl;
        }
    }

    return expresion;
}
