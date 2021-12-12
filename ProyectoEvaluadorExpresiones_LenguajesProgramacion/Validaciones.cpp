#include "Validaciones.h"

Validaciones::Validaciones() {

}

bool Validaciones::validarExpresion(Stack<string>* expresion) {
    if (expresion->isEmpty()) {
        cout << "\nExpresion Vacia!!!*\n";
        return false;
    }

    StackNode<string>* actual = expresion->top;
    bool esValid = false;

    while (actual != nullptr) {
        if (esFloat(actual->data)) {
            cout << "\nEs Float*\n";
            esValid = true;
        }
        else if (esInt(actual->data)) {
            cout << "\nEs Entero*\n";
            esValid = true;
        }
        else if (esSimbolo(actual->data)){
            cout << "\nEs Simbolo*\n";
            esValid = true;
        }
        else if (esVariable(actual->data)) {
            cout << "\nEs Variable*\n";
            esValid = true;
        }
        else if (esConstante(actual->data)) {
            cout << "\nEs Constante*\n";
            esValid = true;
        }else
            esValid = false;

        actual = actual->next;
    }

    return esValid;
}

bool Validaciones::esFloat(string valor) {
    while (valor.size() > 1 && valor[0] == ' ') {
        valor.erase(valor.begin());
    }

    int ini = valor[0] == '-';

    for (int i = ini; i < valor.size(); i++) {
        if (isdigit(valor[0]) || valor[i] == '.') {
            continue;
        }
        else {
            return false;
        }
    }

    if (valor.find('.') != std::string::npos)
        return true;
    else
        return false;

    return true;
}

bool Validaciones::esInt(string valor) {
    while (valor.size() > 1 && valor[0] == ' ') {
        valor.erase(valor.begin());
    }

    int ini = valor[0] == '-';

    for (int i = ini; i < valor.size(); i++) {
        if (isdigit(valor[0])) {
            continue;
        }
        else {
            return false;
        }
    }

    return true;
}

bool Validaciones::esSimbolo(string valor) {
    while (valor.size() > 1 && valor[0] == ' ') {
        valor.erase(valor.begin());
    }

    int ini = valor[0] == '-';

    for (int i = ini; i < valor.size(); i++) {
        if (valor[i] == '*' || valor[i] == '/' || valor[i] == '%' || valor[i] == '^' || valor[i] == '-' || valor[i] == '+' || valor[i] == '(' || valor[i] == ')') {
            continue;
        }
        else {
            return false;
        }
    }

    return true;
}

bool Validaciones::esVariable(string valor) {
    while (valor.size() > 1 && valor[0] == ' ') {
        valor.erase(valor.begin());
    }

    int ini = valor[0] == '-';

    for (int i = ini; i < valor.size(); i++) {
        if (isalpha(valor[0])) {
            continue;
        }
        else {
            return false;
        }
    }

    ConstanteManager buscador;
    Constantes constAux = buscador.buscarConstante(valor);

    if (constAux.name != "" && constAux.value != 0) {
        return false;
    }
    else {
        return true;
    }

    return true;
}

bool Validaciones::esConstante(string valor) {
    while (valor.size() > 1 && valor[0] == ' ') {
        valor.erase(valor.begin());
    }

    int ini = valor[0] == '-';

    for (int i = ini; i < valor.size(); i++) {
        if (isalpha(valor[0])) {
            continue;
        }
        else {
            return false;
        }
    }

    ConstanteManager buscador;
    Constantes constAux = buscador.buscarConstante(valor);

    if (constAux.name == "" && constAux.value == 0) {
        return false;
    }
    else {
        return true;
    }

    return true;
}