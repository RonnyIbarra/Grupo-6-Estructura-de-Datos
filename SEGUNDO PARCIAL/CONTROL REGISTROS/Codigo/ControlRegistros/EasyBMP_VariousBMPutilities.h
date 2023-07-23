/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE             
	AUTORES:
		Johan Romo
		Cristhopher Villamarin
		Sebastian Torres
                Jeanhela Nazate
                Milena Maldonado
                Shared Tinoco
		Brandon Masacela
		Juan Reyes
        GRUPOS: 7 - 10 - 11 - 14
        FECHA DE CREACION:        Viernes, 1 de julio de 2022 7:34:00 p. m. 	
	FECHA DE MODIFICACION:    Martes, 19 de junio de 2022 4:58:00 p. m.
        PROPOSITO: Proyecto Segundo Parcial - Arboles B
*/

#ifndef _EasyBMP_VariousBMPutilities_h_
#define _EasyBMP_VariousBMPutilities_h_

BMFH GetBMFH( const char* szFileNameIn );
BMIH GetBMIH( const char* szFileNameIn );
void DisplayBitmapInfo( const char* szFileNameIn );
int GetBitmapColorDepth( const char* szFileNameIn );
void PixelToPixelCopy( BMP& From, int FromX, int FromY,  
                       BMP& To, int ToX, int ToY);
void PixelToPixelCopyTransparent( BMP& From, int FromX, int FromY,  
                                  BMP& To, int ToX, int ToY,
                                  RGBApixel& Transparent );
void RangedPixelToPixelCopy( BMP& From, int FromL , int FromR, int FromB, int FromT, 
                             BMP& To, int ToX, int ToY );
void RangedPixelToPixelCopyTransparent( 
     BMP& From, int FromL , int FromR, int FromB, int FromT, 
     BMP& To, int ToX, int ToY ,
     RGBApixel& Transparent );
bool CreateGrayscaleColorTable( BMP& InputImage );

bool Rescale( BMP& InputImage , char mode, int NewDimension );

#endif
