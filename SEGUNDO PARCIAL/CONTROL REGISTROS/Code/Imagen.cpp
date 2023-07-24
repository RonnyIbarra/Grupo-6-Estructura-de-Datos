/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Module:  Imagen.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Implementation of the class Imagen
 ***********************************************************************/


#include "Imagen.h"

Imagen::Imagen(const string& filename) : filename_(filename) {}

bool Imagen::readImage() {
    std::ifstream file(filename_, std::ios::binary);
    if (!file) {
        std::cerr << "Error al abrir el archivo: " << filename_ << std::endl;
        return false;
    }

    file.read(reinterpret_cast<char*>(&header_), sizeof(BMPHeader));
    if (header_.signature != 0x4D42) {
        std::cerr << "Formato de archivo incorrecto. Se esperaba un BMP." << std::endl;
        return false;
    }

    if (header_.bitsPerPixel != 24) {
        std::cerr << "Este programa solo admite imágenes de 24 bits por píxel." << std::endl;
        return false;
    }

    size_t padding = (4 - (header_.width * 3) % 4) % 4;
    file.seekg(header_.dataOffset, std::ios::beg);

    pixels_.resize(header_.height, std::vector<unsigned char>(header_.width * 3));
    for (int y = header_.height - 1; y >= 0; --y) {
        file.read(reinterpret_cast<char*>(pixels_[y].data()), header_.width * 3);
        file.seekg(padding, std::ios::cur);
    }

    return true;
}

void Imagen::displayImage() const {
    if (pixels_.empty() || header_.width <= 0 || header_.height <= 0) {
        std::cerr << "No se ha leído ninguna imagen o el tamaño de la imagen es inválido." << std::endl;
        return;
    }

    for (const auto& row : pixels_) {
        for (const auto& pixel : row) {
            // Convertir el valor del píxel a un carácter ASCII y mostrarlo
            const char* asciiChars = "@%#*+=-:. ";
            int index = pixel * 10 / 255;
            std::cout << asciiChars[index];
        }
        std::cout << std::endl;
    }
}