/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Persona.h
 * Author:  Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__ProyectoControlRegistro_Persona_h)
#define __ProyectoControlRegistro_Persona_h

#include <string>
#include "Fecha.h"
#include "Registro.h"

using namespace std;

class Persona
{
public:
   long int getCedula(void);
   void setCedula(long int newCedula);
   int getSw(void);
   void setSw(int newSw);
   string getNombre(void);
   void setNombre(string newNombre);
   string getApellido(void);
   void setApellido(string newApellido);
   Fecha getFechaNacimiento(void);
   void setFechaNacimiento(Fecha newFechaNacimiento);
   Registro getRegistro(void);
   void setRegistro(Registro newRegistro);
   Persona();
   Persona(long int , string , string ,int , Fecha, Registro);
   ~Persona();
   void toString(void);

protected:
private:
   long int cedula;
   string nombre;
   string apellido;
   int sw;
   Fecha fechaNacimiento;
   Registro registro;

};

#endif