/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Registro.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Monday, June 19, 2023 8:24:36 AM
 * Purpose: Implementation of the class Registro
 *******************************************************************************/
 
#include "Registro.h"

Registro::Registro(){
}

Registro::Registro(std::string newDni, Fecha newFecha){
	this->dni = newDni;
	this->fecha = newFecha;
}

std::string Registro::getDni(){return dni;}

void Registro::setDni(std::string newDni){this->dni = newDni;}

Fecha Registro::getFecha(){return fecha;}

void Registro::setFecha(Fecha newFecha){this->fecha = newFecha;}
