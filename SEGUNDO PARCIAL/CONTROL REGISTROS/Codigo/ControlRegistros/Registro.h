/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Registro.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Registro
 ***********************************************************************/

#ifndef REGISTRO_H
#define REGISTRO_H

#include "Fecha.h"
#include <iostream>
#include <ctime>

using namespace std;

class Registro
{
public:
    string getDni();
    void setDni(string);
    Fecha getEntrada();
    void setEntrada(Fecha);
    void setEntradaFromSystem();
    Fecha getSalida();
    void setSalida(Fecha);
    void setSalidaFromSystem();
    int getSw();
    void setSw(int);
    Registro();
    Registro(string, int, Fecha, Fecha);
    void toString(void);
    void toStringEntrada(void);
    void toStringSalida(void);
    
protected:
private:
   string dni;
   int sw;
   Fecha entrada;
   Fecha salida;

};

#endif