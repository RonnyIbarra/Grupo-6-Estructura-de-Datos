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
    bool esDecimalPermitido = true; 
    bool esFuncion = false; 

    for (size_t i = 0; i < expresion.length(); i++) {
        char c = expresion[i];

        if (c == '(') {
            contadorParentesis++;
            esOperadorPermitido = false;
            esDecimalPermitido = true;
            esFuncion = true;

            if (!verificarParentesisNegativo(expresion, i)) {
                return false;
            }
        }
        else if (c == ')') {
            contadorParentesis--;
            esOperadorPermitido = true;
            esDecimalPermitido = false;
            esFuncion = false;
        }
        else if (isdigit(c) || c == '.') {
            if (!verificarDecimales(expresion, i)) {
                return false;
            }
            esOperadorPermitido = true;
        }
        else if (isalpha(c)) {
            if (!verificarLetras(expresion, i, esFuncion)) {
                return false;
            }
            esOperadorPermitido = true;
        }
        else if (esOperadorAritmetico(c)) {
            if (!verificarOperadores(expresion, i, esOperadorPermitido)) {
                return false;
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

    if (verificarParentesisSinOperador(expresion)) {
        return false;  // Existen paréntesis sin operador entre ellos
    }

    return expresion.length() > 0;
}

bool Validacion::verificarParentesisNegativo(const string& expresion, size_t index)
{
    if (index + 1 < expresion.length() && expresion[index + 1] == '-') {
        return true;
    }
    return false;
}

bool Validacion::verificarDecimales(const string& expresion, size_t index)
{
    if (expresion[index] == '.') {
        size_t puntoDecimal = expresion.find('.', index + 1);
        if (puntoDecimal != string::npos) {
            return false;  // Más de un punto decimal en el mismo número
        }
    }
    return true;
}

bool Validacion::verificarLetras(const string& expresion, size_t index, bool esFuncion)
{
    char letra = tolower(expresion[index]);
    if (letra != 'q' && letra != 'r' && letra != 's' && letra != 't' && letra != 'c') {
        return false;  // Letra no permitida
    }

    if ((letra == 's' || letra == 'c' || letra == 't') && index + 2 < expresion.length() && expresion[index + 1] == '(') {
        size_t posCierreParentesis = expresion.find(')', index + 2);
        if (posCierreParentesis == string::npos) {
            return false;  // Falta el paréntesis de cierre en la función
        }
        return true;
    }
    else {
        if (!esFuncion) {
            return false;  // Carácter no permitido fuera de una función
        }
    }

    return true;
}

bool Validacion::verificarOperadores(const string& expresion, size_t index, bool& esOperadorPermitido)
{
    if (!esOperadorPermitido) {
        if (expresion[index] == '-' && index + 1 < expresion.length() && (isdigit(expresion[index + 1]) || expresion[index + 1] == '.')) {
            esOperadorPermitido = true;
            return true;
        }
        else {
            return false;  // Operador sin número o letra previo
        }
    }
    else {
        esOperadorPermitido = false;
    }

    return true;
}

bool Validacion::verificarParentesisSinOperador(const string& expresion)
{
    size_t pos = expresion.find(")(");
    if (pos != string::npos) {
        return true;  // Existen paréntesis sin operador entre ellos
    }
    return false;
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
