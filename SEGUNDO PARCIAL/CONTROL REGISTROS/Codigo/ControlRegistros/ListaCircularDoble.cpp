/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  ListaCircularDoble.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class ListaDoble
 *******************************************************************************/
 
#include <iostream>
#include <list>
#include "ListaCircularDoble.h"

using namespace std;

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble() {
    printf("this is a destructor\n");
}

template <typename T>
NodoDoble<T>* ListaCircularDoble<T>::getCabeza() {
    return cabeza;
}

template <typename T>
NodoDoble<T>* ListaCircularDoble<T>::getCola() {
    return cola;
}

template <typename T>
void ListaCircularDoble<T>::insertar(T valor) {
    NodoDoble<T>* nuevoNodo = new NodoDoble<T>(valor);

	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevoNodo;
		this->cola = nuevoNodo;
		this->cabeza->setSiguiente(this->cola);
		this->cabeza->setAnterior(this->cola);
		this->cola->setSiguiente(this->cabeza);
		this->cola->setAnterior(this->cabeza);
	}
	else
	{
		this->cola->setSiguiente(nuevoNodo);
		nuevoNodo->setAnterior(this->cola);
		nuevoNodo->setSiguiente(this->cabeza);
		this->cabeza->setAnterior(nuevoNodo);
		this->cola = nuevoNodo;
	}
}

template <typename T>
void ListaCircularDoble<T>::insertarPorCola(T valor) {
    NodoDoble<T>* nuevoNodo = new NodoDoble<T>(valor);

    if (this->cabeza == nullptr) {
        // Si la lista está vacía, el nuevo nodo será el único nodo en la lista
        this->cabeza = nuevoNodo;
        this->cola = nuevoNodo;
        this->cabeza->setSiguiente(this->cola);
        this->cabeza->setAnterior(this->cola);
        this->cola->setSiguiente(this->cabeza);
        this->cola->setAnterior(this->cabeza);
    }
    else {
        // Si la lista no está vacía, el nuevo nodo se agregará después del nodo de la cola actual
        nuevoNodo->setAnterior(this->cola);
        nuevoNodo->setSiguiente(this->cabeza);
        this->cola->setSiguiente(nuevoNodo);
        this->cabeza->setAnterior(nuevoNodo);
        this->cola = nuevoNodo;
    }
}


template <typename T>
void ListaCircularDoble<T>::eliminar(std::string cedula) {
    if (this->cabeza != nullptr) {
        if (this->cabeza->getDato().getDni() == cedula) {
            NodoDoble<T>* aux = this->cabeza;
            if (this->cabeza->getSiguiente() == this->cabeza) {
                // If there's only one element in the list
                this->cabeza = nullptr;
                this->cola = nullptr;
            }
            else {
                this->cabeza = this->cabeza->getSiguiente();
                this->cabeza->setAnterior(this->cola);
                this->cola->setSiguiente(this->cabeza);
            }
            delete aux;
        }
        else {
            NodoDoble<T>* aux = this->cabeza;
            while (aux->getSiguiente() != this->cabeza) {
                if (aux->getSiguiente()->getDato().getDni() == cedula) {
                    NodoDoble<T>* aux2 = aux->getSiguiente();
                    aux->setSiguiente(aux2->getSiguiente());
                    aux2->getSiguiente()->setAnterior(aux);
                    delete aux2;
                    break;
                }
                aux = aux->getSiguiente();
            }
        }
    }
    else {
        printf("La lista se encuentra vacia\n");
    }
}



//mostar todo
template <typename T>
void ListaCircularDoble<T>::mostrar() {
    if (this->cabeza != nullptr)
	{
		NodoDoble<T>* aux = this->cabeza;
		do
		{
			aux->getDato().toString();
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		std::cout << std::endl;
	}
}

template <typename T>
void ListaCircularDoble<T>::mostrarRegistros(ListaCircularDoble<Empleado>* listaEmpleados) {
    NodoDoble<T>* actual = cabeza;
    NodoDoble<Empleado>* actualPersona = listaEmpleados->getCabeza();

    if (cabeza == nullptr || actualPersona == nullptr) {
        cout << "No se han registrado empleados\n" << endl;
        return;
    }

    do {
        actualPersona->getDato().toString();
        do {
            if (actual->getDato().getDni() == actualPersona->getDato().getDni()) {
                actual->getDato().toString();
                cout << endl;
                actual = actual->getSiguiente();
            }
            else {
                actual = actual->getSiguiente();
            }
        } while (actual != cabeza); 

        actualPersona = actualPersona->getSiguiente();
        actual = cabeza;
    } while (actualPersona != listaEmpleados->getCabeza());
}

template <typename T>
void ListaCircularDoble<T>::mostrarTabla() {
    if (this->cabeza != nullptr)
	{
		NodoDoble<T>* aux = this->cabeza;
		do
		{
			aux->getDato().toStringTable();
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		std::cout << std::endl;
	}
}


//buscar por cedula
template <typename T>
bool ListaCircularDoble<T>::buscar(std::string cedula) {
	if (this->cabeza != nullptr)
	{
		NodoDoble<T>* aux = this->cabeza;
		do
		{
			if (aux->getDato().getDni() == cedula)
			{
				return true;
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}
	return false;
}

//ordenar Radix


template <typename T>
void ListaCircularDoble<T>::ordenarRadixPorApellido() {
    if (this->cabeza == nullptr || this->cabeza->getSiguiente() == this->cabeza) {
        // La lista está vacía o solo tiene un elemento, no es necesario ordenar
        return;
    }

    int numCaracteresMax = 0;
    NodoDoble<T>* aux = this->cabeza;
    do {
        int numCaracteres = aux->getDato().getApellido().length();
        if (numCaracteres > numCaracteresMax) {
            numCaracteresMax = numCaracteres;
        }
        aux = aux->getSiguiente();
    } while (aux != this->cabeza);

    // Llamar a la función recursiva para el primer dígito
    ordenarRadixPorApellidoRecursivo(this->cabeza, numCaracteresMax - 1);
}

template <typename T>
void ListaCircularDoble<T>::ordenarRadixPorApellidoRecursivo(NodoDoble<T>*& cabeza, int posicion) {
    if (posicion < 0) {
        return;
    }

    // Crear listas vacías para cada carácter
    list<NodoDoble<T>*> listas[256];

    // Llenar las listas según el carácter actual en la posición 'posicion'
    NodoDoble<T>* aux = cabeza;
    do {
        int ascii = (int)aux->getDato().getApellido()[posicion];
        listas[ascii].push_back(aux);
        aux = aux->getSiguiente();
    } while (aux != cabeza);

    // Unir las listas en una sola lista ordenada
    NodoDoble<T>* cabezaOrdenada = nullptr;
    NodoDoble<T>* colaOrdenada = nullptr;
    for (int j = 0; j < 256; j++) {
        for (NodoDoble<T>* nodo : listas[j]) {
            if (cabezaOrdenada == nullptr) {
                cabezaOrdenada = nodo;
                colaOrdenada = nodo;
                nodo->setAnterior(nullptr);
                nodo->setSiguiente(nullptr);
            } else {
                colaOrdenada->setSiguiente(nodo);
                nodo->setAnterior(colaOrdenada);
                nodo->setSiguiente(nullptr);
                colaOrdenada = nodo;
            }
        }
    }

    // Unir la lista ordenada con la lista original
    colaOrdenada->setSiguiente(cabezaOrdenada);
    cabezaOrdenada->setAnterior(colaOrdenada);
    cabeza = cabezaOrdenada;

    // Llamar recursivamente para el siguiente dígito
    ordenarRadixPorApellidoRecursivo(cabeza, posicion - 1);
}

template<typename T>
NodoDoble<T>* ListaCircularDoble<T>::buscarNodo(std::string cedula) {
    NodoDoble<T>* actual = cabeza;
    
    while (actual != nullptr) {
        if (actual->getDato().getDni() == cedula) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    
    return nullptr;
}

template<typename T>
NodoDoble<T>* ListaCircularDoble<T>::buscarNodoPorCola(std::string cedula) {
    NodoDoble<T>* actual = cola;
    
    while (actual != nullptr) {
        if (actual->getDato().getDni() == cedula) {
            return actual;
        }
        actual = actual->getAnterior();
    }
    
    return nullptr;
}

