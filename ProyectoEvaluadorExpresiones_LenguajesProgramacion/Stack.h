#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

//Feature de C++ V14 paso de template <class T> a template <typename T>
template <typename T>
struct StackNode {
	T data;
	StackNode<T>* next;
	StackNode<T>* previous;

	StackNode(const T& _data, StackNode<T>* _next, StackNode<T>* _previous) {
		data = _data;
		next = _next;
		previous = _previous;
	}
};

template <typename T>
class Stack {
public:
	Stack() : top(nullptr) {}

	bool isEmpty();
	void push(T);
	void pop();

	T& peek();
	int size();

	void print();

	//Feature de C++ V11 - Designacion de constante a puntero nulo
	StackNode<T>* top = nullptr;
};


template <typename T>
bool Stack<T>::isEmpty() {
	//Feature de C++ V11 - Designacion de constante a puntero nulo
	return top == nullptr;
}

template <typename T>
void Stack<T>::push(T _data) {
	//Feature de C++ V11 - Designacion de constante a puntero nulo
	StackNode<T>* nuevo = new StackNode<T>(_data, nullptr, nullptr);

	if (isEmpty()) {
		top = nuevo;
	}
	else {
		nuevo->next = top;
		top->previous = nuevo;
		top = nuevo;
	}
}

template <typename T>
void Stack<T>::print() {
	if (isEmpty())
		cout << "LISTA ESTA VACIA.\n";

	StackNode<T>* actual = top;

	cout << "\n***LISTA***\n";
	cout << "Cantidad de elementos: " << size() << " \n\n";

	while (actual != nullptr) {
		cout << "[ " << actual->data << "]\n";
		actual = actual->next;
	}

	cout << "\n";
}

template <typename T>
T& Stack<T>::peek() {
	return top->data;
}

template <typename T>
void Stack<T>::pop() {
	if (isEmpty())
		return;

	StackNode<T>* aux = top;
	top = top->next;
	//Feature de C++ V11 - Designacion de constante a puntero nulo
	top->previous = nullptr;

}

template <typename T>
int Stack<T>::size() {
	if (isEmpty())
		return 0;

	StackNode<T>* actual = top;
	int cantidad = 0;

	while (actual != nullptr) {
		cantidad++;
		actual = actual->next;
	}

	return cantidad;
}
#endif