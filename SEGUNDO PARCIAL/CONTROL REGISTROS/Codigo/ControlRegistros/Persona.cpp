/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Persona.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class Persona
 *******************************************************************************/

#include "Persona.h"

Persona::Persona(){
    Fecha newFecha;
    this->dni = "";
    this->nombre = "";
    this->apellido = "";
    this->fecha = newFecha;
}

Persona::Persona(string newDni, string newNombre, string newApellido, Fecha newFecha) {
    this->dni = newDni;
    this->nombre = newNombre;
    this->apellido = newApellido;
    this->fecha = newFecha;
}

string Persona::getDni() {
    return dni;
}

string Persona::getNombre() {
    return nombre;
}

string Persona::getApellido() {
    return apellido;
}

Fecha Persona::getFecha() {
    return fecha;
}

void Persona::setDni(string newDni) {
    this->dni = newDni;
}

void Persona::setNombre(string newNombre) {
    this->nombre = newNombre;
}

void Persona::setApellido(string newApellido) {
    this->apellido = newApellido;
}

void Persona::setFecha(Fecha newFecha) {
    this->fecha = newFecha;
}
