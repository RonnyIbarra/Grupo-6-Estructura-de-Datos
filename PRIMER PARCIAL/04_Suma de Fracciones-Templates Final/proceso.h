/***********************************************************************
 * Module:  proceso.h
 * Author:  ronny
 * Modified: miércoles, 10 de mayo de 2023 8:20:18
 * Purpose: Declaration of the class proceso
 ***********************************************************************/

#if !defined(__Class_Diagram_1_proceso_h)
#define __Class_Diagram_1_proceso_h

#include "Fraccion.h"
#include <iostream>
using namespace std;

template <typename T>
class Proceso
{
public:
virtual T calculo(Fraccion<T> obj1, Fraccion<T> obj2) = 0;
    

protected:
private:
};

#endif