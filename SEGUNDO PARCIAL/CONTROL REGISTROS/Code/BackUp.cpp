/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  BackUp.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class BackUp
 *******************************************************************************/

#include "BackUp.h"

BackUp::BackUp(){
}


void BackUp::generarBackUp(void){
    namespace fs = std::filesystem;

    time_t now = time(nullptr);
    tm* local_time = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d%m%Y%H%M%S", local_time);
    string fechaHora(buffer);
    fechaHora = "..//BackUp//" + fechaHora;

    string backUp = "..//BackUp";

    if (!fs::exists(backUp)) {
        if (fs::create_directories(backUp)) {
            // Se creo la carpeta BackUp
            if (!fs::exists(fechaHora)) {
                if (fs::create_directories(fechaHora)) {
                    cout << "Se creo el respaldo en la carpeta: " << fechaHora << endl;
                    string rutaArchivoEmpleados = fechaHora + "//empleados.txt";
                    ofstream archivoEmpleados(rutaArchivoEmpleados);
                    string rutaArchivoRegistros = fechaHora + "//registros.txt";
                    ofstream archivoRegistros(rutaArchivoRegistros);
                    copyAndReplaceFiles("empleados.txt", fechaHora + "//empleados.txt");
                    copyAndReplaceFiles("registros.txt", fechaHora + "//registros.txt");
                }
                else {
                    cerr << "Se produjo un error al realizar el respaldo\n";
                }
            }
        }
        else {
            cerr << "Se produjo un error con la carpeta: " << backUp << endl;
        }
    }
    else {
        // Ya existe la carpeta BackUp
        if (!fs::exists(fechaHora)) {
            if (fs::create_directories(fechaHora)) {
                cout << "Se creo el respaldo en la carpeta: " << fechaHora << endl;
                string rutaArchivoEmpleados = fechaHora + "//empleados.txt";
                ofstream archivoEmpleados(rutaArchivoEmpleados);
                string rutaArchivoRegistros = fechaHora + "//registros.txt";
                ofstream archivoRegistros(rutaArchivoRegistros);
                copyAndReplaceFiles("empleados.txt", fechaHora + "//empleados.txt");
                copyAndReplaceFiles("registros.txt", fechaHora + "//registros.txt");
            }
            else {
                cout << "Se produjo un error al realizar el respaldo\n";
            }
        }
    }    
}

void BackUp::copyAndReplaceFiles(const string& sourceFilePath, const string& destinationFilePath) {
    ifstream sourceFile(sourceFilePath, ios::binary);
    ofstream destinationFile(destinationFilePath, ios::binary);

    if (sourceFile && destinationFile) {
        destinationFile << sourceFile.rdbuf(); // Copiar el contenido del archivo
        cout << "Respaldo realizado con exito del archivo: " << destinationFilePath << endl;
    }
    else {
        cout << "Error al realizar respaldo del archivo: " << sourceFilePath << endl;
        cout << "El archivo: " << destinationFilePath << " se encuentra vacio." << endl;
    }
    sourceFile.close();
    destinationFile.close();
}
