/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  ListaCircularDoble.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/

#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#include "NodoDoble.h"
#include "Empleado.h"
using namespace std;

template <typename T>
class ListaCircularDoble
{
public:
   ListaCircularDoble();
   ~ListaCircularDoble();
   NodoDoble<T>* getCola(void);
   NodoDoble<T>* getCabeza(void);
   void insertar(T);
   void insertarPorCola(T);
   void eliminar(string);
   void mostrar(void);
   void mostrarRegistros(ListaCircularDoble<Empleado>*);
   void mostrarTabla(void);
   bool buscar(string);
   void ordenarRadixPorApellido(void);
   void ordenarRadixPorApellidoRecursivo(NodoDoble<T>*& cabeza, int posicion);
   NodoDoble<T>* buscarNodo(string);
   NodoDoble<T>* buscarNodoPorCola(string);

protected:
private:
   NodoDoble<T>* cabeza;
   NodoDoble<T>* cola;


};

#endif