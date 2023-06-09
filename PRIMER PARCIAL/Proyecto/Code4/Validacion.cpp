/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  Validacion.h
 * Author:  Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Implementation of the class Validacion
 ***********************************************************************/

#include "Validacion.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <ctime>

Validacion::Validacion(){
}

//float 
float Validacion::ingresarDatosfloat() {
		char *dato=new char[100];
	char c;
	int p=0,x=0,e=1,i=0;
	float n=0.0;
	while((c=getch())!=13){
		if(c>='0' && c<='9'){
			std::cout<<c;;
			dato[i++]=c;
		}
		if(p == 0){
			if(c=='.'){
				printf("%c",c);
				dato[i++]=c;
				p++;
			}
        }
        if(i!=0){
			if(c==8) {
				i--;
				putchar(8);
				putchar(32);
				putchar(8); 
				if(dato[i]=='.'){
					p--;
				}
            }
        }
	}
	dato[i]='\0';
	while(dato[x]!='\0'){
		if(dato[x]=='.'){
			x++;
			while(dato[x]!='\0'){
				n = n + (dato[x] - '0') * pow(0.1,e);           
				e++;
				x++;   
			}
		} else {
			n = (n * 10) + (dato[x]-'0');
			x++;
		}
    }
	std::cout<<"\n";
	return n;
	}

//enteros
int Validacion::ingresarDatosEnteros() {
		char *dato=new char[100];
		char c;
		int i=0;
		int x=0,n=0;
		int result=0;
		while((c=getch())!=13){
			if(c>='0'&& c<='9'){
				std::cout<<c;;
				dato[i++]=c;
			} else {
				if(i!=0){
				if(c==8){
						i--;
						putchar(8);
						putchar(32);
						putchar(8);
					}
				}
			}
		}
		dato[i]='\0';
		while(dato[x]!='\0'){
			n = 10*n + (dato[x]-'0'); 
			x++;
		}
		std::cout<<"\n";
		return n;
	}
	
//cedula

long int Validacion::validarCedula() {
    long int cedula;
    std::cout << "Ingrese el numero de cedula: ";
    cedula = ingresarDatosEnteros();

    std::string cedulaStr = std::to_string(cedula);
    
    if (cedulaStr.length() != 10) {
        return -1; // La longitud de la cédula debe ser 10 dígitos
    }

    int coeficientes[9] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int verificador = cedulaStr[9] - '0';
    int suma = 0;

    for (int i = 0; i < 9; i++) {
        int digito = cedulaStr[i] - '0';
        int producto = coeficientes[i] * digito;

        if (producto >= 10) {
            producto -= 9;
        }

        suma += producto;
    }

int digitoVerificadorCalculado = (suma % 10 == 0) ? 0 : (10 - (suma % 10));

    if (digitoVerificadorCalculado == verificador) {
        return cedula; // Retorna la cédula válida
    } else {
        return -1; // La cédula no es válida
    }
}



//edad   	
Fecha Validacion::ingresarEdad(void){
	Fecha fecha;
	return fecha;
}



//ingresar solo letras
std::string Validacion::ingresarLetras() {
    std::string texto;
    char c;
    
    while ((c = getch()) != 13) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            std::cout << c;
            texto += c;
        } else {
            if (c == 8) {
                if (!texto.empty()) {
                    texto.pop_back();
                    putchar(8);
                    putchar(32);
                    putchar(8);
                }
            }
        }
    }
    
    std::cout << std::endl;
    return texto;
}

//validar aino nacimiento 1900 
bool Validacion::validarYear(int year){
    return (year>= 1900 && year<= 2005);
}
// validar dia 1, 31
bool Validacion::validarDia(int dia){
    return (dia>= 1 && dia<= 31);
}
// validar mes 1, 12
bool Validacion::validarMes(int mes){
    return (mes>= 1 && mes<= 12);
}


//validar cantidad de digitos enteros
int Validacion::validarYear() {
     while (true) {
    char *entrada = new char[4];
    char tecla;
    int i = 0;
    while (true) {
        tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

        if (tecla == '\r' && i == 4){ // si el usuario presiona Enter
          std::cout << std::endl;
          break;
        } else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
            i--;
            std::cout << "\b \b"; // borra el último caracter de la consola
            entrada[i] = 0; // elimina el último caracter de la entrada
        } else if (i<4 && isdigit(tecla)){ //Si el usuario ingresa un dígito (resto de caracteres de la placa)
            entrada[i++] = tecla;
            std::cout << tecla; // muestra el caracter ingresado en la consola
        }
    }
        int entrada1 = atoi(entrada);
        if(validarYear(entrada1)){
            return entrada1;
        };
        delete[] entrada;
        std::cout << "Anio no permitid0.\nIntente nuevamente: ";
    }
}

int Validacion::validarDia() {
     while (true) {
    char *entrada = new char[2];
    char tecla;
    int i = 0;
    while (true) {
        tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

        if (tecla == '\r' && i == 2){ // si el usuario presiona Enter
          std::cout << std::endl;
          break;
        } else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
            i--;
            std::cout << "\b \b"; // borra el último caracter de la consola
            entrada[i] = 0; // elimina el último caracter de la entrada
        } else if (i<2 && isdigit(tecla)){ //Si el usuario ingresa un dígito (resto de caracteres de la placa)
            entrada[i++] = tecla;
            std::cout << tecla; // muestra el caracter ingresado en la consola
        }
    }
        int entrada1 = atoi(entrada);
        if(validarDia(entrada1)){
            return entrada1;
        };
        delete[] entrada;
        std::cout << "Dia no permitid0.\nIntente nuevamente: ";
    }
}

int Validacion::validarMes() {
     while (true) {
    char *entrada = new char[2];
    char tecla;
    int i = 0;
    while (true) {
        tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

        if (tecla == '\r' && i == 2){ // si el usuario presiona Enter
          std::cout << std::endl;
          break;
        } else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
            i--;
            std::cout << "\b \b"; // borra el último caracter de la consola
            entrada[i] = 0; // elimina el último caracter de la entrada
        } else if (i<2 && isdigit(tecla)){ //Si el usuario ingresa un dígito (resto de caracteres de la placa)
            entrada[i++] = tecla;
            std::cout << tecla; // muestra el caracter ingresado en la consola
        }
    }
        int entrada1 = atoi(entrada);
        if(validarMes(entrada1)){
            return entrada1;
        };
        delete[] entrada;
        std::cout << "Mes no permitid0.\nIntente nuevamente: ";
    }
}

