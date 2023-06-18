/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Persona.h
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__ProyectoControlRegistro_Persona_h)
#define __ProyectoControlRegistro_Persona_h

#include <string>
#include "Fecha.h"

using namespace std;

class Persona
{
public:
   long int getCedula(void);
   void setCedula(long int newCedula);
   string getNombre(void);
   void setNombre(string newNombre);
   string getApellido(void);
   void setApellido(string newApellido);
   int getSw();
   void setSw(int);  
   Fecha getFechaNacimiento(void);
   void setFechaNacimiento(Fecha newFechaNacimiento);
   Persona();
   Persona(long int , string , string , int, Fecha);
   ~Persona();
   void toString(void);
   void toStringTabla(void);

protected:
private:
   long int cedula;
   string nombre;
   string apellido;
   int sw;
   Fecha fechaNacimiento;

};

#endif