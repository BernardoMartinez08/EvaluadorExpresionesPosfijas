#pragma once
#ifndef POSTFIX_MANAGER_H
#define POSTFIX_MANAGER_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
#include "Stack.h"
#include "Validaciones.h"
#include "Conversiones.h"
#include "Operaciones.h"

using namespace std;
/*
	
*/
class PostFixManager {
public:
	PostFixManager(vector<string>*);

	vector<string>* getInfixExpresion();
	vector<string>* getPostfixExpresion();


	//feature C++ V11 - Autodeduccion de Tipos de Datos
	auto getResult() { return this->result; };

	//Feature de C++ V11 - Designacion de constante a puntero nulo
	vector<string>* infixExpresion = nullptr;
	vector<string>* postfixExpresion = nullptr;

	string result = "";

	void convert();
	int precedence(string);
	void evaluate();
	float operate(auto operando1, auto operando2, string operador);
};


#endif // !POSTFIX_MANAGER_H