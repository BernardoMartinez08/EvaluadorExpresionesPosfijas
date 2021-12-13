#include <conio.h>
#include <iostream>
#include "Stack.h"
#include <string>
#include <fstream>
#include "constantes.h"
#include "Operaciones.h"
#include "VariableManager.h"
#include "ConstantesManager.h"
#include <any>
#include "Validaciones.h"
#include "InfixManager.h"

using namespace std;


int main() {
	//Prueba de Archivo de Constantes
	/*ConstanteManager constantManager;
	vector<Constantes>* constantes = constantManager.cargarArchivoConstantes();

	if (constantes != nullptr) {
		for (int i = 0; i < constantes->size(); i++)
			constantes->at(i).print();
	}


	//Prueba de Pila
	Stack<int> st;

	st.push(4);
	st.push(3);
	st.push(7);
	st.push(2);
	st.push(1);
	st.push(8);
	st.push(10);
	st.push(33);
	st.push(12);
	st.push(13);
	st.push(17);

	st.print();

	st.pop();
	st.pop();
	st.print();

	Stack<string> st2;

	st2.push("Carlos");
	st2.push("Maria");
	st2.push("Esteban");
	st2.push("Carolina");
	st2.push("Bernardo");

	st2.print();
	cout << "\nTope de la Fila: " << st.peek() << "\n";


	//Prueba de Operaciones
	Operaciones operador;
	int suma = operador.suma(2, 4);
	cout << "\nLa suma es: " << suma;

	float suma2 = operador.suma(2, 4.5f);
	cout << "\nLa suma es: " << suma2;



	//Prueba de Variables
	VariableManager variables;
	string a = "a";
	variables.requestVariable(a);
	cout << "el valor asignado a la variable fue: " << a;

	auto x = std::any(1);
	std::cout << "\n";
    std::cout << x.type().name() << ": " << std::any_cast<int>(x) << '\n';
    x = 3.14;
    std::cout << x.type().name() << ": " << std::any_cast<double>(x) << '\n';
    x = true;
    std::cout << x.type().name() << ": " << std::any_cast<bool>(x) << '\n';
	x = string("Hola Mundo");
	std::cout << x.type().name() << ": " << std::any_cast<string>(x) << '\n';
	*/


	/*vector<string>* expresion = new vector<string>;

	expresion->push_back("/");
	expresion->push_back("10");
	expresion->push_back("+");
	expresion->push_back("45");
	expresion->push_back("*");
	expresion->push_back("a");
	expresion->push_back("%");
	expresion->push_back("pi");
	expresion->push_back("/");
	expresion->push_back("33.4");

	for (int i = 0; i < expresion->size(); i++) {
		cout << "[ " << expresion->at(i) << " ]\n";
	}

	Validaciones validador;
	bool esValid = validador.validarExpresion(expresion);

	if (esValid)
		cout << "\nLa Expresion SI es Valida.\n";
	else
		cout << "\nLa Expresion NO es Valida.\n";*/

	string expresion = "23+783/773*63+pi";
	string expresion2 = "23+783/773*63+";
	string expresion3 = "+783/773*63+pi";

	auto toString = [](char a) {
		string s(1, a);
		return s;
	};


	InfixManager InfiExpresion(expresion);
	InfixManager InfiExpresion2(expresion2);
	InfixManager InfiExpresion3(expresion3);

	cout << "\nExpresion 1\n";
	for (int i = 0; i < InfiExpresion.getInfixExpresion()->size(); i++) {
		cout << "[ " << InfiExpresion.getInfixExpresion()->at(i) << " ]\n";
	}
	cout << "\nExpresion 2\n";
	for (int i = 0; i < InfiExpresion2.getInfixExpresion()->size(); i++) {
		cout << "[ " << InfiExpresion2.getInfixExpresion()->at(i) << " ]\n";
	}
	cout << "\nExpresion 3\n";
	for (int i = 0; i < InfiExpresion3.getInfixExpresion()->size(); i++) {
		cout << "[ " << InfiExpresion3.getInfixExpresion()->at(i) << " ]\n";
	}

	if (InfiExpresion.isValid())
		cout << "\nLa Expresion 1 SI es Valida.\n";
	else
		cout << "\nLa Expresion 1 NO es Valida.\n";

	if (InfiExpresion2.isValid())
		cout << "\nLa Expresion 1 SI es Valida.\n";
	else
		cout << "\nLa Expresion 1 NO es Valida.\n";

	if (InfiExpresion3.isValid())
		cout << "\nLa Expresion 1 SI es Valida.\n";
	else
		cout << "\nLa Expresion 1 NO es Valida.\n";

 
	_getch();
}