/***********************************************************************
 * Module:  Validar.h
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#ifndef VALIDACION_H
#define VALIDACION_H

#include <string>
#include <regex>
using namespace std;

class Validacion {
public:
    Validacion();
    string validarExpresion();
    bool verificarParentesisSinOperador(const string& expresion);
    bool verificarOperadores(const string& expresion, size_t index, bool& esOperadorPermitido);
    bool verificarLetras(const string& expresion, size_t index, bool esFuncion);
    bool verificarDecimales(const string& expresion, size_t index);
    bool verificarParentesisNegativo(const string& expresion, size_t index);
    bool validarExpresion(const string& expresion);
    string ingresoExpresion(const char* msj);
};

#endif
