/***********************************************************************
 * Module:  Polaca.h
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: miércoles, 23 de Junio de 2023 8:20:18
 * Purpose: Polaca Inversa
 ***********************************************************************/
#ifndef POLACA_H
#define POLACA_H

#include <string>

using namespace std;

class Polaca {
public:
    static string convertInfijoAPrefijo(const string& expresion);
    static string convertInfijoAInfijo(const string& expresion);
    static string convertInfijoAPosfijo(const string& expresion);

private:
    static bool Operador(char c);
    static int obtenerPrecedencia(char operador);
};

#endif  // CALCULATOR_H
