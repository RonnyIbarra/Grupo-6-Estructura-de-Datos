/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Persona.cpp
 * Author:  Det-Pc
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

long int Persona::getCedula(void){return cedula;}

void Persona::setCedula(long int newCedula){cedula = newCedula;}

string Persona::getNombre(void){return nombre;}

void Persona::setNombre(string newNombre){nombre = newNombre;}

string Persona::getApellido(void){return apellido;}

void Persona::setApellido(string newApellido){apellido = newApellido;}

Fecha Persona::getFechaNacimiento(void){return fechaNacimiento;}

void Persona::setFechaNacimiento(Fecha newFechaNacimiento){fechaNacimiento = newFechaNacimiento;}


Persona::Persona(){
	Fecha newFechaNacimiento;
	this->cedula = 0;
	this-> nombre = "";
	this-> apellido = "";
	this-> fechaNacimiento = newFechaNacimiento;
}                         
 
 
Persona::Persona(long int newCedula, string newNombre, string NewApellido, Fecha newFechaNacimiento){

	this->cedula = newCedula;
	this-> nombre = newNombre;
	this-> apellido = NewApellido;
	this-> fechaNacimiento = newFechaNacimiento;
}

Persona::~Persona()
{
   // TODO : implement
}

void Persona::toString()
{
    std::cout << "PERSONA::";
	std::cout << "{" << "cedula:" << cedula << "; " << "nombre:" << nombre << "; " << "apellido:" << apellido << "; " << "fechaNacimiento:";
    fechaNacimiento.toString();
    std::cout << "}" << std::endl;
}
