/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  GestorArchivos.h
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Monday, June 19, 2023 8:24:36 AM
 * Purpose: Declaration of the class GestorArchivos
 ***********************************************************************/

#if !defined(__ProyectoControlRegistro_Nodo_h)
#define __ProyectoControlRegistro_Nodo_h

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