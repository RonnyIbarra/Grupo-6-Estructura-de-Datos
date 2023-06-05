/***********************************************************************
 * Module:  Fraccion.h
 * Author:  ronny
 * Modified: miércoles, 10 de mayo de 2023 8:20:18
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#ifndef __Class_Diagram_1_Fraccion_h
#define __Class_Diagram_1_Fraccion_h

class Fraccion
{
public:
    int getNumerador();
    void setNumerador(int newNumerador);
    int getDenominador();
    void setDenominador(int newDenominador);
    Fraccion(int num, int den);
    Fraccion();
    ~Fraccion();

protected:
private:
    int numerador;
    int denominador;
};

#endif