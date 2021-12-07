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

using namespace std;


int main() {
	//Prueba de Archivo de Constantes
	ConstanteManager constantManager;
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

	/*auto x = std::any(11);
	x = std::string("You are beautiful :)");
	x = 12.0;*/

	_getch();
}