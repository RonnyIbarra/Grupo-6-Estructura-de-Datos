/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Registro.cpp
 * Author:   Kevin Amaguaña, Alexander Daniel, Ronny Ibarra
 * Modified: Sunday, June 4, 2023 8:24:36 AM
 * Purpose: Implementation of the class Registro
 ***********************************************************************/
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Registro.h"

Registro::Registro(){
}

Registro::Registro(const std::tm& entrada, const std::tm& salida) {
        horaEntrada = entrada;
        horaSalida = salida;
    }

const std::tm& Registro::getHoraEntrada() const {
        return horaEntrada;
}

void Registro::setHoraEntrada(const std::tm& hora) {
        horaEntrada = hora;
}

const std::tm& Registro::getHoraSalida() const {
        return horaSalida;
}

void Registro::setHoraSalida(const std::tm& hora) {
        horaSalida = hora;
}

void Registro::calcularTiempoTrabajado() {
        std::time_t tiempoTrabajado = std::difftime(std::mktime(&horaSalida), std::mktime(&horaEntrada));

        int horas = tiempoTrabajado / 3600;
        int minutos = (tiempoTrabajado % 3600) / 60;
        int segundos = tiempoTrabajado % 60;

        // Imprimir el tiempo transcurrido en horas, minutos y segundos
        std::cout << "Tiempo trabajado: " << horas << " horas, " << minutos << " minutos, " << segundos << " segundos" << std::endl;
    }
    
void Registro::setHoraEntradaFromSystem() {
        std::time_t now = std::time(nullptr);
        horaEntrada = *std::localtime(&now);
    }
    
void Registro::setHoraSalidaFromSystem() {
        std::time_t now = std::time(nullptr);
        horaSalida = *std::localtime(&now);
    }
    
void Registro::toString() {
    std::ostringstream ossEntrada;
    ossEntrada << std::put_time(&horaEntrada, "%H:%M:%S");
    std::string strHoraEntrada = ossEntrada.str();

    std::ostringstream ossSalida;
    ossSalida << std::put_time(&horaSalida, "%H:%M:%S");
    std::string strHoraSalida = ossSalida.str();

    std::cout << "Hora de entrada: " << strHoraEntrada << "; ";
    std::cout << "Hora de salida: " << strHoraSalida ;
}