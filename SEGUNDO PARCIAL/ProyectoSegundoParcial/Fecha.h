/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Fecha.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Monday, June 19, 2023 8:24:36 AM
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__ProyectoControlRegistro_Fecha_h)
#define __ProyectoControlRegistro_Fecha_h


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