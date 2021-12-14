#pragma once
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
#include "Stack.h"
#include "VariableManager.h"
#include "ConstantesManager.h"

using namespace std;

/*
	Clase Validaciones es una clase que recopila las funciones que nos permiten
	realizar las validaciones sobre la expresion, vas validaciones son, si un datos
	es un valor (entero o flotante) una variable, una constante, o un simbolo.

	Estas funciones son utilizadas en multiples operaciones por tanto tenerlas
	recopiladas en un solo lugar para su uso eficiente es de mucha ayuda.
*/
class Validaciones {
public:
	Validaciones();

	//Valida una expresion completa.
	bool validarExpresion(vector<string>*);

	//Valida un componente de la expresion.
	//Valida si un string es un flotante.
	bool esFloat(string);

	//Valida si un string es una Variable.
	bool esVariable(string);

	//Valida si un string es una constante.
	bool esConstante(string);

	//Valida si un string es un entero.
	bool esInt(string);

	//Valida si un string es un simbolo.
	bool esSimbolo(string);

	//Valida si un string es parentisis izquierdo
	bool esParentisisIzq(string);

	//Valida si un string es parentesis derecho
	bool esParentisisDer(string);

	bool errorParentesis(Stack<string>*);
	bool expresionNoValida(Stack<string>*);
};
#endif // !VALIDACIONES_H