/***********************************************************************
 * Module:  Stack.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#include "Stack.h"

template <typename T>
Stack<T>::Stack() {
    topNode = nullptr;
} 

template <typename T>
Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
T Stack<T>::top() const {
    if (empty()) {
        throw std::runtime_error("La pila está vacía");
    }
    return topNode->getData();
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::runtime_error("La pila está vacía");
    }
    Nodo<T>* temp = topNode;
    topNode = topNode->getNext();
    delete temp;
}

template <typename T>
bool Stack<T>::empty() const {
    return topNode == nullptr;
}

template <typename T>
void Stack<T>::push(const T& value) {
    Nodo<T>* newNode = new Nodo<T>(value);
    newNode->setNext(topNode);
    topNode = newNode;
}

