/***********************************************************************
 * Module:  Operaciones.h
 * Author:  Alexander Guaman, Ronny Ibarra, Kevin Amaguaña
 * Modified: miércoles, 13 de mayo de 2023 19:12:18
 * Purpose: Declaration of the class operaciones
 ***********************************************************************/

#if !defined(OPERACIONES_H)
#define OPERACIONES_H
#include<iostream>
#include "Proceso.h"
#include "Template.hpp"


using namespace std;
class Operaciones : public Proceso
{
public:
   Operaciones();
   float suma(void);
   float resta(void);
   Fraccion<float> calculo(Fraccion<float> obj1, Fraccion<float> obj2){
   		
   		Fraccion<float> resultado;
   	
   		if(obj2.getDenominador()==obj1.getDenominador()){
   			int numerador=0;
   			resultado.setDenominador(obj2.getDenominador());
   			numerador=obj1.getNumerador()+obj2.getNumerador();
   			resultado.setNumerador(numerador);
		}else{
			resultado.setDenominador(obj1.getDenominador()*obj2.getDenominador());
			resultado.setNumerador((obj1.getNumerador()*obj2.getDenominador())+(obj2.getNumerador()*obj1.getDenominador()));
		}
	
   		return resultado;
   }
   void imprimir(Fraccion<float> fraccion){
   		cout<<fraccion.getNumerador()<<"/"<<fraccion.getDenominador()<<endl;
   }
   

protected:
private:

};

#endif