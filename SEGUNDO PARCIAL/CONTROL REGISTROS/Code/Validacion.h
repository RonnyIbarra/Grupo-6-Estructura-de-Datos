/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  Validacion.h
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Validacion.h
 ***********************************************************************/

#ifndef VALIDACION_H
#define VALIDACION_H

#include "Fecha.h"
#include <string>

class Validacion {
public:
	float ingresarDatosfloat(void);
   	int ingresarDatosEnteros(void);
   	std::string ingresarDatosEnterosString(void);
   	std::string validarDni(void);
   	bool validarYear(int );
   	int validarYear(void);
   	bool validarDia(int );
   	int validarDia(void);
   	bool validarMes(int );
   	int validarMes(void);
   	Fecha validarFecha(void);
   	bool es_bisiesto(int);
   	bool validar_fecha(int, int, int);
   	float validarSueldo(void);
   	std::string ingresarLetras();
   	Validacion();
	
protected:
private:
};

#endif
