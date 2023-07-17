/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  ListaCircularDoble.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/

#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#include "Nodo.h"

template <typename T>
class ListaCircularDoble
{
public:
   ListaCircularDoble();
   ~ListaCircularDoble();
   Nodo<T>* getCola(void);
   Nodo<T>* getCabeza(void);
   void insertar(T);
   void eliminar(std::string);
   void mostrar(void);
   void mostrarTabla(void);
   bool buscar(std::string);
   void ordenarRadixPorApellido(void);
   void ordenarRadixPorApellidoRecursivo(Nodo<T>*, int );
   Nodo<T>* buscarNodo(std::string );
   Nodo<T>* buscarNodoPorCola(std::string );

protected:
private:
   Nodo<T>* cabeza;
   Nodo<T>* cola;


};

#endif