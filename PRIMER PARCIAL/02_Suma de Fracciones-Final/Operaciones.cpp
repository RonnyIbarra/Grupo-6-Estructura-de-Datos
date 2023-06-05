/***********************************************************************
 * Module:  Operaciones.cpp
 * Author:  ronny
 * Modified: jueves, 11 de mayo de 2023 16:56:25
 * Purpose: Implementation of the class Operaciones
 ***********************************************************************/

#include "Operaciones.h"
#include "Fraccion.cpp"
#include<iostream>

using namespace std; 



Operaciones::Operaciones() {

}

float Operaciones::calculo(Fraccion obj1, Fraccion obj2) {
    float n1, n2, n3, n4, num, deno;

    n1 = obj1.getNumerador();
    n2 = obj1.getDenominador();
    n3 = obj2.getNumerador();
    n4 = obj2.getDenominador();

    num = (n1 * n4) + (n2 * n3);
    deno = (n2 * n4);


cout.precision(3);
    return num / deno;
}
