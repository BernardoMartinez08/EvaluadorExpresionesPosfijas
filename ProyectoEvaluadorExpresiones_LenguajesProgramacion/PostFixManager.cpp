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
		pila->print();
		//Si es un numero agregar a la expresion		
		if (validador.esFloat(this->infixExpresion->at(i)) || validador.esInt(this->infixExpresion->at(i))) {
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
			pila->print();
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

}


vector<string>* PostFixManager::getInfixExpresion() {
	return this->infixExpresion;
}


vector<string>* PostFixManager::getPostfixExpresion() {
	return this->postfixExpresion;
}