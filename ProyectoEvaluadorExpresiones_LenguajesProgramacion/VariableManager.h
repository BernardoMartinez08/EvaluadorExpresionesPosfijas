#pragma once
#ifndef VARIABLE_MANAGER
#define VARIABLE_MANAGER

#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;

class VariableManager {
public:
	VariableManager() {};

	void requestVariable(string &variable) {
		cout << "\nIngrese el valor para la variable [ " << variable << " ]: ";
		variable = "";
		cin >> variable;
	};


};
#endif // !VARIABLE_MANAGER