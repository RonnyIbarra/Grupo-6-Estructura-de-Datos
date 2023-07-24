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
    uint32_t fileSize;      // Tamaño total del archivo
    uint32_t reserved;      // Reservado, debe ser 0
    uint32_t dataOffset;    // Offset hasta los datos de imagen
    uint32_t headerSize;    // Tamaño de la cabecera en bytes
    int32_t width;          // Ancho de la imagen
    int32_t height;         // Altura de la imagen
    uint16_t planes;        // Planos de color (debe ser 1)
    uint16_t bitsPerPixel;  // Bits por píxel
    uint32_t compression;   // Método de compresión (0 = sin comprimir)
    uint32_t dataSize;      // Tamaño de los datos de imagen
    int32_t hResolution;    // Resolución horizontal en ppp (píxeles por metro)
    int32_t vResolution;    // Resolución vertical en ppp (píxeles por metro)
    uint32_t numColors;     // Número de colores en la paleta
    uint32_t importantColors; // Número de colores importantes (0 = todos)
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
