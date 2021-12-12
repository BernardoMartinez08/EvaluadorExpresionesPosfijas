#pragma once
#ifndef CONSTANTE_MANAGER_H
#define CONSTANTE_MANAGER_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
#include "constantes.h"

using namespace std;

class ConstanteManager {
public:
	ConstanteManager() {};
	vector<Constantes>* cargarArchivoConstantes();
	void agregarConstante();
	Constantes buscarConstante(string _nombreVariable);

};
#endif // !CONSTANTE_MANAGER_H