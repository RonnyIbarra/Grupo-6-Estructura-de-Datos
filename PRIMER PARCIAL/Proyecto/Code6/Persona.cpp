/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Persona.cpp
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
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

int Persona::getSw(){return sw;}

void Persona::setSw(int newSw){sw = newSw;}

Fecha Persona::getFechaNacimiento(void){return fechaNacimiento;}

void Persona::setFechaNacimiento(Fecha newFechaNacimiento){fechaNacimiento = newFechaNacimiento;}



Persona::Persona(){
	Fecha newFechaNacimiento;
	this->cedula = 0;
	this-> nombre = "";
	this-> apellido = "";
	this-> sw = 0;
	this-> fechaNacimiento = newFechaNacimiento;
}                         
 
 
Persona::Persona(long int newCedula, string newNombre, string NewApellido, int newSw, Fecha newFechaNacimiento){

	this->cedula = newCedula;
	this-> nombre = newNombre;
	this-> apellido = NewApellido;
	this-> sw = newSw;
	this-> fechaNacimiento = newFechaNacimiento;
}

Persona::~Persona()
{
   // TODO : implement
}

void Persona::toString()
{
	printf("\t******************\n              Persona          \n\t******************\n\n");
	std::cout << "cedula:           " << cedula <<   std::endl;
	std::cout << "nombre:           " << nombre <<   std::endl;
	std::cout << "apellido:         " << apellido <<  std::endl;
	std::cout << "Fecha Nacimiento: " << fechaNacimiento.getDia() << "/" << fechaNacimiento.getMes() << "/" << fechaNacimiento.getYear() << std::endl;
    std::cout <<  std::endl;
    std::cout <<  std::endl;
}

void Persona::toStringTabla(){
	printf("%ld   \t %s   \t %s   \t %d/%d/%d",cedula,nombre.c_str(),apellido.c_str(),fechaNacimiento.getDia(),fechaNacimiento.getMes(),fechaNacimiento.getYear());
	
    std::cout <<  std::endl;
}
