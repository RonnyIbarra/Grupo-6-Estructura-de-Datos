/***********************************************************************
 * UFA-ESPE
 *Module:  Sobrecarga.cpp
 * Author:  Kevin Amaguña, Alexander Guaman, Ronny Ibarra
 * Modified: Wednesday, May 17, 2023 7:43:08 AM
 * Purpose: Implementation of the class Sobrecarga
 ***********************************************************************/

#include "Sobrecarga.h"
#include <iostream>

using namespace std;



int Sobrecarga::getNum1(void)
{
   return num1;
}



void Sobrecarga::setNum1(int newNum1)
{
   num1 = newNum1;
}



Sobrecarga::Sobrecarga()
{
}



Sobrecarga::~Sobrecarga()
{
   // TODO : implement
}

int Sobrecarga::obetenerValor() const{
	return valor;
    }  



bool Sobrecarga::operator>=(const Sobrecarga& other) const {
        return valor >= other.valor;
    }

int Sobrecarga::imprimir( int num1, int num2)
{
	if (num1 >= num2) {
    cout << "El primer numero es mayor o igual que el segundo." << endl;
    } else {
    cout << "El primer numero es menor que el segundo." <<endl;
    }
    return 0;
	
  
}