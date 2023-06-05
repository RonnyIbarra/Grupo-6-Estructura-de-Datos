/***********************************************************************
 * UFA-ESPE
 *Module:  Sobrecarga.cpp
 * Author:  Kevin Amaguña, Alexander Guaman, Ronny Ibarra
 * Modified: Wednesday, May 17, 2023 7:43:08 AM
 * Purpose: Implementation of the class Sobrecarga
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Sobrecarga_h)
#define __Class_Diagram_1_Sobrecarga_h

class Sobrecarga
{
public:
   int getNum1(void);
   void setNum1(int newNum1);
   Sobrecarga(int v) : valor(v) {}
   int obetenerValor() const;
   bool operator>=(const Sobrecarga& other) const;
   Sobrecarga();
   ~Sobrecarga();
   int imprimir(int num1, int num2);

protected:
private:
   int valor;
   int num1;
   int num2;



};

#endif