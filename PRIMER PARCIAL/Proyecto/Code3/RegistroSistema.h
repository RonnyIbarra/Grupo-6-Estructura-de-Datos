/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  RegistroSistema.h
 * Author:   Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class RegistroSistema
 ***********************************************************************/

#if !defined(__ProyectoControlRegistro_RegistroSistema_h)
#define __ProyectoControlRegistro_RegistroSistema_h

class RegistroSistema
{
public:
   int calcularTiempoTrabajado(void);

protected:
private:
   int horaEntrada;
   int horaSalida;

};

#endif