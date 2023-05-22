/***********************************************************************
 * Module:  Template.cpp
 * Author:  Alexander Guaman, Ronny Ibarra, Kevin Amaguaña
 * Modified: miércoles, 13 de mayo de 2023 19:12:18
 * Purpose: Declaration of the class Template
 ***********************************************************************/

#include "Template.hpp"

// Definición
template <typename T>
T Fraccion<T>::getNumerador(void){return numerador;}

template <typename T>
void Fraccion<T>::setNumerador(T newNumerador){numerador = newNumerador;}

template <typename T>
T Fraccion<T>::getDenominador(void){return denominador;}

template <typename T>
void Fraccion<T>::setDenominador(T newDenominador){denominador = newDenominador;}

template <typename T>
Fraccion<T>::Fraccion(){}

template <typename T>
Fraccion<T>::~Fraccion(){}
