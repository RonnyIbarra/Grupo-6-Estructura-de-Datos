/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Imagen.h
 * Author: Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Declaration of the class Imagen
 ***********************************************************************/

#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>
#include <fstream>
#include <vector>

#pragma pack(2) // Asegura que la estructura no tenga padding.

struct BMPHeader {
    uint16_t signature;     // BM (Tipo de archivo)
    uint32_t fileSize;      // Tama�o total del archivo
    uint32_t reserved;      // Reservado, debe ser 0
    uint32_t dataOffset;    // Offset hasta los datos de imagen
    uint32_t headerSize;    // Tama�o de la cabecera en bytes
    int32_t width;          // Ancho de la imagen
    int32_t height;         // Altura de la imagen
    uint16_t planes;        // Planos de color (debe ser 1)
    uint16_t bitsPerPixel;  // Bits por p�xel
    uint32_t compression;   // M�todo de compresi�n (0 = sin comprimir)
    uint32_t dataSize;      // Tama�o de los datos de imagen
    int32_t hResolution;    // Resoluci�n horizontal en ppp (p�xeles por metro)
    int32_t vResolution;    // Resoluci�n vertical en ppp (p�xeles por metro)
    uint32_t numColors;     // N�mero de colores en la paleta
    uint32_t importantColors; // N�mero de colores importantes (0 = todos)
};

using namespace std;

class Imagen {
public:
    Imagen(const string&);
    bool readImage();
    void displayImage() const;

private:
    std::string filename_;
    BMPHeader header_;
    std::vector<std::vector<unsigned char>> pixels_;
};

#endif 
