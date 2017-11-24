#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <string>
#include <vector>
#include "ficha.h"


using namespace std;

class Tablero{
	private:
		int nFilas;
		int nCols;
		static string cadSimbolo;
		Ficha** matriz;
	public:
		Tablero();
		Tablero(int nFilas_, int nCols_);
		~Tablero();
		void dibujarse();
		void cambiarSimbolos(char e1, char e2);
		vector<Ficha> buscarTripletaFila(int i);
		vector<Ficha> buscarTripletaCol(int j);
		void cambiarTripleta(vector<Ficha> fila);
		void cambiarTripletaCol(vector<Ficha> col);
		Ficha** getMatriz();
		void setMatriz(Ficha** matriz_);
		void cambiarFicha(Ficha ficha_);
		Ficha getFicha(int i, int j);
		void cambiarFicha(char simbolo, char etiqueta, int x, int y);
};

#endif
