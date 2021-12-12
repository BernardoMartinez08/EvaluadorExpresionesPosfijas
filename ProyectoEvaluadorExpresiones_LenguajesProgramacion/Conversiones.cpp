#include "Conversiones.h"

Conversiones::Conversiones() {

}

float Conversiones::toFloat(string valor) {
    Validaciones validador;
    float _valor = 0;

    if (validador.esFloat(valor)) {
        _valor = std::stof(valor);
    }

    return _valor;
}

int Conversiones::toInt(string valor) {
    Validaciones validador;
    int _valor = 0;

    if (validador.esInt(valor)) {
        _valor = std::stoi(valor);
    }

    return _valor;
}

char Conversiones::toSimbolo(string valor) {
    Validaciones validador;
    char _valor = 0;

    if (validador.esFloat(valor)) {
        _valor = valor[0];
    }

    return _valor;
}

auto Conversiones::toVariable(string valor) {
    Validaciones validador;
    VariableManager variablesManager;
    auto _valor = 0;

    if (validador.esVariable(valor)) {
        variablesManager.requestVariable(_valor);
    }

    return _valor;
}

Constantes Conversiones::toConstante(string valor) {
    Validaciones validador;
    ConstanteManager buscador;
    Constantes _valor("", 0);

    if (validador.esConstante(valor)) {
        _valor = buscador.buscarConstante(valor);
    }

    return _valor;
}