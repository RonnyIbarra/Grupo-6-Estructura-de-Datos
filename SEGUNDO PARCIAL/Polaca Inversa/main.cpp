/***********************************************************************
 * Module:  main.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: miércoles, 23 de Junio de 2023 8:20:18
 * Purpose: Polaca Inversa
 ***********************************************************************/


#include<iostream>
#include "Polaca.h"
#include "Polaca.cpp"

using namespace std;

int main()
{
    string expresion;

    while (true)
    {
        cout << "Ingrese la expresion matematica: ";
        getline(std::cin, expresion);

       

        string prefijo = convertirInfijoAPrefijo(expresion);
        string posfijo = convertirInfijoAPosfijo(expresion);

        cout << "Expresion original: " << expresion << endl;
        cout << "Expresion en notacion prefija: " << prefijo << endl;
        cout << "Expresion en notacion posfija: " << posfijo << endl;
    }

    return 0;
}
