/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  main.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Control Registos
 ********************************************************************/

#include "Generar.h"

using std::complex;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ostringstream;

Generar::Generar()
{
}

Generar::~Generar()
{
}

void Generar::generarPDF(string nombre)
{
    PDF p;
    p.setFont(PDF::HELVETICA_BOLD, 30);
    p.showTextXY(" REGISTROS", 230, 746);
    p.setFont(PDF::HELVETICA, 10);
    p.showTextXY("Grupo 6", 50, 699);
    p.showTextXY("Daniel Guaman, Milena Maldonado, Rony Ibarra", 50, 679);
    p.setFont(PDF::HELVETICA, 12);
    p.showTextXY("Registros Generados:", 50, 546);

    string linea, texto;
    int x = 516; // Cambiamos el valor inicial de 'x' a la posición vertical deseada
    ifstream original("registros.txt");

    while (getline(original, linea))
    {
        p.showTextXY(linea, 50, x);
        x -= 12; // Valor ajustable para controlar el espaciado entre líneas
    }

    original.close();
    string errMsg;

    if (!p.writeToFile(nombre, errMsg))
    {
        cout << errMsg << endl;
    }
    else
    {
        cout << "Se guardo correctamente el archivo PDF" << endl;
    }

    cout << endl;
}