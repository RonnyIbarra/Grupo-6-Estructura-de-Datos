/***********************************************************************
 * Module:  Validar.h
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: domingo, 16 de Julio de 2023
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
   
bool Validacion::validarExpresion(const string& expresion)
{
    int contadorParentesis = 0;
    bool esOperadorPermitido = false;
    bool esFuncion = false;
    bool despuesDePunto = false;

    for (size_t i = 0; i < expresion.length(); i++) {
        char c = expresion[i];

        if (c == '(') {
            contadorParentesis++;
            esOperadorPermitido = false;
            esFuncion = true;  // Se encontró una función
            despuesDePunto = false;

            // Verificar si el paréntesis es seguido por un signo de menos para permitir números negativos
            if (i + 1 < expresion.length() && expresion[i + 1] == '-') {
                esOperadorPermitido = true;
                i++;  // Saltar al siguiente carácter después del signo de menos
            }
        }
        else if (c == ')') {
            contadorParentesis--;
            esOperadorPermitido = true;
            esFuncion = false;
            despuesDePunto = false;
        }
        else if (isdigit(c)) {
            esOperadorPermitido = true;
            despuesDePunto = false;
        }
        else if (c == '.') {
            if (despuesDePunto) {
                return false;  // Dos puntos consecutivos (más de un punto decimal en el mismo número)
            }
            despuesDePunto = true;
        }
        else if (isalpha(c)) {
            char letra = c;
            if (letra != 'q' && letra != 'r' && letra != 's' && letra != 't' && letra != 'c') {
                return false;
            }

            // Verificar si es una función
            if ((letra == 's' || letra == 'c' || letra == 't') && i + 2 < expresion.length() && expresion[i + 1] == '(') {
				continue;
            }
            else if (esOperadorPermitido || (letra == 's' || letra == 'c' || letra == 't')){
                return false;  // Función después de un número
            }

            esOperadorPermitido = true;
            despuesDePunto = false;
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
            despuesDePunto = false;
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
        return false;  // Existen paréntesis sin operador entre ellos
    }
    
    std::regex patron("\\d+\\.\\d+\\.");
    if (std::regex_search(expresion, patron)) {
        return false;
    }
    
    std::regex patronPuntos("\\.+\\.");
    if (std::regex_search(expresion, patronPuntos)) {
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
