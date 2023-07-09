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

using namespace std;

Polaca::Polaca(void)
{
}


bool Polaca::isOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Polaca::isFuncion(char c) {
    return c == 's' || c == 'c' || c == 't'  || c == 'r' || c == 'q';
}

int Polaca::obtenerPrecedencia(string operador) {
    if (operador == "s" || operador == "c" || operador == "t")
        return 4;
    else if (operador == "^" || operador == "r" || operador == "q")
        return 3;
    else if (operador == "*" || operador == "/")
        return 2;
    else if (operador == "+" || operador == "-")
        return 1;
    else
        return 0;
}


Pila<string> Polaca::convertirExpresionInfijaAPrefija(string expresionInfija){
    Pila<string> pilaSalida;
    Pila<string> pilaOperadores;
    string infijoRevertido;

    for (auto it = expresionInfija.rbegin(); it != expresionInfija.rend(); ++it) {
        if (*it == '(')
            infijoRevertido += ')';
        else if (*it == ')')
            infijoRevertido += '(';
        else
            infijoRevertido += *it;
    }

    string numero;
    for (char c : infijoRevertido) {
        if (std::isdigit(c) || c == '.') {
            numero = c + numero; // Agregar el dígito o el punto al inicio del número
        }
        else {
            if (!numero.empty()) {
                pilaSalida.push(numero);
                numero.clear(); // Limpiar la variable para el siguiente número
            }
            if (c == '(') {
                while (!pilaOperadores.empty() && pilaOperadores.top() != ")") {
                    pilaSalida.push(pilaOperadores.top());
                    pilaOperadores.pop();
                }
                // Quitar el paréntesis de cierre de la pila de operadores
                if (!pilaOperadores.empty())
                    pilaOperadores.pop();
            }
            else {
                while (!pilaOperadores.empty() && obtenerPrecedencia(string(1, c)) <= obtenerPrecedencia(pilaOperadores.top())) {
                    pilaSalida.push(pilaOperadores.top());
                    pilaOperadores.pop();
                } 
                pilaOperadores.push(string(1, c));
            }
        }
        
    }
    if (!numero.empty()) {
        // Agregar el último número construido (si existe) a la pila de operandos
        pilaSalida.push(numero);
    }

    while (!pilaOperadores.empty()) {
        pilaSalida.push(pilaOperadores.top());
        pilaOperadores.pop();
    }

    return pilaSalida;
}


Pila<string> Polaca::convertirExpresionInfijaAPosfija(string expresionInfija) {
    Pila<string> pilaPosfija;
    Pila<string> pilaOperadores;
    string numero;

    for (char c : expresionInfija) {
        if (isdigit(c) || c == '.') {
            numero += c;
        }
        else {
            if (!numero.empty()) {
                pilaPosfija.push(numero);
                numero.clear();
            }
            if (c == '(') {
                pilaOperadores.push(string(1, c));
            }
            else if (c == ')') {
                while (!pilaOperadores.empty() && pilaOperadores.top() != "(") {
                    pilaPosfija.push(pilaOperadores.top());
                    pilaOperadores.pop();
                }
                if (!pilaOperadores.empty() && pilaOperadores.top() == "(") {
                    pilaOperadores.pop();
                }
            }
            else {
                while (!pilaOperadores.empty() && obtenerPrecedencia(string(1, c)) <= obtenerPrecedencia(pilaOperadores.top())) {
                    pilaPosfija.push(pilaOperadores.top());
                    pilaOperadores.pop();
                }
                pilaOperadores.push(string(1, c));
            }
        }
    }

    if (!numero.empty()) {
        // Agregar el último número construido (si existe) a la pila de operandos
        pilaPosfija.push(numero);
    }

    while (!pilaOperadores.empty()) {
        pilaPosfija.push(pilaOperadores.top());
        pilaOperadores.pop();
    }

    Pila<string> pilaSalida;
    while (!pilaPosfija.empty()) {
        pilaSalida.push(pilaPosfija.top());
        pilaPosfija.pop();
    }

    return pilaSalida;
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
