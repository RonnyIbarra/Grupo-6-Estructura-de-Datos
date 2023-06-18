/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Fecha.h
 * Author: Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__ProyectoControlRegistro_Fecha_h)
#define __ProyectoControlRegistro_Fecha_h


class Fecha
{
public:
   int getDia(void);
   void setDia(int newDia);
   int getMes(void);
   void setMes(int newMes);
   int getYear(void);
   void setYear(int newYear);
   Fecha();
   Fecha(int, int, int);
   void toString(void);

protected:
private:
   int dia;
   int mes;
   int year;


};

#endif