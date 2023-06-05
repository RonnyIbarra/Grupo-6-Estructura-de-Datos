/***********************************************************************
 * Module:  proceso.h
 * Author:  ronny
 * Modified: miércoles, 10 de mayo de 2023 8:20:18
 * Purpose: Declaration of the class proceso
 ***********************************************************************/
#ifndef __Class_Diagram_1_proceso_h
#define __Class_Diagram_1_proceso_h

#include "Fraccion.h"
#include <iostream>
using namespace std;

class Proceso
{
public:
    virtual float calculo(Fraccion obj1, Fraccion obj2) = 0;

protected:
private:
};

#endif