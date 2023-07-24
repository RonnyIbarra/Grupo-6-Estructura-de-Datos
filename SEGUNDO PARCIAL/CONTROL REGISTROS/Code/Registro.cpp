/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Registro.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class Registro
 *******************************************************************************/
 
#include "Registro.h"

Registro::Registro(){
}

Registro::Registro(string newDni, int newSW, Fecha newEntrada, Fecha newSalida){
	this->dni = newDni;
	this->sw = newSW;
	this->entrada = newEntrada;
	this->salida = newSalida;
}

std::string Registro::getDni(){return dni;}

void Registro::setDni(std::string newDni){this->dni = newDni;}

Fecha Registro::getEntrada(){return entrada;}

void Registro::setEntrada(Fecha newEntrada){this->entrada = newEntrada;}

Fecha Registro::getSalida() { return salida; }

void Registro::setSalida(Fecha newSalida) { this->salida = newSalida; }

int Registro::getSw() { return sw; }

void Registro::setSw(int newSw) { this->sw = newSw; }

void Registro::toString(){
	printf("Entrada: %d/%d/%d   %d:%d:%d \n", entrada.getDia(), entrada.getMes(), entrada.getYear(), entrada.getHora(), entrada.getMinuto(), entrada.getSegundo());
	printf("Salida: %d/%d/%d   %d:%d:%d \n", salida.getDia(), salida.getMes(), salida.getYear(), salida.getHora(), salida.getMinuto(), salida.getSegundo());
}

void Registro::toStringEntrada() {
	printf("Entrada: %d/%d/%d   %d:%d:%d \n", entrada.getDia(), entrada.getMes(), entrada.getYear(), entrada.getHora(), entrada.getMinuto(), entrada.getSegundo());
	printf("Hora de entrada registrada con exito...\n\n");
}

void Registro::toStringSalida() {
	printf("Salida: %d/%d/%d   %d:%d:%d \n", salida.getDia(), salida.getMes(), salida.getYear(), salida.getHora(), salida.getMinuto(), salida.getSegundo());
	printf("Hora de salida registrada con exito...\n\n");
}

void Registro::setEntradaFromSystem() {
	time_t tiempoActual = time(nullptr);
	tm* fechaActual = localtime(&tiempoActual);

	int diaActual = fechaActual->tm_mday;
	int mesActual = fechaActual->tm_mon + 1;
	int anioActual = fechaActual->tm_year + 1900;
	int horaActual = fechaActual->tm_hour;
	int minutosActual = fechaActual->tm_min;
	int segundosActual = fechaActual->tm_sec;
	Fecha _entrada(diaActual, mesActual, anioActual, horaActual, minutosActual, segundosActual);

	this->entrada = _entrada;
}

void Registro::setSalidaFromSystem() {
	time_t tiempoActual = time(nullptr);
	tm* fechaActual = localtime(&tiempoActual);

	int diaActual = fechaActual->tm_mday;
	int mesActual = fechaActual->tm_mon + 1;
	int anioActual = fechaActual->tm_year + 1900;
	int horaActual = fechaActual->tm_hour;
	int minutosActual = fechaActual->tm_min;
	int segundosActual = fechaActual->tm_sec;
	Fecha _salida(diaActual, mesActual, anioActual, horaActual, minutosActual, segundosActual);

	this->salida = _salida;
}