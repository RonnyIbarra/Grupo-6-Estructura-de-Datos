/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Persona.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined PERSONA_H
#define PERSONA_H

#include "Fecha.h"
#include <iostream>

using namespace std;

// Clase abstracta Persona
class Persona {
protected:
    string dni;
    string nombre;
    string apellido;
    Fecha fecha;

public:
    Persona();
    Persona(string,string,string,Fecha);
    string getDni();
    string getNombre();
    string getApellido();
    Fecha getFecha();
    void setDni(string);
    void setNombre(string);
    void setApellido(string);
    void setFecha(Fecha);
    virtual void toString() = 0;
    virtual void toStringTable() = 0;
};

#endif
