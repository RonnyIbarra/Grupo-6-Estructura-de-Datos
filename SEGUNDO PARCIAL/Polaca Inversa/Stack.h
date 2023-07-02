/***********************************************************************
 * Module:  Stack.h
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: jueves, 02 de Julio de 2023
 * Purpose: Polaca Inversa
 ***********************************************************************/

#ifndef STACK_H
#define STACK_H

#include "Nodo.h"

template <class T>
class Stack {
private:
    Nodo<T>* topNode;

public:
    Stack();
    ~Stack();
    T top() const;
    void pop();
    bool empty() const;
    void push(const T&);
};

#endif