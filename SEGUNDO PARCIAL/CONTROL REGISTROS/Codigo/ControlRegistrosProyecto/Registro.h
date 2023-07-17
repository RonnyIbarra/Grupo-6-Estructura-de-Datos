/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Registro.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Registro
 ***********************************************************************/

#ifndef REGISTRO_H
#define REGISTRO_H

#include "Fecha.h"
#include <iostream>

class Registro
{
public:
    std::string getDni();
    void setDni(std::string);
    Fecha getFecha();
    void setFecha(Fecha);
    Registro();
    Registro(std::string, Fecha);
    void toString(void);
    
protected:
private:
   std::string dni;
   Fecha fecha;

};

#endif