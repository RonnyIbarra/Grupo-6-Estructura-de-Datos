/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Arbol.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class Arbol
 *******************************************************************************/

#include "Arbol.h"


/**
 * Establece el valor de la variable privada arbol al valor del parámetro _arbol.
 * 
 * @param _arbol El nodo raíz del árbol.
 */
template <typename T>
void Arbol<T>::setArbol(Nodo<T> *_arbol)
{
    arbol = _arbol;
}

/**
 * Devuelve la raíz del árbol.
 * 
 * @return El nodo raíz del árbol.
 */
template <typename T>
Nodo<T> *Arbol<T>::getArbol()
{
    return arbol;
}

/**
 * Crea un nuevo nodo con el valor del parámetro.
 * 
 * @param dato El valor del nodo
 * 
 * @return Un puntero a un objeto Nodo.
 */
template <typename T>
Nodo<T> *Arbol<T>::crearNodo(T dato)
{
    Nodo<T> *nuevoNodo = new Nodo<T>();
    nuevoNodo->setValor(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 * 
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
template <typename T>
void Arbol<T>::insertarNodo(Nodo<T>*& arbol, T dato)
{
    if (arbol == NULL)
    {
        Nodo<T> *nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else
    {
        string raiz = arbol->getValor().getDni();
        if (dato.getDni() < raiz)
        {
            insertarNodo(arbol->getIzquierda(), dato);
        }
        else
        {
            insertarNodo(arbol->getDerecha(), dato);
        }
    }
}

/**
 * Mostrar el contenido del arbol
 *
 * @param dato El valor del nodo
 * @param contador
 */
template <typename T>
void Arbol<T>::mostrar(Nodo<T> *arbol, int contador)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrar(arbol->getDerecha(), contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "  ";
        }
        cout << arbol->getValor() << endl;
        mostrar(arbol->getIzquierda(), contador + 1);
    }
}

/**
 * Buscar un nodo con el valor del parámetro.
 *
 * @param dato El valor del nodo
 * @param string
 */

template <typename T>
bool Arbol<T>::buscar(Nodo<T>* arbol, string &dni) {
    if (arbol == NULL) {
        return false; // Elemento no encontrado
    }
    else if (arbol->getValor().getDni() == dni) {
        return true; // Elemento encontrado
    }
    else if (dni < arbol->getValor().getDni()) {
        return buscar(arbol->getIzquierda(), dni);
    }
    else {
        return buscar(arbol->getDerecha(), dni);
    }
}

/**
 * Buscar un nodo con el valor del parámetro y retonar un objeto.
 *
 * @param dato El valor del nodo
 * @param string DNI
 *
 * @return el valor del objeto Nodo.
 */
template <typename T>
T Arbol<T>::buscarNodo(Nodo<T>* arbol, string& dni) {
    if (arbol == NULL) {
        return T();
    }
    else if (arbol->getValor().getDni() == dni) {
        // Devuelve el objeto Empleado encontrado
        return arbol->getValor();
    }
    else if (dni < arbol->getValor().getDni()) {
        // Busca en el subárbol izquierdo
        return buscarNodo(arbol->getIzquierda(), dni);
    }
    else {
        // Busca en el subárbol derecho
        return buscarNodo(arbol->getDerecha(), dni);
    }
}

/**
 * Eliminar un nodo con el valor del parámetro.
 *
 * @param dato El valor del nodo
 * @param string
 */
template <typename T>
Nodo<T>* Arbol<T>::eliminarNodo(Nodo<T>* raiz, string dato) {
    if (raiz == NULL)
        return raiz;

    if (dato < raiz->getValor().getDni())
        raiz->setIzquierda(eliminarNodo(raiz->getIzquierda(), dato));
    else if (dato > raiz->getValor().getDni())
        raiz->setDerecha(eliminarNodo(raiz->getDerecha(), dato));
    else {
        if (raiz->getIzquierda() == NULL) {
            Nodo<T>* temp = raiz->getDerecha();
            delete raiz;
            return temp;
        }
        else if (raiz->getDerecha() == NULL) {
            Nodo<T>* temp = raiz->getIzquierda();
            delete raiz;
            return temp;
        }
        else {
            // Encontrar el nodo mínimo en el subárbol derecho
            Nodo<T>* temp = raiz->getDerecha();
            while (temp->getIzquierda()) {
                temp = temp->getIzquierda();
            }

            // Copiar el valor del nodo mínimo en el nodo actual
            raiz->setValor(temp->getValor());

            // Eliminar el nodo mínimo del subárbol derecho
            raiz->setDerecha(eliminarNodo(raiz->getDerecha(), temp->getValor().getDni()));
        }
    }
    return raiz;
}




//RECORRIDO EN PREORDEN
/**
 * *|CURSOR_MARCADOR|*
 *
 * @param arbol es la raiz del arbol
 *
 * @return el valor del nodo.
 */
template <typename T>
void Arbol<T>::preOrden(Nodo<T>* arbol)
{
    if (arbol == NULL)
    {
        return;
        cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        arbol->getValor().toString();
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}

/**
 * Recorrido inOrden.
 *
 * @param arbol Un puntero al nodo de la raíz.
 *
 * @return Dato entero del nodo.
 */
template <typename T>
void Arbol<T>::inOrden(Nodo<T>* arbol)
{
    if (arbol == NULL)
    {
        return;
        cout << "No se encuentran datos en el arbol" << endl;
        cout << "El arbol se encuentra vacio" << endl;
    }
    else
    {
        inOrden(arbol->getIzquierda());
        cout << arbol->getValor().getDni() << " -> ";
        cout << arbol->getValor().getApellido() << " " << arbol->getValor().getNombre() << endl;
        inOrden(arbol->getDerecha());
    }
}

/**
 * Imprime el árbol en orden posterior.
 *
 * @param arbol El nodo raíz del árbol.
 *
 * @return Dato entero del nodo.
 */
template <typename T>
void Arbol<T>::postOrden(Nodo<T>* arbol) {

    if (arbol == NULL)
    {
        return;
        cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        postOrden(arbol->getIzquierda());
        postOrden(arbol->getDerecha());
        arbol->getValor().toString();
    }
}

