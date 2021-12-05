#include "constantes.h"

//Constructor sin parametros.
Constantes::Constantes() {
	name = "";
	value = 0;
}


//Sobrecarga de operadores de escritura ostream
ostream& operator<<(ostream& stream, const Constantes& data) {
	stream
		<< data.name
		<< "="
		<< data.value
		<< "\n";
	return stream;
}


//Sobrecarga de operadores de lectura istream
istream& operator>>(istream& stream, Constantes& data) {
	//Nombre de la Constante
	char _name[32];
	stream.getline(_name, 32, '=');
	data.name = _name;

	//Valor de la Constante
	char _value[8];
	stream.getline(_value, 8, '\n');
	data.value = atof(_value);
	return stream;
}


void Constantes::print() {
	cout << "Constante: " << this->name << " = " << this->value << "\n";
}