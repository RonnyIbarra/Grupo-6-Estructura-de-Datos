/***********************************************************************
 * Module:  Fraccion.cpp
 * Author:  ronny
 * Modified: miércoles, 10 de mayo de 2023 8:20:18
 * Purpose: Implementation of the class Fraccion
 ***********************************************************************/

#include "Fraccion.h"

Fraccion::Fraccion(int num, int den) {
    numerador = num;
    denominador = den;
}

Fraccion::Fraccion() {}

int Fraccion::getNumerador() {
    return numerador;
}

void Fraccion::setNumerador(int newNumerador) {
    numerador = newNumerador;
}

int Fraccion::getDenominador() {
    return denominador;
}

void Fraccion::setDenominador(int newDenominador) {
    denominador = newDenominador;
}

Fraccion::~Fraccion() {
    // TODO: implement
}