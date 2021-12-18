#pragma once
#ifndef PRUEBAS_H
#define PRUEBAS_H

#include "PostFixManager.h"
#include "InfixManager.h"
#include "Conversiones.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class pruebas {
public:
	pruebas() {};

	bool prueba_unitaria(string expresion, string resultado_esperado) {
		Conversiones conversor;
		InfixManager InfixExpresion(expresion);
		
		if (InfixExpresion.isValid()) {
			PostFixManager PostfixExpresion(InfixExpresion.getInfixExpresion());

			string resultado = PostfixExpresion.getResult();

			if (resultado.compare(resultado_esperado)) {
				return true;
			}
			else
				return false;
		}
		else {
			return true;
		}

		return true;
	};
};

#endif // !PRUEBAS_H
