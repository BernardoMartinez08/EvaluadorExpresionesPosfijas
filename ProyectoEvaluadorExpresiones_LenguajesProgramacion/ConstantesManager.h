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

/*
	Clase ConstanteManager nos permite cargar el archivo de Constantes y atraves
	de la clase Constantes nos permite hacer la extraccion de los datos del 
	archivo para su recorrido o cargar todo el archivo.
*/
class ConstanteManager {
public:
	ConstanteManager() {};
	vector<Constantes>* cargarArchivoConstantes();
	void agregarConstante();
	Constantes buscarConstante(string _nombreVariable);

};
#endif // !CONSTANTE_MANAGER_H