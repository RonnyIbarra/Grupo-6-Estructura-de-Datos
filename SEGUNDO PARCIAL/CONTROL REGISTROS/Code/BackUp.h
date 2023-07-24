/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  BackUp.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class BackUp
 ***********************************************************************/

#ifndef BACKUP_H
#define BACKUP_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;

class BackUp
{
public:
    BackUp();
    void generarBackUp(void);
    void copyAndReplaceFiles(const string&, const string&);
};

#endif