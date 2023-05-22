/***********************************************************************
 * Module:  proceso.h
 * Author:  ronny
 * Modified: miércoles, 10 de mayo de 2023 8:20:18
 * Purpose: Declaration of the class proceso
 ***********************************************************************/

#if !defined(__Class_Diagram_1_proceso_h)
#define __Class_Diagram_1_proceso_h

#include "Fraccion.h"

class proceso
{
public:
   virtual Fraccion calculo(Fraccion obj1, Fraccion obj2)=0;
   virtual void imprimir(Fraccion fraccion)=0;
   virtual Fraccion ingresarDatos(void)=0;


protected:
private:

};

#endif