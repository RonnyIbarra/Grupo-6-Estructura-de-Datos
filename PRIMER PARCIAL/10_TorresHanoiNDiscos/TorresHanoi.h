/***********************************************************************
 * UFA-ESPE
 * Module:  TorresHanoi.h
 * Author: Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
  * Created: Sunday, May 28, 2023 7:00:00 PM
 * Purpose: Declaration of the class TorresHanoi
 ***********************************************************************/
#ifndef TORRESHANOI_H
#define TORRESHANOI_H

#include <iostream>
#include <stack>
#include <functional>

using namespace std;

template <typename T>
class TorresDeHanoi {
private:
    stack<T> torreA;
    stack<T> torreB;
    stack<T> torreC;

public:
    void moverDiscos(int, stack<T>&, stack<T>&, stack<T>&, const function<void(T, string, string)>&);
    void resolver(int);
    string nombreTorre(stack<T>&);
};

#endif
