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
		if (validador.esFloat(this->infixExpresion->at(i)) || validador.esInt(this->infixExpresion->at(i))) {
			postfixExpresion->push_back(this->infixExpresion->at(i));
		}
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && pila->isEmpty()) {
			pila->push(this->infixExpresion->at(i));
		}
		else if (validador.esParentisisIzq(this->infixExpresion->at(i))) {
			pila->push(this->infixExpresion->at(i));
		}
		else if (validador.esParentisisDer(this->infixExpresion->at(i))) {
			StackNode<string>* actual = pila->top;

			while (actual != nullptr && validador.esParentisisIzq(actual->data)) {
				this->postfixExpresion->push_back(actual->data);
				pila->pop();
				actual = actual->next;
			}
		}
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && precedence(this->infixExpresion->at(i)) == precedence(pila->peek())) {
			postfixExpresion->push_back(pila->peek());
			pila->pop();
			pila->push(this->infixExpresion->at(i));
		}
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && precedence(this->infixExpresion->at(i)) > precedence(pila->peek())) {
			pila->push(this->infixExpresion->at(i));
		}
		else if (validador.esSimbolo(this->infixExpresion->at(i)) && precedence(this->infixExpresion->at(i)) < precedence(pila->peek())) {
			postfixExpresion->push_back(pila->peek());
			pila->pop();
			pila->push(this->infixExpresion->at(i));
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