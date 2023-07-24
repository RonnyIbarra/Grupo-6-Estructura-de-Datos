/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Empleado.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class Empleado
 *******************************************************************************/

#include "Empleado.h"

Empleado::Empleado() : Persona(){
	this->sueldo = 0.0;
}

Empleado::Empleado(string newDni, string newNombre, string newApellido, Fecha newFecha, float newSueldo) : Persona(newDni, newNombre, newApellido, newFecha) {
    this->sueldo = newSueldo;
}

float Empleado::getSueldo() {
    return sueldo;
}

void Empleado::setSueldo(float newSueldo) {
    this->sueldo = newSueldo;
}

void Empleado::toString() {
    printf("\t******************\n              Empleado          \n\t******************\n\n");
	cout << "DNI:              " << dni <<  endl;
	cout << "Nombre:           " << nombre <<  endl;
	cout << "Apellido:         " << apellido << endl;
	cout << "Fecha Nacimiento: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getYear() << endl;
	printf("Sueldo:           $%.2f",sueldo);
    cout <<  endl;
    cout <<  endl;
	
}

void Empleado::toStringTable() {
	printf("%s   \t %s   \t %s   \t %d/%d/%d   	\t%.2f",dni.c_str(),apellido.c_str(),nombre.c_str(),fecha.getDia(),fecha.getMes(),fecha.getYear(),sueldo);
    std::cout <<  std::endl;
}