#include "Validaciones.h"

Validaciones::Validaciones() {

}

bool Validaciones::validarExpresion(vector<string>* expresion) {
    if (expresion->empty()) {
        cout << "\nExpresion Vacia!!!*\n";
        return false;
    }

    bool esValid = false;

    if (esSimbolo(expresion->at(0))) {
        cout << "\nExpresion No puede comenzar con un simbolo!!!*\n";
        return false;
    }else if (esSimbolo(expresion->at(expresion->size()-1))) {
        cout << "\nExpresion No puede Finalizar con un simbolo!!!*\n";
        return false;
    }

    for (int i = 0; i < expresion->size(); i++) {
        if (esFloat(expresion->at(i))) {
            cout << "\nEs Float*\n";
            esValid = true;
        }
        else if (esInt(expresion->at(i))) {
            cout << "\nEs Entero*\n";
            esValid = true;
        }
        else if (esSimbolo(expresion->at(i))){
            cout << "\nEs Simbolo*\n";
            esValid = false;
        }
        else if (esVariable(expresion->at(i))) {
            cout << "\nEs Variable*\n";
            esValid = true;
        }
        else if (esConstante(expresion->at(i))) {
            cout << "\nEs Constante*\n";
            esValid = true;
        }
        else if (esParentisisIzq(expresion->at(i)) && esValid == true) {
            cout << "\nEs Parentesis Izquiedo*\n";
            esValid = false;
        }
        else if (esParentisisDer(expresion->at(i)) && esValid == false) {
            cout << "\nEs Parentesis Izquiedo*\n";
            esValid = true;
        }
        else
            esValid = false;
    }

    return esValid;
}

bool Validaciones::esFloat(string valor) {
    while (valor.size() > 1 && valor[0] == ' ') {
        valor.erase(valor.begin());
    }

    int ini = valor[0] == '-';

    for (int i = ini; i < valor.size(); i++) {
        if (isdigit(valor[i]) || valor[i] == '.') {
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
        if (isdigit(valor[i])) {
            continue;
        }
        else {
            return false;
        }
    }

    return true;
}

bool Validaciones::esParentisisIzq(string valor) {
    while (valor.size() > 1 && valor[0] == ' ') {
        valor.erase(valor.begin());
    }

    int ini = valor[0] == '-';

    for (int i = ini; i < valor.size(); i++) {
        if (valor[i] == '(') {
            continue;
        }
        else {
            return false;
        }
    }

    return true;
}

bool Validaciones::esParentisisDer(string valor) {
    while (valor.size() > 1 && valor[0] == ' ') {
        valor.erase(valor.begin());
    }

    int ini = valor[0] == '-';

    for (int i = ini; i < valor.size(); i++) {
        if (valor[i] == ')') {
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
        if (isalpha(valor[i])) {
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
        if (isalpha(valor[i])) {
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