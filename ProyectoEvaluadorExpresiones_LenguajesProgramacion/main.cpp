#include <conio.h>
#include <iostream>
#include <string>
#include "InfixManager.h"
#include "PostFixManager.h"
#include "ConstantesManager.h"
#include "constantes.h"
#include "pruebas.h"

using namespace std;


int main() {
	int opcion = 0;
	vector<string> historial;

	while (opcion != 6) {
		cout << "\n\n\n********* E V A L U A D O R  D E  E X P R E S I O N E S *********\n\n";

		cout << "1.Agregar Constantes.\n2.Ver todas las Constantes.\n3.Evaluar una Expresion.\n4.Historial de Evaluaciones.\n5.Ejecutar Pruebas de Validacion.\n6.Salir\n ";
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
				cout << "\n\nEvaluando la Expresion Ingresada........";

				PostFixManager PostfixExpresion(InfiExpresion.getInfixExpresion());
				vector<string>* postfixAux = PostfixExpresion.getPostfixExpresion();

				cout << "\n\n\n\nExpresion en formato Posfijo:\n\n";
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
			cout << "\n\n********* P R U E B A S  U N I T A R I A S *********\n";

			pruebas tester;
			string expresiones[10][2];

			expresiones[0][0] = "2+4*(pi+5)";
			expresiones[0][1] = "34.56637";

			expresiones[1][0] = "10+(1+2)*2";
			expresiones[1][1] = "16";

			expresiones[2][0] = "5+5";
			expresiones[2][1] = "10";

			expresiones[3][0] = "10+12*24";
			expresiones[3][1] = "298";

			expresiones[4][0] = "5-(6*(5+4))/2";
			expresiones[4][1] = "-22";

			expresiones[5][0] = "4/0";
			expresiones[5][1] = "0";

			expresiones[6][0] = "*7+83";
			expresiones[6][1] = "0";

			expresiones[7][0] = "56-8*(10-4)/";
			expresiones[7][1] = "0";

			expresiones[8][0] = "13+873/";
			expresiones[8][1] = "0";

			expresiones[9][0] = "332+89)";
			expresiones[9][1] = "0";

			for (int i = 0; i < 10; i++) {
				if (tester.prueba_unitaria(expresiones[i][0], expresiones[i][1])) {
					cout << "\n\nLa Expresion: " << expresiones[i][0] << " SUPERO LA PRUEBA CON EXITO!!!.\n\n\n\n";
				}
				else {
					cout << "\n\nLa Expresion: " << expresiones[i][0] << " NO SUPERO LA PRUEBA CON EXITO!!!.\n\n\n\n";
				}
			}

			break;

		}case 6: {
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