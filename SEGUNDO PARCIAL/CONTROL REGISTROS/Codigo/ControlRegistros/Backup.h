/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  main.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Control Registos 
 ***********************************************************************/
#include <iostream>
#include <ctime>
#include <fstream>

class Backup
{
public:
    Backup();
    ~Backup();
    void generarBackup();
};
