#include"Sobrecarga.h"
#include <iostream>

using namespace std;

template<typename T>
T Sobrecarga<T>::getNum1()
{
    return num1;
}

template<typename T>
void Sobrecarga<T>::setNum1(T newNum1)
{
    num1 = newNum1;
}

template<typename T>
Sobrecarga<T>::Sobrecarga()
{
}

template<typename T>
Sobrecarga<T>::~Sobrecarga()
{
    // TODO: implement
}

template<typename T>
T Sobrecarga<T>::obtenerValor() const
{
    return valor;
}

template<typename T>
bool Sobrecarga<T>::operator>=(const Sobrecarga& other) const
{
    return valor >= other.valor;
}

template<typename T>
int Sobrecarga<T>::imprimir(T num1, T num2)
{
    if (num1 >= num2) {
        cout << "El primer numero es mayor o igual que el segundo." << endl;
    } else {
        cout << "El primer numero es menor que el segundo." << endl;
    }
    return 0;
}
