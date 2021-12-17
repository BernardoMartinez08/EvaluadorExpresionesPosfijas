#include "PostFixManager.h"

PostFixManager::PostFixManager(vector<string>* _infixExpresion) {
	this->infixExpresion = new vector<string>;
	this->infixExpresion = _infixExpresion;
	convert();
	evaluate();
}


void PostFixManager::convert() {
	this->postfixExpresion = new vector<string>;
	Validaciones validador;
	Stack<string>* pila = new Stack<string>;

	for (int i = 0; i < this->infixExpresion->size(); i++) {
		//Si es un numero agregar a la expresion		
		if (validador.esFloat(this->infixExpresion->at(i)) || validador.esInt(this->infixExpresion->at(i)) && this->infixExpresion->at(i) != "-") {
			postfixExpresion->push_back(this->infixExpresion->at(i));
		}
		//Si es un operador y pila esta vacia, agregar operador a la pila
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && pila->isEmpty()) {
			pila->push(this->infixExpresion->at(i));
		}
		//Si es un operador y el top de la pila es parentesis izquierdo, agregar a la pila
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && validador.esParentisisIzq(pila->peek())) {
			pila->push(this->infixExpresion->at(i));
		}
		//Si es un parentesis izquierdo agregar a la pila
		else if (validador.esParentisisIzq(this->infixExpresion->at(i))) {
			pila->push(this->infixExpresion->at(i));
		}
		//Si es parentesis derecho, vaciar la pila hasta encontrar un parentesis izquierdo
		else if (validador.esParentisisDer(this->infixExpresion->at(i))) {
			StackNode<string>* actual = pila->top;

			while (actual != nullptr) {
				if (validador.esParentisisIzq(actual->data) == false) {
					this->postfixExpresion->push_back(actual->data);
					pila->pop();
					actual = actual->next;
				}
				else {
					pila->pop();
					break;
				}
			}
		}
		//Si es operador de igual precedencia sacar el top de la pila y agregarlo a expresion, ademas agregar operador a la pila
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && precedence(this->infixExpresion->at(i)) == precedence(pila->peek())) {
			postfixExpresion->push_back(pila->peek());
			pila->pop();
			pila->push(this->infixExpresion->at(i));
		}
		//Si es un operador de mayor precedecia se agrega a la pila
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && precedence(this->infixExpresion->at(i)) < precedence(pila->peek())) {
			pila->push(this->infixExpresion->at(i));
		}
		//Si es un operador de menor precedencia sacar el top de la pila y agregarlo a la expresion,ademas agregar operador a la pila
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && precedence(this->infixExpresion->at(i)) > precedence(pila->peek())) {
			postfixExpresion->push_back(pila->peek());
			pila->pop();
			pila->push(this->infixExpresion->at(i));
		}

		if (i == (this->infixExpresion->size() - 1)) {
			StackNode<string>* actual = pila->top;

			while (actual != nullptr) {
				
				this->postfixExpresion->push_back(actual->data);
				pila->pop();
				actual = actual->next;
			}
		}
	}
}


int PostFixManager::precedence(string operador) {
	if (operador == "^")
		return 1;
	else if (operador == "*" || operador == "/" || operador == "%")
		return 2;
	else if (operador == "+" || operador == "-") {
		return 3;
	}
}


void PostFixManager::evaluate() {
	Validaciones validador;
	Conversiones convertidor;

	Stack<string>* pila = new Stack<string>;

	for (int i = 0; i < this->postfixExpresion->size(); i++) {
		if (validador.esFloat(this->postfixExpresion->at(i)) || validador.esInt(this->postfixExpresion->at(i)) && this->postfixExpresion->at(i) != "-") {
			pila->push(this->postfixExpresion->at(i));
		}
		
		else if (validador.esSimbolo(this->postfixExpresion->at(i))) {
			string operando1 = pila->peek();
			pila->pop();
			string operando2 = pila->peek();
			pila->pop();

			if (validador.esFloat(operando1) && validador.esFloat(operando2)) {
				float operando1_converted = convertidor.toFloat(operando1);
				float operando2_converted = convertidor.toFloat(operando2);
				
				float resultado = operate(operando1_converted, operando2_converted, postfixExpresion->at(i));
				pila->push(to_string(resultado));
			}
			else if (validador.esFloat(operando1) && validador.esInt(operando2)) {
				float operando1_converted = convertidor.toFloat(operando1);
				float operando2_converted = convertidor.toInt(operando2);

				float resultado = operate(operando1_converted, operando2_converted, postfixExpresion->at(i));
				pila->push(to_string(resultado));
			}
			else if (validador.esInt(operando1) && validador.esFloat(operando2)) {
				float operando1_converted = convertidor.toInt(operando1);
				float operando2_converted = convertidor.toFloat(operando2);

				float resultado = operate(operando1_converted, operando2_converted, postfixExpresion->at(i));
				pila->push(to_string(resultado));
			}
			else if (validador.esInt(operando1) && validador.esInt(operando2)) {
				float operando1_converted = convertidor.toInt(operando1);
				float operando2_converted = convertidor.toInt(operando2);

				float resultado = operate(operando1_converted, operando2_converted, postfixExpresion->at(i));
				pila->push(to_string(resultado));
			}
		}
	}

	if (!pila->isEmpty())
		this->result = pila->peek();
	else
		this->result = "0";
}


float PostFixManager::operate(auto operando1, auto operando2, string operador) {
	Operaciones operaciones;
	Validaciones validador;

	if (operador[0] == '+') {
		return  operaciones.suma(operando1, operando2);
	}
	else if (operador[0] == '-') {
		return  operaciones.resta(operando2, operando1);
	}
	else if (operador[0] == '*') {
		return  operaciones.multiplicacion(operando1, operando2);
	}
	else if (operador[0] == '/') {
		if (operando1 != 0) {
			return  operaciones.divicion(operando2, operando1);
		}
		else {
			cout << "\nPara operaracion divicion el denominador no puede ser 0!!";
			return 0;
		}
	}
	else if (operador[0] == '^') {
		return  operaciones.exp(operando2, operando1);
	}
	else if (operador[0] == '%') {
		if(validador.esInt(to_string(operando1)) && validador.esInt(to_string(operando2)))
			if (operando1 != 0)
				return  operaciones.mod(operando2, operando1);
			else {
				cout << "\nPara operaracion modulo el segundo componente no puede ser 0!!";
				return 0;
			}
		else {
			cout << "\nOperacion modulo no acepta valores de tipo flotante!!";
			return 0;
		}
	}
	else{
		return 0;
	}
}


vector<string>* PostFixManager::getInfixExpresion() {
	return this->infixExpresion;
}


vector<string>* PostFixManager::getPostfixExpresion() {
	return this->postfixExpresion;
}