/***********************************************************************
 * Module:  Fraccion.cpp
 * Author:  ronny
 * Modified: miércoles, 10 de mayo de 2023 8:20:18
 * Purpose: Implementation of the class Fraccion
 ***********************************************************************/

#include "Fraccion.h"


template <typename T>
Fraccion<T>::Fraccion(T num, T den) {
   numerador = num;
   denominador = den;
}

template <typename T>
Fraccion<T>::Fraccion() {}

template <typename T>
T Fraccion<T>::getNumerador() {
   return numerador;
}

template <typename T>
void Fraccion<T>::setNumerador(T newNumerador) {
   numerador = newNumerador;
}

template <typename T>
T Fraccion<T>::getDenominador() {
   return denominador;
}

template <typename T>
void Fraccion<T>::setDenominador(T newDenominador) {
   denominador = newDenominador;
}

template <typename T>
Fraccion<T>::~Fraccion() {
   // TODO: implement
}