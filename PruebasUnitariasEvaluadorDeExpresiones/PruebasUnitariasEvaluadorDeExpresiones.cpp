#include "pch.h"
#include "CppUnitTest.h"
#include "..\ProyectoEvaluadorExpresiones_LenguajesProgramacion\InfixManager.h"
#include "..\ProyectoEvaluadorExpresiones_LenguajesProgramacion\PostFixManager.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebasUnitariasEvaluadorDeExpresiones
{
	TEST_CLASS(PruebasEvaluador)
	{
	public:
		TEST_METHOD(Operacion)
		{
			string expresion = "2+4-5*(4/2)";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "-4.000000";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionesConParentesis)
		{
			string expresion = "10+(1+2)*2";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "16.000000";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionSimple)
		{
			string expresion = "5+5";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "10.000000";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionesSinParentesis)
		{
			string expresion = "10+12*24";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "298.000000";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionesConMultiplesParentesis)
		{
			string expresion = "5-(6*(5+4))/2";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "-22.000000";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionDivisorNulo)
		{
			string expresion = "4/0";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "0";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionOperadorInicial)
		{
			string expresion = "*7+83";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "0";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionOperadorFinal)
		{
			string expresion = "56-8*(10-4)/";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "0";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionParentesisAbierto)
		{
			string expresion = "13+873/";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "0";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}

		TEST_METHOD(OperacionParentesisMalCerrado)
		{
			string expresion = "332+89)";
			InfixManager InfixExpresion(expresion);
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string esperado = "0";
			string actual = PostfixExpresion.getResult();

			Assert::AreEqual(actual, esperado);
		}
	};
}
