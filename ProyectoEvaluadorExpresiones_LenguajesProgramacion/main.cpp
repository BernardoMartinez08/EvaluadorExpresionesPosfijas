#include <conio.h>
#include <iostream>
#include <string>
#include "InfixManager.h"
#include "PostFixManager.h"
#include "ConstantesManager.h"
#include "constantes.h"

using namespace std;


int main() {
	int opcion = 0;
	vector<string> historial;

	while (opcion != 5) {
		cout << "\n\n\n********* E V A L U A D O R  D E  E X P R E S I O N E S *********\n\n";

		cout << "1.Agregar Constantes.\n2.Ver todas las Constantes.\n3.Evaluar una Expresion.\n4.Historial de Evaluaciones\n5.Salir\n ";
		cout << "Ingrese una opcion:";
		cin >> opcion;

		cout << "\n";

		switch (opcion)
		{
		case 1: {
			cout << "\n\n********* A G R E G A R  C O N S T A N T E S *********\n";
			ConstanteManager constantes_manager;
			constantes_manager.agregarConstante();

			break;

		}case 2: {
			cout << "\n\n********* L I S T A D O  D E  C O N S T A N T E S *********\n";
			ConstanteManager constantes_manager;
			vector<Constantes>* constantes = constantes_manager.cargarArchivoConstantes();

			for (int i = 0; i < constantes->size(); i++) {
				constantes->at(i).print();
			}

			break;

		}case 3: {
			cout << "\n\n********* E V A L U A  E X P R E S I O N E S *********\n";
			string expresion;
			cout << "\nIngrese una Expresion en formato infijo: ";
			cin >> expresion;

			InfixManager InfiExpresion(expresion);

			cout << "\n\nProcesando Expresion Ingresada........\n\n\nExpresion en formato Infijo:\n";
			for (int i = 0; i < InfiExpresion.getInfixExpresion()->size(); i++) {
				cout << "[ " << InfiExpresion.getInfixExpresion()->at(i) << " ] ";
			}

			cout << "\n\n\n\nVerificando Validez de la Expresion Ingresada........\n";
			if (InfiExpresion.isValid())
				cout << "\nLa Expresion Ingresada: ES VALIDA.\n";
			else
				cout << "\nLa Expresion Ingresada: NO ES VALIDA!!!\n";

			if (InfiExpresion.isValid()) {
				cout << "\n\n\nConvirtiendo la Expresion Ingresada a Expresion Postfija........\n";
				cout << "\n\nEvaluando la Expresion Ingresada........\n\n\n\nExpresion en formato Posfijo:\n\n";
				PostFixManager PostfixExpresion(InfiExpresion.getInfixExpresion());
				vector<string>* postfixAux = PostfixExpresion.getPostfixExpresion();

				for (int i = 0; i < postfixAux->size(); i++) {
					cout << "[ " << postfixAux->at(i) << " ] ";
				}

				string resultado = "\nEl resultado de la expresion : " + expresion + " es igual a : " + PostfixExpresion.getResult();
				cout << "\n\n" << resultado;
				historial.push_back(resultado);
			}

			break;

		}case 4:{
			cout << "\n\n********* H I S T O R I A L  E X P R E S I O N E S *********\n";

			if (historial.empty())
				cout << "\n\nLista Vacia!!";
			else {
				for (int i = 0; i < historial.size(); i++) {
					cout << "\n" << historial[i];
				}
			}

			break;

		}case 5: {
			cout << "\nSaliendo....\nGRACIAS POR UTILIZAR ESTE EVALUADOR.\n";
			break;
		}default: {
			cout << "\nOPCION NO VALIDA";
			break;
		}
		}
	}
	_getch();
}