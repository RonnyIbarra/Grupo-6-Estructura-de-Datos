#include "pch.h"
#include "CppUnitTest.h"
#include "..//PolacaCalculadora/Pila.h"
#include "..//PolacaCalculadora/Polaca.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// infijo 2+3*4
			// postfijo 234*+
			Pila<string> pila;
			Polaca polaca;
			pila.push("+");
			pila.push("*");
			pila.push("4");
			pila.push("3");
			pila.push("2");
			double resultadoEsperado = 14.00;
			double resultado = polaca.calcular(pila);
			Assert::AreEqual(resultadoEsperado, resultado);
		}

		TEST_METHOD(TestMethod2)
		{
			// infijo s0+c0*3
			// postfijo 0s0c3*+
			Pila<string> pila;
			Polaca polaca;
			pila.push("+");
			pila.push("*");
			pila.push("3");
			pila.push("c");
			pila.push("0");
			pila.push("s");
			pila.push("0");
			double resultadoEsperado = 3.00;
			double resultado = polaca.calcular(pila);
			Assert::AreEqual(resultadoEsperado, resultado);
		}
	};
}
