/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Module:  Polaca.cpp
 * Author:  Ronny Ibarra, Milena Maldonado, Daniel Guaman
 * Modified: miércoles, 23 de Junio de 2023 8:20:18
 * Purpose: Polaca Inversa
 ***********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "Polaca.h"
#include "Operaciones.h"
#include "Stack.cpp"

using namespace std;

Polaca::Polaca(void)
{
}

bool Polaca::Operador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 's' || c == 'c' || c == 't' || c == 'q');
}


int Polaca::obtenerPrecedencia(char operador) {
    if (operador == '^' || operador == 'r' || operador == 's' || operador == 'c' || operador == 't' || operador == 'q')
        return 3;
    else if (operador == '*' || operador == '/')
        return 2;
    else if (operador == '+' || operador == '-')
        return 1;
    else
        return 0;
}

string Polaca::convertInfijoAPosfijo(const string& expresion) {
    Stack<char> pilaOperadores;
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


string Polaca::convertInfijoAPrefijo(const string& expresion) {
    Stack<char> pilaOperadores;
    string prefijo;
    string infijoRevertido;

    // Revertir la expresión infija
    for (auto it = expresion.rbegin(); it != expresion.rend(); ++it) {
        if (*it == '(')
            infijoRevertido += ')';
        else if (*it == ')')
            infijoRevertido += '(';
        else
            infijoRevertido += *it;
    }

    for (char c : infijoRevertido) {
        if (std::isalnum(c)) {
            prefijo = c + prefijo;
        }
        else if (c == '(') {
            pilaOperadores.push(c);
        }
        else if (c == ')') {
            while (!pilaOperadores.empty() && pilaOperadores.top() != '(') {
                prefijo = pilaOperadores.top() + prefijo;
                pilaOperadores.pop();
            }

            if (!pilaOperadores.empty() && pilaOperadores.top() == '(')
                pilaOperadores.pop();
        }
        else if (Operador(c)) {
            while (!pilaOperadores.empty() && obtenerPrecedencia(pilaOperadores.top()) >= obtenerPrecedencia(c)) {
                prefijo = pilaOperadores.top() + prefijo;
                pilaOperadores.pop();
            }

            pilaOperadores.push(c);
        }
    }

    while (!pilaOperadores.empty()) {
        prefijo = pilaOperadores.top() + prefijo;
        pilaOperadores.pop();
    }

    return prefijo;
} 

double Polaca::evaluarOperacion(double operand1, double operand2, const string& operador) {
    Operaciones op;

    if (operador == "+") {
        return operand1 + operand2;
    }
    else if (operador == "-") {
        return operand1 - operand2;
    }
    else if (operador == "*") {
        return operand1 * operand2;
    }
    else if (operador == "/") {
        return operand1 / operand2;
    }
    else if (operador == "^") {
        return op.potencia(operand1, operand2);
    }
    else if (operador == "s") {
        return op.sin(operand2);
    }
    else if (operador == "c") {
        return op.cos(operand2);
    }
    else if (operador == "t") {
        return op.tan(operand2);
    }
    else if (operador == "r") {
        return op.raizCuadrada(operand2);
    }
    else if (operador == "q") {
        return op.raizCubica(operand2);
    }
    return 0.0;
}

















