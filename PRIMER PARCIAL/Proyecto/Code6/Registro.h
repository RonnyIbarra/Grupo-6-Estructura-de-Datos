/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  RegistroSistema.h
 * Author:   Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class Registro
 ***********************************************************************/

#if !defined(__ProyectoControlRegistro_Registro_h)
#define __ProyectoControlRegistro_Registro_h

#include <ctime>

class Registro
{
public:
   long int getCedula();
   void setCedula(long int); 
   const std::tm& getHoraEntrada() const;
   void setHoraEntrada(const std::tm& );
   const std::tm& getHoraSalida() const;
   void setHoraSalida(const std::tm& );
   void calcularTiempoTrabajado(void);
   void setHoraEntradaFromSystem(void);
   void setHoraSalidaFromSystem(void);
   void toString(void);
   void toStringSalida(void);
   void toStringEntrada(void);
   Registro(const long int, const std::tm& , const std::tm& );
   Registro();
   

protected:
private:
	long int cedula;
    std::tm horaEntrada;
    std::tm horaSalida;

};

#endif