#pragma once
#ifndef OPERACIONES_H
#define OPERACIONES_H

namespace operancion {
	//feature C++ V17 - Namaspaces Anidados
	namespace _sum {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		//feature C++ V17 - Inline specifier en archivos de cabezera
		inline auto sum = [](auto a, auto b) {
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
		//feature C++ V17 - Inline specifier en archivos de cabezera
		inline auto rest = [](auto a, auto b) {
			return a - b;
		};
	}

	//feature C++ V17 - Namaspaces Anidados
	namespace _mult {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		//feature C++ V17 - Inline specifier en archivos de cabezera
		inline auto mult = [](auto a, auto b) {
			return a * b;
		};
	}

	//feature C++ V17 - Namaspaces Anidados
	namespace _divi {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		//feature C++ V17 - Inline specifier en archivos de cabezera
		inline auto divi = [](auto a, auto b) {
			return a / b;
		};
	}

	//feature C++ V17 - Namaspaces Anidados
	namespace _expo {
		//feature C++ V14 - Lambda Expresions and Funtions con Autodeduccion de  tipos
		//feature C++ V17 - Inline specifier en archivos de cabezera
		inline auto expo = [](auto a, auto b) {
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

	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones
	/*feature C++ V14 - Order of evaluation(Al regresar de una función,
	se secuencia la inicialización de copia del temporal que es el resultado 
	de evaluar la llamada a la función, antes de la destrucción de todos los 
	temporales al final del operando de la declaración de retorno, que, a su 
	vez, se secuencia antes la destrucción de las variables locales del bloque 
	que encierra la declaración de retorno.)*/
	//feature C++ V17 - Class template argument deduction

	//Suma de dos enteros
	template<typename T, typename T2>
	auto suma(T x, T2 y) {
		return sum(x, y);
	};



	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones
	/*feature C++ V14 - Order of evaluation(Al regresar de una función,
	se secuencia la inicialización de copia del temporal que es el resultado
	de evaluar la llamada a la función, antes de la destrucción de todos los
	temporales al final del operando de la declaración de retorno, que, a su
	vez, se secuencia antes la destrucción de las variables locales del bloque
	que encierra la declaración de retorno.)*/
	//feature C++ V17 - Class template argument deduction

	//Resta de dos enteros
	template<typename T, typename T2>
	auto resta(T x, T2 y) {
		return rest(x, y);;
	};



	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones
	/*feature C++ V14 - Order of evaluation(Al regresar de una función,
	se secuencia la inicialización de copia del temporal que es el resultado
	de evaluar la llamada a la función, antes de la destrucción de todos los
	temporales al final del operando de la declaración de retorno, que, a su
	vez, se secuencia antes la destrucción de las variables locales del bloque
	que encierra la declaración de retorno.)*/
	//feature C++ V17 - Class template argument deduction

	//Multimplicacion de dos enteros
	template<typename T, typename T2>
	auto multiplicacion(T x, T2 y) { 
		return mult(x, y);
	};



	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones 
	/*feature C++ V14 - Order of evaluation(Al regresar de una función,
	se secuencia la inicialización de copia del temporal que es el resultado
	de evaluar la llamada a la función, antes de la destrucción de todos los
	temporales al final del operando de la declaración de retorno, que, a su
	vez, se secuencia antes la destrucción de las variables locales del bloque
	que encierra la declaración de retorno.)*/
	//feature C++ V17 - Class template argument deduction

	//Divicion de dos Enteros
	template<typename T, typename T2>
	auto divicion(T x, T2 y) {
		return divi(x, y);;
	};
	

	//feature C++ V11 - Lambda Expresions
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones
	/*feature C++ V14 - Order of evaluation(Al regresar de una función,
	se secuencia la inicialización de copia del temporal que es el resultado
	de evaluar la llamada a la función, antes de la destrucción de todos los
	temporales al final del operando de la declaración de retorno, que, a su
	vez, se secuencia antes la destrucción de las variables locales del bloque
	que encierra la declaración de retorno.)*/

	//Modulo de dos enteros
	auto mod(int x, int y) { 
		auto modulo = [](auto a, auto b) {
			return a % b;
		};

		return  modulo(x, y);
	};
	


	//feature C++ V11 - Autodeduccion de Tipos de Datos
	//feature C++ V14 - Autodeduccion de Tipos de Retorno de Funciones
	/*feature C++ V14 - Order of evaluation(Al regresar de una función,
	se secuencia la inicialización de copia del temporal que es el resultado
	de evaluar la llamada a la función, antes de la destrucción de todos los
	temporales al final del operando de la declaración de retorno, que, a su
	vez, se secuencia antes la destrucción de las variables locales del bloque
	que encierra la declaración de retorno.)*/
	//feature C++ V17 - Class template argument deduction

	//Exponente entero de un entero
	template<typename T, typename T2>
	auto exp(T x, T2 y) { 
		return expo(x, y);
	};
};
#endif // !OPERACIONES_H
