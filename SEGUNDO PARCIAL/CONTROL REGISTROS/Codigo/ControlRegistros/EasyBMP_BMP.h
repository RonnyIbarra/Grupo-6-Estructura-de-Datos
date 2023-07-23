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

#ifndef _EasyBMP_BMP_h_
#define _EasyBMP_BMP_h_

bool SafeFread( char* buffer, int size, int number, FILE* fp );
bool EasyBMPcheckDataSize( void );

class BMP
{private:

 int BitDepth;
 int Width;
 int Height;
 RGBApixel** Pixels;
 RGBApixel* Colors;
 int XPelsPerMeter;
 int YPelsPerMeter;

 ebmpBYTE* MetaData1;
 int SizeOfMetaData1;
 ebmpBYTE* MetaData2;
 int SizeOfMetaData2;
   
 bool Read32bitRow( ebmpBYTE* Buffer, int BufferSize, int Row );   
 bool Read24bitRow( ebmpBYTE* Buffer, int BufferSize, int Row );   
 bool Read8bitRow(  ebmpBYTE* Buffer, int BufferSize, int Row );  
 bool Read4bitRow(  ebmpBYTE* Buffer, int BufferSize, int Row );  
 bool Read1bitRow(  ebmpBYTE* Buffer, int BufferSize, int Row );
   
 bool Write32bitRow( ebmpBYTE* Buffer, int BufferSize, int Row );   
 bool Write24bitRow( ebmpBYTE* Buffer, int BufferSize, int Row );   
 bool Write8bitRow(  ebmpBYTE* Buffer, int BufferSize, int Row );  
 bool Write4bitRow(  ebmpBYTE* Buffer, int BufferSize, int Row );  
 bool Write1bitRow(  ebmpBYTE* Buffer, int BufferSize, int Row );
 
 ebmpBYTE FindClosestColor( RGBApixel& input );

 public: 

 int TellBitDepth( void );
 int TellWidth( void );
 int TellHeight( void );
 int TellNumberOfColors( void );
 void SetDPI( int HorizontalDPI, int VerticalDPI );
 int TellVerticalDPI( void );
 int TellHorizontalDPI( void );
  
 BMP();
 BMP( BMP& Input );
 ~BMP();
 RGBApixel* operator()(int i,int j);
 
 RGBApixel GetPixel( int i, int j ) const;
 bool SetPixel( int i, int j, RGBApixel NewPixel );
 
 bool CreateStandardColorTable( void );
 
 bool SetSize( int NewWidth, int NewHeight );
 bool SetBitDepth( int NewDepth );
 bool WriteToFile( const char* FileName );
 bool ReadFromFile( const char* FileName );
 
 RGBApixel GetColor( int ColorNumber );
 bool SetColor( int ColorNumber, RGBApixel NewColor ); 
};

#endif