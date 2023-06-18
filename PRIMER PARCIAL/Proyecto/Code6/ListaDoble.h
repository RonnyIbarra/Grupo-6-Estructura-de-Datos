/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  ListaDoble.h
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class ListaDoble
 *******************************************************************************/
 
#if !defined(__ProyectoControlRegistro_ListasDobles_h)
#define __ProyectoControlRegistro_ListasDobles_h
 
#include <ctime>
#include "OperacionListas.h"
#include "Nodo.h"
#include "Registro.h"
#include "Persona.h"

template <typename T>
class ListaDoble: public OperacionListas<T>{
	private:
    	Nodo<T>* cabeza;
    	Nodo<T>* cola;
	public:
	    ListaDoble();
	    Nodo<T>* getCabeza();
	    Nodo<T>* getCola();
	    void insertarPorCabeza(T);
	    void insertarPorCola(T);
	    void eliminar(long int);
	    void registrarEntrada(T , std::tm&);
	    bool buscar(long int)override;
	    void mostrar()override;
	    void mostrarPersonas();
	    void mostrarRegistros(ListaDoble<Persona>*);
	    Nodo<T>* buscarNodo(long int);
	    Nodo<T>* buscarNodoPorCola(long int);
	    void modificar(T, T);
};

#endif