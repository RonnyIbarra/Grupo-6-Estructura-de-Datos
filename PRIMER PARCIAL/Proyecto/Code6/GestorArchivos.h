/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  GestorArchivos.h
 * Author:  Kevin Amaguaña, Alexander Guaman, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Declaration of the class GestorArchivos
 ***********************************************************************/
 
#if !defined(__ProyectoControlRegistro_GestorArchivos_h)
#define __ProyectoControlRegistro_GestorArchivos_h

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime> // Agregar esta línea para utilizar std::tm
#include <iomanip> // Agregar esta línea para dar formato a la fecha y hora
#include "ListaDoble.h"
#include "Persona.h"
#include "Registro.h"

using namespace std;

template <typename T>
class GestorArchivos {
public:

static void guardarListaPersonaEnArchivo(const char* nombreArchivo, ListaDoble<T>* lista) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        Nodo<T>* actual = lista->getCabeza();
        while (actual != nullptr) {
            archivo << actual->getDato().getCedula() << "," << actual->getDato().getNombre() << "," << actual->getDato().getApellido();
            archivo << "," << actual->getDato().getSw();
            archivo << "," << actual->getDato().getFechaNacimiento().getDia() << "," << actual->getDato().getFechaNacimiento().getMes() << "," << actual->getDato().getFechaNacimiento().getYear() << endl;

            actual = actual->getSiguiente();
        }

        archivo.close();
        cout << endl;
    } else {
        cout << endl << "No se pudo abrir el archivo." << endl;
    }
}

static void guardarListaRegistroEnArchivo(const char* nombreArchivo, ListaDoble<T>* lista) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        Nodo<T>* actual = lista->getCabeza();
        while (actual != nullptr) {
            archivo << actual->getDato().getCedula(); 
            
      		 // Obtener la hora de entrada y salida formateada
            std::tm entrada = actual->getDato().getHoraEntrada();
            std::tm salida = actual->getDato().getHoraSalida();

            archivo << "," << std::put_time(&entrada, "%d-%m-%Y %H:%M:%S") << "," << std::put_time(&salida, "%d-%m-%Y %H:%M:%S") << endl;
            actual = actual->getSiguiente();
        }

        archivo.close();
        cout << endl;
    } else {
        cout << endl << "No se pudo abrir el archivo." << endl;
    }
}



static ListaDoble<T>* cargarListaPersonaDesdeArchivo(const char* nombreArchivo) {
    ListaDoble<T>* lista = new ListaDoble<T>();

    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string cedulaStr, nombre, apellido, swStr, diaStr, mesStr, yearStr;

            if (std::getline(iss, cedulaStr, ',') &&
                std::getline(iss, nombre, ',') &&
                std::getline(iss, apellido, ',') &&
                std::getline(iss, swStr, ',') &&
                std::getline(iss, diaStr, ',') &&
                std::getline(iss, mesStr, ',') &&
                std::getline(iss, yearStr, ',') ) {

                // Convertir a los tipos de datos correctos
                long int cedula = std::stol(cedulaStr);
                int sw = std::stoi(swStr);
                int dia = std::stoi(diaStr);
                int mes = std::stoi(mesStr);
                int year = std::stoi(yearStr);

                // Crear un objeto Persona y establecer sus atributos
                Persona persona;
                persona.setCedula(cedula);
                persona.setNombre(nombre);
                persona.setApellido(apellido);
                persona.setSw(sw);
                persona.setFechaNacimiento(Fecha(dia, mes, year));

                
                // Agregar la persona a la lista
                lista->insertarPorCola(persona);
            }
        }

        archivo.close();
        cout << endl << "La lista se ha cargado correctamente desde el archivo." << endl;
    } else {
        cout << endl << "No se pudo abrir el archivo." << endl;
    }

    return lista;
}

static ListaDoble<T>* cargarListaRegistroDesdeArchivo(const char* nombreArchivo) {
    ListaDoble<T>* lista = new ListaDoble<T>();
    
	ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
    	
        std::string linea;
        while (getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string cedulaStr, entradaStr, salidaStr;

            if (getline(iss, cedulaStr, ',')) {
                long int cedula = std::stol(cedulaStr);
                
                if (getline(iss, entradaStr, ',') && getline(iss, salidaStr)) {
                    std::tm entrada, salida;
                    std::istringstream entradaStream(entradaStr);
                    std::istringstream salidaStream(salidaStr);

                    entradaStream >> std::get_time(&entrada, "%d-%m-%Y %H:%M:%S");
                    salidaStream >> std::get_time(&salida, "%d-%m-%Y %H:%M:%S");

                    Registro registro(cedula, entrada, salida);
                    lista->insertarPorCola(registro); // Insertar el registro en la lista
                }
            }
        }

        archivo.close();
        cout << endl;
    } else {
        cout << endl << "No se pudo abrir el archivo." << endl;
    }
    
    return lista;
}


};

#endif