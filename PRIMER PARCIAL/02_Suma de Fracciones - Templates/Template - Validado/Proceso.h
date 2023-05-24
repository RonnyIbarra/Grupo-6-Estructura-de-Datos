/***********************************************************************
 * Module:  Proceso.h
 * Author:  Alexander Guaman, Ronny Ibarra, Kevin Amaguaña
 * Modified: miércoles, 13 de mayo de 2023 19:12:18
 * Purpose: Declaration of the class proceso
 ***********************************************************************/

#if !defined(PROCESO_H)
#define PROCESO_h

#include "Template.hpp"

class Proceso
{
public:
   virtual Fraccion<float> calculo(Fraccion<float> obj1, Fraccion<float> obj2)=0;
   virtual void imprimir(Fraccion<float> fraccion)=0;

protected:
private:

};

#endif