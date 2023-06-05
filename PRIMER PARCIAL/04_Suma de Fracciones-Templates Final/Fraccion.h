/***********************************************************************
 * Module:  Fraccion.h
 * Author:  ronny
 * Modified: miércoles, 10 de mayo de 2023 8:20:18
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Fraccion_h)
#define __Class_Diagram_1_Fraccion_h

template<class T>
class Fraccion
{
public:
   T getNumerador();
   void setNumerador(T newNumerador);
   T getDenominador();
   void setDenominador(T newDenominador);
   Fraccion(T num, T den);
   
   
   Fraccion();
  
   ~Fraccion();

protected:
private:
   T numerador;
   T denominador;
};

#endif