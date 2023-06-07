/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  GestorArchivos.h
 * Author:  Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
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
#include "Fecha.h"
#include "Persona.h"

using namespace std;

template <typename T>
class GestorArchivos {
public:

static void guardarListaEnArchivo(const char* nombreArchivo, ListaDoble<T>* lista) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        Nodo<T>* actual = lista->getCabeza();
        while (actual != nullptr) {
            archivo << actual->getDato().getCedula() << "," << actual->getDato().getNombre() << "," << actual->getDato().getApellido();
            archivo << "," << actual->getDato().getSw();
            archivo << "," << actual->getDato().getFechaNacimiento().getDia() << "," << actual->getDato().getFechaNacimiento().getMes() << "," << actual->getDato().getFechaNacimiento().getYear();

            // Obtener la hora de entrada y salida formateada
            std::tm entrada = actual->getDato().getRegistro().getHoraEntrada();
            std::tm salida = actual->getDato().getRegistro().getHoraSalida();

            archivo << "," << std::put_time(&entrada, "%H:%M:%S") << "," << std::put_time(&salida, "%H:%M:%S") << endl;
            actual = actual->getSiguiente();
        }

        archivo.close();
        cout << endl << "La lista se ha guardado correctamente en el archivo." << endl;
    } else {
        cout << endl << "No se pudo abrir el archivo." << endl;
    }
}



static ListaDoble<T>* cargarListaDesdeArchivo(const char* nombreArchivo) {
    ListaDoble<T>* lista = new ListaDoble<T>();

    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string cedulaStr, nombre, apellido, swStr, diaStr, mesStr, yearStr, horaEntrada, horaSalida;

            if (std::getline(iss, cedulaStr, ',') &&
                std::getline(iss, nombre, ',') &&
                std::getline(iss, apellido, ',') &&
                std::getline(iss, swStr, ',') &&
                std::getline(iss, diaStr, ',') &&
                std::getline(iss, mesStr, ',') &&
                std::getline(iss, yearStr, ',') &&
                std::getline(iss, horaEntrada, ',') &&
                std::getline(iss, horaSalida)) {

                // Convertir cedula y sw a los tipos de datos correctos
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

                // Establecer las horas de entrada y salida
                std::tm entrada = {};
                std::istringstream issEntrada(horaEntrada);
                issEntrada >> std::get_time(&entrada, "%H:%M:%S");

                std::tm salida = {};
                std::istringstream issSalida(horaSalida);
                issSalida >> std::get_time(&salida, "%H:%M:%S");

                Registro registro;
                registro.setHoraEntrada(entrada);
                registro.setHoraSalida(salida);

                persona.setRegistro(registro);

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


};

#endif