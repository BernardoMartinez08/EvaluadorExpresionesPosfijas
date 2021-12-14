#include "VariableManager.h"

void VariableManager::requestVariable(string& variable) {
	bool esValida = false;
	Validaciones validador;

	while (esValida == false) {
		cout << "\nIngrese el valor para la variable [ " << variable << " ]: ";
		variable = "";
		cin >> variable;

		//Feature de C++ V17 Inicializadores dento de sentencias if
		if (bool _valid = validador.esFloat(variable) ; _valid == true)
			esValida = true;
		else if (bool _valid = validador.esInt(variable); _valid == true)
			esValida = true;
		else if (bool _valid = validador.esConstante(variable); _valid == true)
			esValida = true;
		else
			esValida = false;
	}
}