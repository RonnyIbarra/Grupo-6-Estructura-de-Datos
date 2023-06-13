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

//validaciones de la fecha
bool Validacion::es_bisiesto(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

bool Validacion::validar_fecha(int dia, int mes, int year) {
    int dias_por_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (mes < 1 || mes > 12) {
        return false;
    }
    
    if (es_bisiesto(year) && mes == 2) {
        dias_por_mes[2] = 29;
    }
    
    if (dia < 1 || dia > dias_por_mes[mes]) {
        return false;
    }
    
    return true;
}

//edad   	
Fecha Validacion::validarFecha(void){
	Fecha fecha;
	int diaNacimiento, mesNacimiento, yearNacimiento;
	printf("\n(Ej. 02, 23)\t dia: ");
	diaNacimiento = validarDia();
	printf("(Ej. 02, 12)\t mes: ");
	mesNacimiento = validarMes();
	printf("(Ej. 2000)\tanio: ");
	yearNacimiento = validarYear();
	
	if (validar_fecha(diaNacimiento, mesNacimiento, yearNacimiento)) {
        time_t now = time(0);
    	// Convertir el tiempo en una estructura tm local
    	tm* localTime = localtime(&now);
    
	    // Extraer el día, mes y año
	    int diaActual = localTime->tm_mday;
	    int mesActual = localTime->tm_mon + 1;  // tm_mon es de 0 a 11, por lo que se suma 1
	    int yearActual = localTime->tm_year + 1900;  // tm_year es el número de años transcurridos desde 1900
	    int edad = yearActual - yearNacimiento;
    
	    // Verificar si ya cumplió 18 años
	    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento)) {
	        edad--; // Restar 1 si aún no ha cumplido años completos en el año actual
	    }
    
	    // Validar si es mayor de edad
	    if (edad >= 18) {
	       Fecha fechaNacimiento(diaNacimiento,mesNacimiento,yearNacimiento);
	       return fechaNacimiento;
	    } else {
			return fecha;
	    }
    } else {
		Fecha fechaNoExiste(-1,0,0);
		return fechaNoExiste;
    }
	
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
    return (year>= 1900 && year<= 2100);
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
        char *entrada = new char[5]; // Aumentamos el tamaño del arreglo para permitir el carácter nulo
        char tecla;
        int i = 0;
        
        while (true) {
            tecla = getch();
            
            if (tecla == '\r' && i > 0 && i <= 4) { // Verificamos que se haya ingresado al menos un carácter y máximo cuatro
                std::cout << std::endl;
                break;
            } else if (tecla == '\b' && i > 0) {
                i--;
                std::cout << "\b \b";
                entrada[i] = 0;
            } else if (i < 4 && isdigit(tecla)) {
                entrada[i++] = tecla;
                std::cout << tecla;
            }
        }
        
        entrada[i] = '\0'; // Agregamos el carácter nulo al final de la cadena
        
        int anio = atoi(entrada);
        delete[] entrada;
        
        if (validarYear(anio)) {
            return anio;
        }
        
        std::cout << "Anio no permitido.\nIntente nuevamente: ";
    }
}


int Validacion::validarDia() {
    while (true) {
        char *entrada = new char[3]; // Aumentamos el tamaño del arreglo para permitir el carácter nulo
        char tecla;
        int i = 0;
        
        while (true) {
            tecla = getch();
            
            if (tecla == '\r' && i > 0 && i <= 2) { // Verificamos que se haya ingresado al menos un carácter y máximo dos
                std::cout << std::endl;
                break;
            } else if (tecla == '\b' && i > 0) {
                i--;
                std::cout << "\b \b";
                entrada[i] = 0;
            } else if (i < 2 && isdigit(tecla)) {
                entrada[i++] = tecla;
                std::cout << tecla;
            }
        }
        
        entrada[i] = '\0'; // Agregamos el carácter nulo al final de la cadena
        
        int dia = atoi(entrada);
        delete[] entrada;
        
        if (validarDia(dia)) {
            return dia;
        }
        
        std::cout << "Dia no permitido.\nIntente nuevamente: ";
    }
}


int Validacion::validarMes() {
    while (true) {
        char *entrada = new char[3]; // Aumentamos el tamaño del arreglo para permitir el carácter nulo
        char tecla;
        int i = 0;
        
        while (true) {
            tecla = getch();
            
            if (tecla == '\r' && i > 0 && i <= 2) { // Verificamos que se haya ingresado al menos un carácter y máximo dos
                std::cout << std::endl;
                break;
            } else if (tecla == '\b' && i > 0) {
                i--;
                std::cout << "\b \b";
                entrada[i] = 0;
            } else if (i < 2 && isdigit(tecla)) {
                entrada[i++] = tecla;
                std::cout << tecla;
            }
        }
        
        entrada[i] = '\0'; // Agregamos el carácter nulo al final de la cadena
        
        int mes = atoi(entrada);
        delete[] entrada;
        
        if (validarMes(mes)) {
            return mes;
        }
        
        std::cout << "Mes no permitido.\nIntente nuevamente: ";
    }
}


