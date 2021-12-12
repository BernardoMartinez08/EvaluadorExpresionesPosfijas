#pragma once
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
#include "Stack.h"
#include "ConstantesManager.h"

using namespace std;

class Validaciones {
public:
	Validaciones();

	bool validarExpresion(Stack<string>*);

	bool esFloat(string);
	bool esVariable(string);
	bool esConstante(string);
	bool esInt(string);
	bool esSimbolo(string);

	bool errorParentesis(Stack<string>*);
	bool expresionNoValida(Stack<string>*);

	bool denominadorCero(string, string);
};
#endif // !VALIDACIONES_H