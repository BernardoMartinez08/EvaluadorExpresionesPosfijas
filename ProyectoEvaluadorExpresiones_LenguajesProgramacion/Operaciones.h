#pragma once
#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;

class Operaciones {
public:
	Operaciones() {};
	
	//feature C++ V11 - Lambda Expresions
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones

	//Suma de dos enteros
	auto suma(int x, int y) {
		auto sum = [](auto a, auto b) {
			return a + b;
		};

		auto resultado = sum(x, y);
		return resultado;
	};
	//Suma de dos flotantes
	auto suma(float x, float y) {
		auto sum = [](auto a, auto b) {
			return a + b;
		};

		auto resultado = sum(x, y);
		return resultado;
	};
	//Suma de un entero y un flotante
	auto suma(int x, float y) {
		auto sum = [](auto a, auto b) {
			return a + b;
		};

		auto resultado = sum(x, y);
		return resultado;
	};
	//Suma de un flotante y un entero
	auto suma(float x, int y) {
		auto sum = [](auto a, auto b) {
			return a + b;
		};

		auto resultado = sum(x, y);
		return resultado;
	};






	//feature C++ V11 - Lambda Expresions
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones
	
	//Resta de dos enteros
	int resta(int x, int y) {
		auto rest = [](auto a, auto b) {
			return a - b;
		};

		auto resultado = rest(x, y);
		return resultado;
	};
	//Resta de dos flotantes
	float resta(float x, float y) { 
		auto rest = [](auto a, auto b) {
			return a - b;
		};

		auto resultado = rest(x, y);
		return resultado;
	};
	//Resta de un entero y un flotante
	float resta(int x, float y) { 
		auto rest = [](auto a, auto b) {
			return a - b;
		};

		auto resultado = rest(x, y);
		return resultado;
	};
	//Resta de un flotante y un entero
	float resta(float x, int y) {
		auto rest = [](auto a, auto b) {
			return a - b;
		};

		auto resultado = rest(x, y);
		return resultado;
	};






	//feature C++ V11 - Lambda Expresions
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	
	//Multimplicacion de dos enteros
	int multiplicacion(int x, int y) { 
		auto mult = [](auto a, auto b) {
			return a * b;
		};

		auto resultado = mult(x, y);
		return resultado;
	};
	//Multiplicacion de dos flotantes
	float multiplicacion(float x, float y) { 
		auto mult = [](auto a, auto b) {
			return a * b;
		};

		auto resultado = mult(x, y);
		return resultado;
	};
	//Multiplicacion de un entero y un flotante
	float multiplicacion(int x, float y) {
		auto mult = [](auto a, auto b) {
			return a * b;
		};

		auto resultado = mult(x, y);
		return resultado;
	};
	//Multiplicacion de un flotante y un entero
	float multiplicacion(float x, int y) {
		auto mult = [](auto a, auto b) {
			return a * b;
		};

		auto resultado = mult(x, y);
		return resultado;
	};





	//feature C++ V11 - Lambda Expresions
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	
	//Divicion de dos Enteros
	int divicion(int x, int y) {
		auto divi = [](auto a, auto b) {
			return a / b;
		};

		auto resultado = divi(x, y);
		return resultado;
	};
	//Divicion de dos Flotantes
	float divicion(float x, float y) { 
		auto divi = [](auto a, auto b) {
			return a / b;
		};

		auto resultado = divi(x, y);
		return resultado;
	};
	//Divicion de un entero y un flotante
	float divicion(int x, float y) { 
		auto divi = [](auto a, auto b) {
			return a / b;
		};

		auto resultado = divi(x, y);
		return resultado;
	};
	//Divicion de un flotante y un entero
	float divicion(float x, int y) {
		auto divi = [](auto a, auto b) {
			return a / b;
		};

		auto resultado = divi(x, y);
		return resultado;
	};






	//feature C++ V11 - Lambda Expresions
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	 
	//Modulo de dos enteros
	int mod(int x, int y) { 
		auto modulo = [](auto a, auto b) {
			return a % b;
		};

		auto resultado = modulo(x, y);
		return resultado;
	};
	





	//feature C++ V11 - Lambda Expresions
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	
	//Exponente entero de un entero
	int exp(int x, int y) { 
		auto expo = [](auto a, auto b) {
			return pow(a, b);
		};

		auto resultado = expo(x, y);
		return resultado;
	};
	//Exponente flotante de un flotante
	float exp(float x, float y) {
		auto expo = [](auto a, auto b) {
			return pow(a, b);
		};
		
		auto resultado = expo(x, y);
		return resultado;
	};
	//Exponente flotanate de un entero
	float exp(int x, float y) {
		auto expo = [](auto a, auto b) {
			return pow(a, b);
		};

		auto resultado = expo(x, y);
		return resultado;
	};
	//Exponente entero de un flotante
	float exp(float x, int y) { 
		auto expo = [](auto a, auto b) {
			return pow(a, b);
		};

		auto resultado = expo(x, y);
		return resultado;
	};

	
};


#endif // !OPERACIONES_H
