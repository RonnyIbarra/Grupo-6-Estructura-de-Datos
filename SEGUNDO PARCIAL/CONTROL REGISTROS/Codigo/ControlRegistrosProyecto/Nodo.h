/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Nodo.h
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class GestorArchivos
 ***********************************************************************/

#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo
{
public:
   T getDato(void);
   void setDato(T newDato);
   Nodo* getSiguiente(void);
   void setSiguiente(Nodo* newSiguiente);
   Nodo* getAnterior(void);
   void setAnterior(Nodo* newAnterior);
   Nodo(T);

protected:
private:
   T dato;
   Nodo* siguiente;
   Nodo* anterior;
};

#endif