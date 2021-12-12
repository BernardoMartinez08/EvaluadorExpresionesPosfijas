#pragma once
#ifndef INFIX_MANAGER
#define INFIX_MANAGER

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
#include "Stack.h"

using namespace std;

class InfixManager {
public:
	InfixManager(string);
	
	bool convertirInfix(string);

	bool validarExpresion();
	string getRootExpresion();
	Stack<string>* getInfixExpresion();
	
private:
	string rootExpresion = " ";
	Stack<string>* infixExpresion = nullptr;
};
#endif // !INFIX_MANAGER