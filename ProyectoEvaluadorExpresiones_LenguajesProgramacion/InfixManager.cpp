#include "InfixManager.h"

InfixManager::InfixManager(string _rootExpresion) {
    Validaciones validador;
	this->rootExpresion = _rootExpresion;
    convert();
    this->valid = validador.validarExpresion(this->infixExpresion);
}

void InfixManager::convert() {
	this->infixExpresion = new vector<string>;
    Validaciones validador;
    string campoAux = "";

    auto toString = [](char a) {
        string s(1, a);
        return s;
    };

	for (int i = 0; i < this->rootExpresion.size(); i++) {
        if (validador.esSimbolo(toString(rootExpresion[i])) && campoAux.compare("") == 0) {
            this->infixExpresion->push_back(toString(rootExpresion[i]));
        }
        else if (validador.esSimbolo(toString(rootExpresion[i])) && campoAux.compare("") != 0) {
            this->infixExpresion->push_back(campoAux);
            this->infixExpresion->push_back(toString(rootExpresion[i]));
            campoAux = "";
        }
        else if (isalnum(rootExpresion[i])) {
            campoAux += rootExpresion[i];

            if(i == this->rootExpresion.size()-1)
                this->infixExpresion->push_back(campoAux);
        }                
	}
}

string InfixManager::getRootExpresion() {
	return this->rootExpresion;
}

vector<string>* InfixManager::getInfixExpresion() {
	return this->infixExpresion;
}