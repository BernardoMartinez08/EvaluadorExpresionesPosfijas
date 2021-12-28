#pragma once
#ifndef INFIX_MANAGER_H
#define INFIX_MANAGER_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
#include "Stack.h"
#include "Validaciones.h"

using namespace std;
/*
	Clase InfixManager la cual recopila las funciones referentes a la expresion
	infija entre ellas estan funciones para extraer la expresion base y la que
	resulto de la conversion a infija ademas una funcion para validar si la 
	expresion es valida.

	Existe una funcion privada convert la cual se encarga de tomar la expresion
	en formato base y la convierte a un vector de strings para su tratamiento
	mas sencillo.
*/
class InfixManager {
public:
	InfixManager(string);

	string getRootExpresion();
	vector<string>* getInfixExpresion();
	
	//feature C++ V11 - Autodeduccion de Tipos de Datos
	auto isValid() { return this->valid; };

	string rootExpresion = " ";

	//Feature de C++ V11 - Designacion de constante a puntero nulo
	vector<string>* infixExpresion = nullptr;

	bool valid = false;

	void convert();
};

#endif // !INFIX_MANAGER_H