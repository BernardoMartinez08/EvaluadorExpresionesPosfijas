#pragma once
#ifndef OPERACIONES_H
#define OPERACIONES_H

namespace operancion {
	//feature C++ V17 - Namaspaces Anidados
	namespace _sum {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		//auto resultado = 0;
		auto sum = [](auto a, auto b) {
			return a + b;
		};

		/*template <typename... Args>
		auto sum2 = [](Args... args){
			return (args + ...);
		}*/
	}

	//feature C++ V17 - Namaspaces Anidados
	namespace _rest {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		auto rest = [](auto a, auto b) {
			return a - b;
		};
	}

	//feature C++ V17 - Namaspaces Anidados
	namespace _mult {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		auto mult = [](auto a, auto b) {
			return a * b;
		};
	}

	//feature C++ V17 - Namaspaces Anidados
	namespace _divi {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		auto divi = [](auto a, auto b) {
			return a / b;
		};
	}

	//feature C++ V17 - Namaspaces Anidados
	namespace _expo {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		auto expo = [](auto a, auto b) {
			return pow(a, b);
		};
	}
};

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace operancion;
using namespace std;
using namespace _sum;
using namespace _rest;
using namespace _mult;
using namespace _divi;
using namespace _expo;


class Operaciones {
public:
	Operaciones() {};
	
	//feature C++ V11 - Lambda Expresions
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones

	//Suma de dos enteros
	template<typename T, typename T2>
	auto suma(T x, T2 y) {
		auto resultado = sum(x, y);
		return resultado;
	};



	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones
	//Resta de dos enteros
	template<typename T, typename T2>
	auto resta(T x, T2 y) {
		auto resultado = rest(x, y);
		return resultado;
	};



	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	//Multimplicacion de dos enteros
	template<typename T, typename T2>
	auto multiplicacion(T x, T2 y) { 
		auto resultado = mult(x, y);
		return resultado;
	};



	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	//Divicion de dos Enteros
	template<typename T, typename T2>
	auto divicion(T x, T2 y) {
		auto resultado = divi(x, y);
		return resultado;
	};
	


	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	//Modulo de dos enteros
	auto mod(int x, int y) { 
		auto modulo = [](auto a, auto b) {
			return a % b;
		};

		auto resultado = modulo(x, y);
		return resultado;
	};
	


	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	//Exponente entero de un entero
	template<typename T, typename T2>
	auto exp(T x, T2 y) { 
		auto resultado = expo(x, y);
		return resultado;
	};
};
#endif // !OPERACIONES_H
