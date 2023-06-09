/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  OperacionListas.h
 * Author:  Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class OperacionListas
 ***********************************************************************/

#if !defined(__ProyectoControlRegistro_OperacionListas_h)
#define __ProyectoControlRegistro_OperacionListas_h

template <typename T>
class OperacionListas
{
public:
   virtual bool buscar(long int)=0;
   virtual void mostrar(void)=0;

protected:
private:

};

#endif