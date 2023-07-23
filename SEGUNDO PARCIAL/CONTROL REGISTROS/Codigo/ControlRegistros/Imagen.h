/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  main.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Control Registos 
 ***********************************************************************/
#pragma once
#include <vector>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include "EasyBMP.cpp"

class Imagen {
	// Private section
	public:
	void Imagenes();
	int runIMG();
	void drawImage(std::string imagePath, HDC* console);
	


};