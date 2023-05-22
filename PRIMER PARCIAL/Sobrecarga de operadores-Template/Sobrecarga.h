/***********************************************************************
 * UFA-ESPE
 *Module:  Sobrecarga.cpp
 * Author:  Kevin Amaguña, Alexander Guaman, Ronny Ibarra
 * Modified: Wednesday, May 17, 2023 7:43:08 AM
 * Purpose: Implementation of the class Sobrecarga
 ***********************************************************************/


template<typename T>
class Sobrecarga
{
public:
   T getNum1(void);
   void setNum1(T newNum1);
   Sobrecarga(T v) : valor(v) {}
   T obtenerValor() const;
   bool operator>=(const Sobrecarga& other) const;
   Sobrecarga();
   ~Sobrecarga();
   int imprimir(T num1, T num2);

protected:
private:
   T valor;
   T num1;
   T num2;
};
