/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Registro.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Monday, June 19, 2023 8:24:36 AM
 * Purpose: Declaration of the class Registro
 ***********************************************************************/

#if !defined(__Registro_Personal2_Registro_h)
#define __Registro_Personal2_Registro_h

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