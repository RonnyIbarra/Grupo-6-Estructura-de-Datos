/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Persona.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Monday, June 19, 2023 8:24:36 AM
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include <iostream>
#include <string>
#include "Persona.h"


using namespace std;

std::string Persona::getDni(void){return dni;}

void Persona::setDni(std::string newDni){dni = newDni;}

string Persona::getNombre(void){return nombre;}

void Persona::setNombre(string newNombre){nombre = newNombre;}

string Persona::getApellido(void){return apellido;}

void Persona::setApellido(string newApellido){apellido = newApellido;}


Fecha Persona::getFecha(void){return fecha;}

void Persona::setFecha(Fecha newFecha){fecha = newFecha;}



Persona::Persona(){
	Fecha newFecha;
	this->dni = "";
	this-> nombre = "";
	this-> apellido = "";
	this-> fecha = newFecha;
}                         
 
 
Persona::Persona(string newDni, string newNombre, string NewApellido, Fecha newFecha){

	this->dni = newDni;
	this-> nombre = newNombre;
	this-> apellido = NewApellido;
	this-> fecha = newFecha;
}

Persona::~Persona()
{
   // TODO : implement
}

void Persona::toString()
{
	printf("\t******************\n              Persona          \n\t******************\n\n");
	std::cout << "dni:              " << dni <<   std::endl;
	std::cout << "nombre:           " << nombre <<   std::endl;
	std::cout << "apellido:         " << apellido <<  std::endl;
	std::cout << "Fecha Nacimiento: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getYear() << std::endl;
    std::cout <<  std::endl;
    std::cout <<  std::endl;
}

void Persona::toStringTabla()
{
	printf("%s   \t %s   \t %s   \t %d/%d/%d",dni.c_str(),apellido.c_str(),nombre.c_str(),fecha.getDia(),fecha.getMes(),fecha.getYear());
    std::cout <<  std::endl;
}


