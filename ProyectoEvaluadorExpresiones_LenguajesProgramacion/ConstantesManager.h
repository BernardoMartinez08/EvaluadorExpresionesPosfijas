#pragma once
#ifndef CONSTANTE_MANAGER
#define CONSTANTE_MANAGER

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "constantes.h"

using namespace std;

class ConstanteManager {
public:
	ConstanteManager() {};

	vector<Constantes>* cargarArchivoConstantes() {
		string file_name = "constantes.bin";
		ifstream file(file_name, ios::in);

		if (file)
			cout << "\nImporando Constantes.......\n";
		else if (!file) {
			cout << "\nError al Importar Constantes.......\n";
			return nullptr;
		}


		vector<Constantes>* constantes_importadas = new vector<Constantes>;

		while (!file.eof()) {
			Constantes aux;
			file >> aux;
			constantes_importadas->push_back(aux);
		}
		file.close();

		return constantes_importadas;
	};

	void agregarConstante() {
		string file_name = "constantes.bin";
		ofstream file(file_name, ios::out | ios::app | ios::binary);

		cout << "\nIngrese el nombre para la variable: ";
		string variable = "";
		cin >> variable;

		cout << "\nIngrese el valor para la variable [ " << variable << " ] : ";
		int valor = 0;
		cin >> valor;

		Constantes aux(variable, valor);
		file << aux;
		file.close();
	};


};
#endif // !CONSTANTE_MANAGER