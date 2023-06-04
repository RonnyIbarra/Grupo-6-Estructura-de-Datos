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

//cedula existente
bool Validacion::validarCedulaExistente(void){
	
	return 0;
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