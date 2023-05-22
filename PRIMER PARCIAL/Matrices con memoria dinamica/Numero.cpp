/***********************************************************************
 * UFA - ESPE
 * Students:  Kevin Amaguaña, Daniel Guaman, Ronny Ibarra
 * Module:  FuncionesMatrices.h
 * NRC: 7999
 ***********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "Numero.h"

using namespace std;

int Numero::getNum(void)
{
   return num;
}

void Numero::setNum(int newNum)
{
   num = newNum;
}

float Numero::getNumF(void)
{
   return numF;
}

void Numero::setNumF(float newNumF)
{
   numF = newNumF;
}

double Numero::getNumD(void)
{
   return numD;
}

void Numero::setNumD(double newNumD)
{
   numD = newNumD;
}

char Numero::getCharacters(void)
{
   return characters;
}

void Numero::setCharacters(char newCharacters)
{
   characters = newCharacters;
}

