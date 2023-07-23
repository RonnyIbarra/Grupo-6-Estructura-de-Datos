/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Fecha.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#ifndef FECHA_H
#define FECHA_H


class Fecha
{
public:
   int getDia(void);
   void setDia(int );
   int getMes(void);
   void setMes(int );
   int getYear(void);
   void setYear(int );
   int getHora(void);
   void setHora(int);
   int getMinuto(void);
   void setMinuto(int);
   int getSegundo(void);
   void setSegundo(int);   
   Fecha();
   Fecha(int, int, int);
   Fecha(int, int, int, int, int, int);
   void toString(void);

protected:
private:
   int dia;
   int mes;
   int year;
   int hora;
   int minuto;
   int segundo;

};

#endif