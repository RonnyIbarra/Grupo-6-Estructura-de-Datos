/***********************************************************************
 * Module:  Operaciones.h
 * Author:  ronny
 * Modified: jueves, 11 de mayo de 2023 16:56:25
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Operaciones_h)
#define __Class_Diagram_1_Operaciones_h

#include "proceso.h"


template<class T>
class Operaciones : public Proceso<T>
{
public:
   Operaciones();
   T calculo(Fraccion<T> obj1, Fraccion<T> obj2) override;

protected:
private:
};

#endif