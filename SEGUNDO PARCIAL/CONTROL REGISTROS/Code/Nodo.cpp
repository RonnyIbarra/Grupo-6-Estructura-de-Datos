/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Nodo.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"
template <typename T>
Nodo<T>::Nodo() {
    Empleado empleado;
    this-> valor = empleado;
}


/**
 * Establece el valor del nodo.
 * 
 * @param _dato El valor que se almacenará en el nodo.
 */
template <typename T>
void Nodo<T>::setValor(T _dato)
{
    valor = _dato;
}

/**
 * 
 * @param _izquierda El nodo que se establecerá como el hijo izquierdo del nodo actual.
 */
template <typename T>
void Nodo<T>::setIzquierda(Nodo<T> *_izquierda)
{
    izquierda = _izquierda;
}

/**
 * 
 * @param _derecha El nodo que se establecerá como el nodo derecho.
 */
template <typename T>
void Nodo<T>::setDerecha(Nodo<T> *_derecha)
{
    derecha = _derecha;
}

/**
 * Devuelve el valor del nodo.
 * 
 * @return El valor del nodo.
 */
template <typename T>
T Nodo<T>::getValor()
{
    return valor;
}

/**
 * Devuelve el nodo izquierdo.
 * 
 * @return Un puntero al nodo izquierdo.
 */
template <typename T>
Nodo<T>*& Nodo<T>::getIzquierda()
{
    return izquierda;
}

/**
 * Devuelve el nodo derecho.
 * 
 * @return Una referencia al nodo derecho.
 */
template <typename T>
Nodo<T>*& Nodo<T>::getDerecha()
{
    return derecha;
}

/**
 * Devuelve el nodo derecho.
 *
 * @return Una referencia al nodo derecho.
 */
template <typename T>
Nodo<T>*& Nodo<T>::getNivel()
{
    return nivel;
}