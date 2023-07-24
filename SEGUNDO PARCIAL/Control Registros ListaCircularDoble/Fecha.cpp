/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Fecha.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Monday, June 19, 2023 8:24:36 AM
 * Purpose: Implementation of the class Fecha
 ***********************************************************************/

#include "Fecha.h"
#include <iostream>
using namespace std;

int Fecha::getDia(void)
{
   return dia;
}


void Fecha::setDia(int newDia)
{
   dia = newDia;
}


int Fecha::getMes(void)
{
   return mes;
}


void Fecha::setMes(int newMes)
{
   mes = newMes;
}


int Fecha::getYear(void)
{
   return year;
}

void Fecha::setYear(int newYear)
{
   year = newYear;
}

int Fecha::getHora(void)
{
   return hora;
}


int Fecha::getMinuto(void)
{
   return minuto;
}


int Fecha::getSegundo(void)
{
   return segundo;
}
void Fecha::setHora(int newHora)
{
   hora = newHora;
}
void Fecha::setMinuto(int newMinuto)
{
   minuto = newMinuto;
}
void Fecha::setSegundo(int newSegundo)
{
   segundo = newSegundo;
}




Fecha::Fecha(){
	this->dia = 0;
	this->mes = 0;
	this->year = 0;
}

Fecha::Fecha(int newDia, int newMes, int newYear){
	this-> dia = newDia;
	this-> mes = newMes;
	this-> year = newYear;
}

Fecha::Fecha(int newDia, int newMes, int newYear, int newHora, int newMinuto, int newSegundo){
	this-> dia = newDia;
	this-> mes = newMes;
	this-> year = newYear;
	this-> hora = newHora;
	this-> minuto = newMinuto;
	this->segundo = newSegundo;
}

//toString
void Fecha::toString()
{
    std::cout << dia << "/" << mes << "/" << year;
}

