/***********************************************************************
 * Module:  Fraccion.cpp
 * Author:  ronny
 * Modified: miércoles, 10 de mayo de 2023 8:20:18
 * Purpose: Implementation of the class Fraccion
 ***********************************************************************/

#include "Fraccion.h"


float Fraccion::getNumerador(void)
{
   return numerador;
}



void Fraccion::setNumerador(float newNumerador)
{
   numerador = newNumerador;
}


float Fraccion::getDenominador(void)
{
   return denominador;
}


void Fraccion::setDenominador(float newDenominador)
{
   denominador = newDenominador;
}



Fraccion::Fraccion(float num, float den)
{
   
   this->numerador=num;
   this->denominador=den;
}
Fraccion::Fraccion(){
}



Fraccion::~Fraccion()
{
   // TODO : implement
}