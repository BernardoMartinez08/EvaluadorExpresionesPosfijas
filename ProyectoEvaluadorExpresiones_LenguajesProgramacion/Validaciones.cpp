#include "Validaciones.h"

Validaciones::Validaciones() {

}

bool Validaciones::validarExpresion(vector<string>* expresion) {
    //Feature de C++ V17 Inicializadores dento de sentencias if
    if (bool _vacio = expresion->empty(); _vacio == true) {
        cout << "\nExpresion Vacia!!!*\n";
        return false;
    }

    bool esValid = false;

    //Feature de C++ V17 Inicializadores dento de sentencias if
    if (bool _valid = esSimbolo(expresion->at(0)); _valid == true) {
        cout << "\nExpresion No puede comenzar con un simbolo!!!*\n";
        return false;
    }
    //Feature de C++ V17 Inicializadores dento de sentencias if
    else if (bool _valid = esSimbolo(expresion->at(expresion->size() - 1)); _valid == true) {
        cout << "\nExpresion No puede Finalizar con un simbolo!!!*\n";
        return false;
    }

    for (int i = 0; i < expresion->size(); i++) {
        //Feature de C++ V17 Inicializadores dento de sentencias if
        if (bool _valid = esFloat(expresion->at(i)); _valid == true) {
            esValid = true;
        }
        //Feature de C++ V17 Inicializadores dento de sentencias if
        else if (bool _valid = esInt(expresion->at(i)); _valid == true) {
            esValid = true;
        }
        //Feature de C++ V17 Inicializadores dento de sentencias if
        else if (bool _valid = esSimbolo(expresion->at(i)); _valid == true) {
            esValid = false;
        }
        //Feature de C++ V17 Inicializadores dento de sentencias if
        else if (bool _valid = esVariable(expresion->at(i)); _valid == true) {
            VariableManager manager;
            manager.requestVariable(expresion->at(i));
            esValid = true;
        }
        //Feature de C++ V17 Inicializadores dento de sentencias if
        else if (bool _valid = esConstante(expresion->at(i)); _valid == true) {
            ConstanteManager buscador;
            Constantes constAux = buscador.buscarConstante(expresion->at(i));

            if (constAux.name == "" && constAux.value == 0) {
                expresion->at(i) = "0";
            }
            else {
                expresion->at(i) = to_string(constAux.value);
            }

            esValid = true;
        }
        else if (esParentisisIzq(expresion->at(i)) && esValid == true) {
            esValid = false;
        }
        else if (esParentisisDer(expresion->at(i)) && esValid == false) {
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