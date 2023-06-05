/***********************************************************************
 * Module:  Template.hpp
 * Author:  Alexander Guaman, Ronny Ibarra, Kevin Amaguaña
 * Modified: miércoles, 13 de mayo de 2023 19:12:18
 * Purpose: Declaration of the class Template
 ***********************************************************************/
#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>

// Declaración
template <typename T>
class Fraccion {
	private:
		T numerador, denominador;
	public:
		Fraccion(T num, T den) : numerador(num), denominador(den){};
		T getNumerador(void);
   		void setNumerador(T newNumerador);
   		T getDenominador(void);
   		void setDenominador(T newDenominador);
   		Fraccion();
   		~Fraccion();
};

#endif