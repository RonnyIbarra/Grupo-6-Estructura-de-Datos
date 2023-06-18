/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Fecha.cpp
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Implementation of the class Fecha
 ***********************************************************************/

#include "Fecha.h"
#include <iostream>

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

//toString
void Fecha::toString()
{
    std::cout << dia << "/" << mes << "/" << year;
}

