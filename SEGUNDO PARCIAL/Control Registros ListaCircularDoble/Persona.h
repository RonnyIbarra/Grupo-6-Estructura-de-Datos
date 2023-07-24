/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Persona.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Monday, June 19, 2023 8:24:36 AM
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Registro_Personal2_Persona_h)
#define __Registro_Personal2_Persona_h

#include "Fecha.h"
#include <iostream>

class Persona
{
public:
   std::string getDni(void);
   void setDni(std::string );
   std::string getNombre(void);
   void setNombre(std::string );
   std::string getApellido(void);
   void setApellido(std::string);
   Fecha getFecha(void);
   void setFecha(Fecha newFecha);
   Persona();
   Persona(std::string,std::string,std::string,Fecha);
   ~Persona();
   void toString(void);
   void toStringTabla(void);

protected:
private:
   std::string dni;
   std::string nombre;
   std::string apellido;
   Fecha fecha;


};

#endif