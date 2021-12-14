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
private:
	//Feature de C++ V11 - Designacion de constante a puntero nulo
	vector<string>* infixExpresion = nullptr;
	vector<string>* postfixExpresion = nullptr;

	string result = "";

	void convert();
	int precedence(string);
	void evaluate();
};
#endif // !POSTFIX_MANAGER_H