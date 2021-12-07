#pragma once
#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Constantes {
	friend ostream& operator<<(ostream&, const Constantes&);
	friend istream& operator>>(istream&, Constantes&);
public:
	//feature C++ V11 - Incializacion de matriz de miembros
	Constantes(string _name, float _value) : value(_value), name(_name) {};
	//feature C++ V11 - Llamado a un constructor de la misma clase dentro de otro constructor
	Constantes() : Constantes("", 0) {};

	void print();

	//feature C++ V11 - Inicializador de miembros de clase
	string name = "";
	float value = 0;
};
#endif // !CONSTANTES_H

