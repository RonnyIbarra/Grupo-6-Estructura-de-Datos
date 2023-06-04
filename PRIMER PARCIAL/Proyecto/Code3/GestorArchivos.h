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
                archivo << "," << actual->getDato().getFechaNacimiento().getDia() << "," << actual->getDato().getFechaNacimiento().getMes() << "," << actual->getDato().getFechaNacimiento().getYear() << endl;
                actual = actual->getSiguiente();
            }

            archivo.close();
            cout << "La lista se ha guardado correctamente en el archivo." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
    

	static ListaDoble<T>* cargarListaDesdeArchivo(const char* nombreArchivo) {
        ListaDoble<T>* lista = new ListaDoble<T>();
        ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                long int cedula;
                string nombre;
                string apellido;
                int dia;
                int mes;
                int year;

                size_t pos1 = linea.find(",");
                size_t pos2 = linea.find(",", pos1 + 1);
                size_t pos3 = linea.find(",", pos2 + 1);
                size_t pos4 = linea.find(",", pos3 + 1);
                size_t pos5 = linea.find(",", pos4 + 1);

                if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos && pos4 != string::npos && pos5 != string::npos) {
                    cedula = stol(linea.substr(0, pos1));
                    nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
                    apellido = linea.substr(pos2 + 1, pos3 - pos2 - 1);
                    dia = stoi(linea.substr(pos3 + 1, pos4 - pos3 - 1));
                    mes = stoi(linea.substr(pos4 + 1, pos5 - pos4 - 1));
                    year = stoi(linea.substr(pos5 + 1));

                    Fecha fechaNacimiento(dia, mes, year);
                    Persona persona(cedula, nombre, apellido, fechaNacimiento);
                    lista->insertarPorCola(persona);
                }
            }

            archivo.close();
            cout << "La lista se ha cargado correctamente desde el archivo." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }

        return lista;
	}

};

#endif