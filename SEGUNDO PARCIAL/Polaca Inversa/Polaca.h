/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
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
	Polaca(void);
	bool Operador(char);
	int obtenerPrecedencia(char);
	string convertInfijoAPrefijo(const string&);
	string convertInfijoAPosfijo(const string&);
	double evaluarOperacion(double, double, const string &);

};

#endif  // CALCULATOR_H
