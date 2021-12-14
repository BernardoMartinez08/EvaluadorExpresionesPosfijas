#pragma once
#ifndef VARIABLE_MANAGER
#define VARIABLE_MANAGER

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Validaciones.h"


using namespace std;

/*
	Clase VariableManager es una clase que se encarga de pedir al usuario
	el valor correspondiente a una variable valida si el valor es un entero
	o un float o constante.
*/
class VariableManager {
public:
	VariableManager() {};

	//feature C++ V11 - Autodeduccion de Tipos de Datos
	void requestVariable(string& variable);


};
#endif // !VARIABLE_MANAGER