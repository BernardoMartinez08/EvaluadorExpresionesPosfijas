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

class Conversiones {
public:
	Conversiones();

	float toFloat(string);
	auto toVariable(string);
	Constantes toConstante(string);
	int toInt(string);
	char toSimbolo(string);
};
#endif // !CONVERSIONES_H