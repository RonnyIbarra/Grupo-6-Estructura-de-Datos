/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  Validacion.h
 * Author:  Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class Validacion.h
 ***********************************************************************/
#if !defined(__ProyectoControlRegistro_Validacion_h)
#define __ProyectoControlRegistro_Validacion_h

#include "Fecha.h"
#include <string>

class Validacion {
public:
	float ingresarDatosfloat(void);
   	int ingresarDatosEnteros(void);
   	long int validarCedula(void);
   	bool validarYear(int );
   	int validarYear(void);
   	bool validarDia(int );
   	int validarDia(void);
   	bool validarMes(int );
   	int validarMes(void);
   	Fecha validarFecha(void);
   	bool es_bisiesto(int);
   	bool validar_fecha(int, int, int);
   	std::string ingresarLetras();
   	Validacion();
	
protected:
private:
};

#endif
