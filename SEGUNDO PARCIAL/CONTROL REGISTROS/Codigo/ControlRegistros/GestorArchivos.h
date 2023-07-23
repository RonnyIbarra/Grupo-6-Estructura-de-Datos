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
#include "Empleado.h"
#include "Registro.h"

using namespace std;

template <typename T>
class GestorArchivos {
public:

static void guardarListaEmpleadoEnArchivo(const char* nombreArchivo, ListaCircularDoble<T>* lista) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        NodoDoble<T>* nodoActual = lista->getCabeza(); // Suponiendo que primerNodo es un puntero al primer nodo de la lista

	if (nodoActual != nullptr) {
	    do {
	        archivo << nodoActual->getDato().getDni() << "," << nodoActual->getDato().getNombre() << "," << nodoActual->getDato().getApellido();
	        archivo << "," << nodoActual->getDato().getFecha().getDia() << "," << nodoActual->getDato().getFecha().getMes() << "," << nodoActual->getDato().getFecha().getYear();
            archivo << "," << nodoActual->getDato().getSueldo() << endl;
	        nodoActual = nodoActual->getSiguiente();
	    } while (nodoActual != lista->getCabeza()); // Continuar hasta que se vuelva al primer nodo
	}


        archivo.close();
        cout << endl;
    } else {
        cout << endl << "No se pudo abrir el archivo." << endl;
    }
}


static ListaCircularDoble<T>* cargarListaEmpleadoDesdeArchivo(const char* nombreArchivo) {
    ListaCircularDoble<T>* lista = new ListaCircularDoble<T>();

    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string dni, nombre, apellido, swStr, diaStr, mesStr, yearStr, sueldoStr;

            if (std::getline(iss, dni, ',') &&
                std::getline(iss, nombre, ',') &&
                std::getline(iss, apellido, ',') &&
                std::getline(iss, diaStr, ',') &&
                std::getline(iss, mesStr, ',') &&
                std::getline(iss, yearStr, ',')&&
                std::getline(iss, sueldoStr, ',') ) {

                // Convertir a los tipos de datos correctos
                int dia = std::stoi(diaStr);
                int mes = std::stoi(mesStr);
                int year = std::stoi(yearStr);
                float sueldo = std::stof(sueldoStr);

                // Crear un objeto Persona y establecer sus atributos
                Empleado empleado;
                empleado.setDni(dni);
                empleado.setNombre(nombre);
                empleado.setApellido(apellido);
                empleado.setFecha(Fecha(dia, mes, year));
                empleado.setSueldo(sueldo);

                
                // Agregar la persona a la lista
                lista->insertar(empleado);
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
            NodoDoble<T> *nodoActual = lista->getCabeza(); // Suponiendo que primerNodo es un puntero al primer nodo de la lista

            if (nodoActual != nullptr)
            {
                do
                {
                    archivo <<nodoActual->getDato().getDni() << "," << nodoActual->getDato().getSw() << ","
                            << nodoActual->getDato().getEntrada().getDia() << "," << nodoActual->getDato().getEntrada().getMes() << "," << nodoActual->getDato().getEntrada().getYear()
                            << "," << nodoActual->getDato().getEntrada().getHora() << "," << nodoActual->getDato().getEntrada().getMinuto() << "," << nodoActual->getDato().getEntrada().getSegundo()
                            << "," << nodoActual->getDato().getSalida().getDia() << "," << nodoActual->getDato().getSalida().getMes() << "," << nodoActual->getDato().getSalida().getYear()
                            << "," << nodoActual->getDato().getSalida().getHora() << "," << nodoActual->getDato().getSalida().getMinuto() << "," << nodoActual->getDato().getSalida().getSegundo() << endl;

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
                std::string dni, swStr, diaSalidaStr, mesSalidaStr, yearSalidaStr;
                std::string horaSalidaStr, minutosSalidaStr, segundosSalidaStr;
                std::string diaEntradaStr, mesEntradaStr, yearEntradaStr;
                std::string horaEntradaStr, minutosEntradaStr, segundosEntradaStr;

                if (std::getline(iss, dni, ',') &&
                    std::getline(iss, swStr, ',') &&
				    std::getline(iss, diaEntradaStr, ',') &&
                    std::getline(iss, mesEntradaStr, ',') &&
                    std::getline(iss, yearEntradaStr, ',') &&
                    std::getline(iss, horaEntradaStr, ',') &&
                    std::getline(iss, minutosEntradaStr, ',') &&
                    std::getline(iss, segundosEntradaStr, ',') &&
                    std::getline(iss, diaSalidaStr, ',') &&
                    std::getline(iss, mesSalidaStr, ',') &&
                    std::getline(iss, yearSalidaStr, ',') &&
                    std::getline(iss, horaSalidaStr, ',') &&
                    std::getline(iss, minutosSalidaStr, ',') &&
                    std::getline(iss, segundosSalidaStr, ','))
                {

                    // Convertir a los tipos de datos correctos
                    int sw = stoi(swStr);
                    int diaEntrada = stoi(diaEntradaStr);
                    int mesEntrada = stoi(mesEntradaStr);
                    int yearEntrada = stoi(yearEntradaStr);
                    int horaEntrada = stoi(horaEntradaStr);
                    int minutoEntrada = stoi(minutosEntradaStr);
                    int segundoEntrada = stoi(segundosEntradaStr);

                    int diaSalida = stoi(diaSalidaStr);
                    int mesSalida = stoi(mesSalidaStr);
                    int yearSalida = stoi(yearSalidaStr);
                    int horaSalida = stoi(horaSalidaStr);
                    int minutoSalida = stoi(minutosSalidaStr);
                    int segundoSalida = stoi(segundosSalidaStr);

                    // Crear un objeto registro y establecer sus atributos
                    Registro registro;
                    registro.setDni(dni);
                    registro.setSw(sw);
                    Fecha entrada;
                    entrada.setDia(diaEntrada);
                    entrada.setMes(mesEntrada);
                    entrada.setYear(yearEntrada);
                    entrada.setHora(horaEntrada);
                    entrada.setMinuto(minutoEntrada);
                    entrada.setSegundo(segundoEntrada);
                    registro.setEntrada(entrada);
                    Fecha salida;  
                    salida.setDia(diaSalida);       
                    salida.setMes(mesSalida);        
                    salida.setYear(yearSalida);      
                    salida.setHora(horaSalida);      
                    salida.setMinuto(minutoSalida);  
                    salida.setSegundo(segundoSalida);
                    registro.setSalida(salida);

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