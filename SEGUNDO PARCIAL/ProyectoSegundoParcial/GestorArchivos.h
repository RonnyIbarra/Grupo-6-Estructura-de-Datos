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
#include "ListaCircularDoble.h"
#include "Persona.h"
#include "Registro.h"

using namespace std;

template <typename T>
class GestorArchivos {
public:

static void guardarListaPersonaEnArchivo(const char* nombreArchivo, ListaCircularDoble<T>* lista) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        Nodo<T>* nodoActual = lista->getCabeza(); // Suponiendo que primerNodo es un puntero al primer nodo de la lista

	if (nodoActual != nullptr) {
	    do {
	        archivo << nodoActual->getDato().getDni() << "," << nodoActual->getDato().getNombre() << "," << nodoActual->getDato().getApellido();
	        archivo << "," << nodoActual->getDato().getFecha().getDia() << "," << nodoActual->getDato().getFecha().getMes() << "," << nodoActual->getDato().getFecha().getYear() << endl;
	
	        nodoActual = nodoActual->getSiguiente();
	    } while (nodoActual != lista->getCabeza()); // Continuar hasta que se vuelva al primer nodo
	}


        archivo.close();
        cout << endl;
    } else {
        cout << endl << "No se pudo abrir el archivo." << endl;
    }
}


static ListaCircularDoble<T>* cargarListaPersonaDesdeArchivo(const char* nombreArchivo) {
    ListaCircularDoble<T>* lista = new ListaCircularDoble<T>();

    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string dni, nombre, apellido, swStr, diaStr, mesStr, yearStr;

            if (std::getline(iss, dni, ',') &&
                std::getline(iss, nombre, ',') &&
                std::getline(iss, apellido, ',') &&
                std::getline(iss, diaStr, ',') &&
                std::getline(iss, mesStr, ',') &&
                std::getline(iss, yearStr, ',') ) {

                // Convertir a los tipos de datos correctos
                int dia = std::stoi(diaStr);
                int mes = std::stoi(mesStr);
                int year = std::stoi(yearStr);

                // Crear un objeto Persona y establecer sus atributos
                Persona persona;
                persona.setDni(dni);
                persona.setNombre(nombre);
                persona.setApellido(apellido);
                persona.setFecha(Fecha(dia, mes, year));

                
                // Agregar la persona a la lista
                lista->insertar(persona);
            }
        }

        archivo.close();
        cout << endl << "La lista se ha cargado correctamente desde el archivo." << endl;
    } else {
        cout << endl << "No se pudo abrir el archivo." << endl;
    }

    return lista;
}

static void guardarListaRegistroEnArchivo(const char *nombreArchivo, ListaCircularDoble<T> *lista)
    {
        ofstream archivo(nombreArchivo);

        if (archivo.is_open())
        {
            Nodo<T> *nodoActual = lista->getCabeza(); // Suponiendo que primerNodo es un puntero al primer nodo de la lista

            if (nodoActual != nullptr)
            {
                do
                {
                    archivo <<nodoActual->getDato().getDni() << "," << nodoActual->getDato().getFecha().getDia()
                            << "," << nodoActual->getDato().getFecha().getMes() << "," << nodoActual->getDato().getFecha().getYear()
                            << "," << nodoActual->getDato().getFecha().getHora() << "," << nodoActual->getDato().getFecha().getMinuto()
                            << "," << nodoActual->getDato().getFecha().getSegundo() << endl;

                    nodoActual = nodoActual->getSiguiente();
                } while (nodoActual != lista->getCabeza()); // Continuar hasta que se vuelva al primer nodo
            }

            archivo.close();
            cout << endl;
        }
        else
        {
            cout << endl
                 << "No se pudo abrir el archivo." << endl;
        }
    }

    static ListaCircularDoble<T> *cargarListaRegistroDesdeArchivo(const char *nombreArchivo)
    {
        ListaCircularDoble<T> *lista = new ListaCircularDoble<T>();

        std::ifstream archivo(nombreArchivo);

        if (archivo.is_open())
        {
            std::string linea;
            while (std::getline(archivo, linea))
            {
                std::istringstream iss(linea);
                std::string dni, diaStr, mesStr, yearStr;
                std::string horaStr, minutosStr, segundosStr;

                if (std::getline(iss, dni, ',') &&
				    std::getline(iss, diaStr, ',') &&
                    std::getline(iss, mesStr, ',') &&
                    std::getline(iss, yearStr, ',') &&
                    std::getline(iss, horaStr, ',') &&
                    std::getline(iss, minutosStr, ',') &&
                    std::getline(iss, segundosStr, ','))
                {

                    // Convertir a los tipos de datos correctos
                    int dia = std::stoi(diaStr);
                    int mes = std::stoi(mesStr);
                    int year = std::stoi(yearStr);
                    int hora = std::stoi(horaStr);
                    int minuto = std::stoi(minutosStr);
                    int segundo = std::stoi(segundosStr);

                    // Crear un objeto Persona y establecer sus atributos
                    Registro registro;
                    registro.setDni(dni);
                    Fecha fecha;
                    fecha.setDia(dia);
                    fecha.setMes(mes);
                    fecha.setYear(year);
                    fecha.setHora(hora);
                    fecha.setMinuto(minuto);
                    fecha.setSegundo(segundo);
                    registro.setFecha(fecha);

                    // Agregar la persona a la lista
                    lista->insertar(registro);
                }
            }

            archivo.close();
            cout << endl
                 << "La lista se ha cargado correctamente desde el archivo." << endl;
        }
        else
        {
            cout << endl
                 << "No se pudo abrir el archivo." << endl;
        }

        return lista;
    }



};

#endif