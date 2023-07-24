/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  main.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Control Registos
 ***********************************************************************/

#ifndef GENERAR_H
#define GENERAR_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cmath>
#include "Metrics.h"


class Generar
{
public:
    Generar();
    ~Generar();
    void generarPDF(string);
};

#endif