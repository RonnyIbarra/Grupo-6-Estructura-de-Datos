/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Empleado.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Empleado
 ***********************************************************************/

#if !defined EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"
#include <iostream>

using namespace std;

class Empleado : public Persona {
private:
    float sueldo;
public:
    Empleado();
	Empleado(string, string, string, Fecha, float);
    float getSueldo();
    void setSueldo(float sueldo);
    void toString();
    void toStringTable();

};

#endif