#include<iostream>
#include "Operaciones.cpp"
#include "Imprimir.h"

using namespace std;

int main(){
	
    Fraccion<float> f1;
    Fraccion<float> f2;
    Operaciones<float> operacion;
    Validacion valido;
    
    float num1, num2, den1, den2, respuesta;

    cout << "Fraccion 1:" <<endl;
    cout << "Ingrese el numerador: ";
    num1= valido.ingresarDatosfloat();
    cout << "Ingrese el denominador: ";
    den1= valido.ingresarDatosfloat();

    cout << "Fraccion 2:" <<endl;
    cout << "Ingrese el numerador: ";
    num2=valido.ingresarDatosfloat();
    cout << "Ingrese el denominador: ";
    den2=valido.ingresarDatosfloat();

    f1.setNumerador(num1);
    f1.setDenominador(den1);
    f2.setNumerador(num2);
    f2.setDenominador(den2);
    
 

    respuesta = operacion.calculo(f1,f2);

    cout << "La respuesta de la suma de fracciones es: " << respuesta;

    return 0;
}