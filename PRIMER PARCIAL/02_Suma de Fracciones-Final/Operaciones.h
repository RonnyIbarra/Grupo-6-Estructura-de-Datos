/***********************************************************************
 * Module:  Operaciones.h
 * Author:  ronny
 * Modified: jueves, 11 de mayo de 2023 16:56:25
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#ifndef __Class_Diagram_1_Operaciones_h
#define __Class_Diagram_1_Operaciones_h

#include "proceso.h"

class Operaciones : public Proceso
{
public:
    Operaciones();
    float calculo(Fraccion obj1, Fraccion obj2) override;

protected:
private:
};

#endif