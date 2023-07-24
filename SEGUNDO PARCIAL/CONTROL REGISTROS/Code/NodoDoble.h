/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  NodoDoble.h
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class NodoDoble
 ***********************************************************************/

#ifndef NODODOBLE_H
#define NODODOBLE_H

template <typename T>
class NodoDoble
{
public:
   T getDato(void);
   void setDato(T newDato);
   NodoDoble* getSiguiente(void);
   void setSiguiente(NodoDoble* newSiguiente);
   NodoDoble* getAnterior(void);
   void setAnterior(NodoDoble* newAnterior);
   NodoDoble(T);

protected:
private:
   T dato;
   NodoDoble* siguiente;
   NodoDoble* anterior;
};

#endif