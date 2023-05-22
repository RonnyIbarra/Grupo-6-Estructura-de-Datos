/***********************************************************************
 * UFA - ESPE
 * Students:  Kevin Amaguaña, Daniel Guaman, Ronny Ibarra
 * Module:  FuncionesMatrices.h
 * NRC: 7999
 ***********************************************************************/
#include "FuncionesMatrices.cpp"
#define FILAS 3
#define COLUMNAS 3


int main(int argc, char const *argv[])
{
    int *matriz1 = new int[FILAS*COLUMNAS];
    int *matriz2 = new int[FILAS*COLUMNAS];
    int *matriz3 = new int[FILAS*COLUMNAS];
    int *matriz4 = new int[FILAS*COLUMNAS];
    FuncionesMatrices funcionesMatrices;
    cout << "Ingrese los valores de la primera matriz" << endl;
    funcionesMatrices.crearMatriz(matriz1, FILAS, COLUMNAS);
    cout << "Ingrese los valores de la segunda matriz" << endl;
    funcionesMatrices.crearMatriz(matriz2, FILAS, COLUMNAS);
    cout << "La suma de las matrices es: " << endl;
    matriz3 = funcionesMatrices.sumarMatriz(matriz1, matriz2, FILAS, COLUMNAS);
    funcionesMatrices.imprimirMatriz(matriz3, FILAS, COLUMNAS);
    cout << "La multiplicacion de las matrices es: " << endl;
    matriz4 = funcionesMatrices.multiplicarMatriz
	(matriz1, matriz2, FILAS, COLUMNAS);
    funcionesMatrices.imprimirMatriz(matriz4, FILAS, COLUMNAS);

    return 0;
}

