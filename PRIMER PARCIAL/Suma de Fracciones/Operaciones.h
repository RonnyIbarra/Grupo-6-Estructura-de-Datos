/***********************************************************************
 * Module:  Operaciones.h
 * Author:  ronny
 * Modified: jueves, 11 de mayo de 2023 16:56:25
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Operaciones_h)
#define __Class_Diagram_1_Operaciones_h
#include<iostream>
#include "proceso.h"
#include "Fraccion.h"


using namespace std;
class Operaciones : public proceso
{
public:
   Operaciones();
   float suma(void);
   float resta(void);
   Fraccion calculo(Fraccion obj1, Fraccion obj2){
   		
   		Fraccion resultado;
   	
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
   void imprimir(Fraccion fraccion){
   		cout<<fraccion.getNumerador()<<"/"<<fraccion.getDenominador()<<endl;
   }
   
   Fraccion ingresarDatos(){
   	Fraccion resultado;
   	float numerador;
   	float denominador;
   	
	cout<<"Ingrese numerador: ";
   	cin>>numerador;
   	cout<<"Ingrese denominador: ";
   	cin>>denominador;
   	resultado.setNumerador(numerador);
   	
  	resultado.setDenominador(denominador);
   	return resultado;
   }

protected:
private:

};

#endif