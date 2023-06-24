/***********************************************************************
 * Module:  Polaca.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: miércoles, 23 de Junio de 2023 8:20:18
 * Purpose: Polaca Inversa
 ***********************************************************************/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // Para std::reverse

using namespace std;

// Funciones para verificar si un carácter es un operador válido
bool Operador(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Función para determinar la precedencia de un operador
int obtenerPrecedencia(char operador)
{
    if (operador == '^')
        return 3;
    else if (operador == '*' || operador == '/')
        return 2;
    else if (operador == '+' || operador == '-')
        return 1;
    else
        return 0;
}

// Función para convertir una expresión infija a prefija
string convertirInfijoAPrefijo(const string &expresion)
{
    stack<char> pilaOperadores;
    string prefijo;

    for (int i = expresion.length() - 1; i >= 0; i--)
    {
        char c = expresion[i];

        if (isdigit(c) || isalpha(c))
        {
            prefijo = c + prefijo;
        }
        else if (c == ')')
        {
            pilaOperadores.push(c);
        }
        else if (c == '(')
        {
            while (!pilaOperadores.empty() && pilaOperadores.top() != ')')
            {
                prefijo = pilaOperadores.top() + prefijo;
                pilaOperadores.pop();
            }

            if (!pilaOperadores.empty() && pilaOperadores.top() == ')')
                pilaOperadores.pop();
        }
        else if (Operador(c))
        {
            while (!pilaOperadores.empty() && obtenerPrecedencia(pilaOperadores.top()) >= obtenerPrecedencia(c))
            {
                prefijo = pilaOperadores.top() + prefijo;
                pilaOperadores.pop();
            }

            pilaOperadores.push(c);
        }
    }

    while (!pilaOperadores.empty())
    {
        prefijo = pilaOperadores.top() + prefijo;
        pilaOperadores.pop();
    }

    return prefijo;
}

// Función para convertir una expresión infija a posfija
string convertirInfijoAPosfijo(const string& expresion) {
    stack<char> pilaOperadores;
    string posfijo;

    for (char c : expresion) {
        if (isalnum(c)) {
            posfijo += c;
        }
        else if (c == '(') {
            pilaOperadores.push(c);
        }
        else if (c == ')') {
            while (!pilaOperadores.empty() && pilaOperadores.top() != '(') {
                posfijo += pilaOperadores.top();
                pilaOperadores.pop();
            }

            if (!pilaOperadores.empty() && pilaOperadores.top() == '(')
                pilaOperadores.pop();
        }
        else if (Operador(c)) {
            while (!pilaOperadores.empty() && obtenerPrecedencia(pilaOperadores.top()) >= obtenerPrecedencia(c)) {
                posfijo += pilaOperadores.top();
                pilaOperadores.pop();
            }

            pilaOperadores.push(c);
        }
    }

    while (!pilaOperadores.empty()) {
        posfijo += pilaOperadores.top();
        pilaOperadores.pop();
    }

    return posfijo;
}

