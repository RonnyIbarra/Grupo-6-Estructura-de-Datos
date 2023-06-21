/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  ListaCircularDoble.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Monday, June 19, 2023 8:24:36 AM
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/

#if !defined(__Registro_Personal2_ListaCircularDoble_h)
#define __Registro_Personal2_ListaCircularDoble_h

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
   bool buscar(std::string);
   void ordenarRadixPorApellido(void);
   Nodo<T>* buscarNodo(std::string );
   Nodo<T>* buscarNodoPorCola(std::string );

protected:
private:
   Nodo<T>* cabeza;
   Nodo<T>* cola;


};

#endif