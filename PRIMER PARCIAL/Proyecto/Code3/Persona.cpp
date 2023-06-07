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

int Persona::getSw(void){return sw;}

void Persona::setSw(int newSw){sw = newSw;}

string Persona::getNombre(void){return nombre;}

void Persona::setNombre(string newNombre){nombre = newNombre;}

string Persona::getApellido(void){return apellido;}

void Persona::setApellido(string newApellido){apellido = newApellido;}

Fecha Persona::getFechaNacimiento(void){return fechaNacimiento;}

void Persona::setFechaNacimiento(Fecha newFechaNacimiento){fechaNacimiento = newFechaNacimiento;}

Registro Persona::getRegistro(void){return registro;}

void Persona::setRegistro(Registro newRegistro){this->registro = newRegistro;}


Persona::Persona(){
	Fecha newFechaNacimiento;
	Registro newRegistro;
	this->cedula = 0;
	this-> nombre = "";
	this-> apellido = "";
	this-> sw=0;
	this-> fechaNacimiento = newFechaNacimiento;
	this->registro = newRegistro;
}                         
 
 
Persona::Persona(long int newCedula, string newNombre, string NewApellido, int newSw, Fecha newFechaNacimiento, Registro newRegistro){

	this->cedula = newCedula;
	this-> nombre = newNombre;
	this-> apellido = NewApellido;
	this->sw = newSw;
	this-> fechaNacimiento = newFechaNacimiento;
	this->registro = newRegistro;
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
    std::cout << "; " ;
    registro.toString();
    std::cout << "}" << std::endl;
}
