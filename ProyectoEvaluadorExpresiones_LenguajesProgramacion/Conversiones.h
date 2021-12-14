#pragma once
#ifndef CONVERSIONES_H
#define CONVERSIONES_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
#include "Stack.h"
#include "ConstantesManager.h"
#include "Validaciones.h"
#include "VariableManager.h"

using namespace std;

/*
	Clase Conversiones donde se juntas todas las funciones para convertir los datos de
	tipo string a su tipo correspondiente.
*/
class Conversiones {
public:
	Conversiones();
	
	//Convertir String a Float
	float toFloat(string);

	//Convertir una variable a un valor pedido de consola
	auto toVariable(string);

	//Convertir String a una Constante extraida del archivo
	Constantes toConstante(string);

	//Convertir String a Entero
	int toInt(string);

	//Convertir String a Char
	char toSimbolo(string);
};
#endif // !CONVERSIONES_H