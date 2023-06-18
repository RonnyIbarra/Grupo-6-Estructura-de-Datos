/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  ListaDoble.cpp
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Implementation of the class ListaDoble
 *******************************************************************************/
 
#include <iostream>
#include "ListaDoble.h"

template <typename T>
ListaDoble<T>::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

template <typename T>
Nodo<T>* ListaDoble<T>::getCabeza() {
    return cabeza;
}

template <typename T>
Nodo<T>* ListaDoble<T>::getCola() {
    return cola;
}

template <typename T>
void ListaDoble<T>::insertarPorCabeza(T valor) {
	
	Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        nuevoNodo->setAnterior(cola);
        cola->setSiguiente(nuevoNodo);
        cola = nuevoNodo;
    }
}

template <typename T>
void ListaDoble<T>::insertarPorCola(T valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    
    if (cola == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        nuevoNodo->setAnterior(cola);
        cola->setSiguiente(nuevoNodo);
        cola = nuevoNodo;
    }
}


//buscar por cedula
template <typename T>
bool ListaDoble<T>::buscar(long int cedula) {
    Nodo<T>* actual = cabeza;
    bool encontrado = false;
    
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == cedula) {
            encontrado = true;
            break;
        }
        
        actual = actual->getSiguiente();
    }
    
    if (encontrado) {
        return true;
    } else {
        return false;
    }
}



template <typename T>
void ListaDoble<T>::eliminar(long int cedula) {
    Nodo<T>* actual = cabeza;
    Nodo<T>* anterior = nullptr;
    
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == cedula) {
            if (anterior == nullptr) {
                // Si el nodo a eliminar es el primero de la lista
                cabeza = actual->getSiguiente();
            } else {
                anterior->setSiguiente(actual->getSiguiente());
            }
            
            delete actual;
            return; // Termina la función sin retornar un valor
        }
        
        anterior = actual;
        actual = actual->getSiguiente();
    }
}


//mostar todo
template <typename T>
void ListaDoble<T>::mostrar() {
    Nodo<T>* actual = cabeza;
    
    std::cout << "Contenido de la lista:" << std::endl;
    
    while (actual != nullptr) {
        actual->getDato().toString();
        actual = actual->getSiguiente();
    }
}

template <typename T>
void ListaDoble<T>::mostrarPersonas() {
    Nodo<T>* actual = cabeza;
        
    while (actual != nullptr) {
        actual->getDato().toStringTabla();
        actual = actual->getSiguiente();
    }
}

template <typename T>
void ListaDoble<T>::mostrarRegistros(ListaDoble<Persona>* listaPersonas) {
    Nodo<T>* actual = cabeza;
    Nodo<Persona>* actualPersona = listaPersonas->getCabeza();
    
    std::cout << "Contenido de la lista:" << std::endl;
    
    while (actualPersona != nullptr) {
	    actualPersona->getDato().toString();
			while (actual != nullptr){
	    		if(actual->getDato().getCedula() == actualPersona->getDato().getCedula()){
		        	actual->getDato().toString();
		        	actual = actual->getSiguiente();
				}else{
					actual = actual->getSiguiente();	
				}	
			}
	    actualPersona = actualPersona->getSiguiente();
	    actual = cabeza;
    }
}


template<typename T>
Nodo<T>* ListaDoble<T>::buscarNodo(long int cedula) {
    Nodo<T>* actual = cabeza;
    
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == cedula) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    
    return nullptr;
}

template<typename T>
Nodo<T>* ListaDoble<T>::buscarNodoPorCola(long int cedula) {
    Nodo<T>* actual = cola;
    
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == cedula) {
            return actual;
        }
        actual = actual->getAnterior();
    }
    
    return nullptr;
}

template<typename T>
void ListaDoble<T>::modificar(T dato, T nuevoDato){
	Nodo<T>* nodo = buscarNodo(dato);
    if (nodo != NULL) {
        nodo->setDato(nuevoDato);
        std::cout << "Elemento actualizado correctamente." << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }
}


