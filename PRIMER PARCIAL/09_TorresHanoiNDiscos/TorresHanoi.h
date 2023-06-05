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
    void moverDiscos(int , stack<T>& , stack<T>& , stack<T>&, const function<void(T, string, string)>& );
	void resolver(int );
	string nombreTorre(stack<T>& );   
    
};

template <typename T>
void TorresDeHanoi<T>::moverDiscos(int n, stack<T>& origen, stack<T>& destino, stack<T>& auxiliar, const function<void(T, string, string)>& mover) {
         if (n > 0) {
            // Mover n-1 discos de origen a auxiliar, usando destino como torre auxiliar
            moverDiscos(n - 1, origen, auxiliar, destino, mover);

            // Mover el disco superior de origen a destino
            T disco = origen.top();
            origen.pop();
            destino.push(disco);
            
            mover(disco, nombreTorre(origen), nombreTorre(destino));
            cout << endl;
            
            // Mover n-1 discos de auxiliar a destino, usando origen como torre auxiliar
            moverDiscos(n - 1, auxiliar, destino, origen, mover);
        }
    }


template <typename T>  
void TorresDeHanoi<T>::resolver(int numDiscos) {
       if (numDiscos <= 0) {
            cout << "El número de discos debe ser mayor que cero." << endl;
            return;
        }

        // Inicializar torre A con discos
        for (int i = numDiscos; i > 0; --i) {
            torreA.push(i);
        }

        auto mover = [](T disco, string origen, string destino) {
            cout << "Mover disco " << disco << " de " << origen << " a " << destino << endl;
        };

        moverDiscos(numDiscos, torreA, torreC, torreB, mover);
    }


template <typename T>
string TorresDeHanoi<T>::nombreTorre(std::stack<T>& torre) {
        if (&torre == &torreA)
            return "A";
        else if (&torre == &torreB)
            return "B";
        else if (&torre == &torreC)
            return "C";
        else
            return "Desconocida";
}

#endif
