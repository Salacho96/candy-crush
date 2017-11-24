#include "tablero.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

Ficha** Tablero::getMatriz(){return matriz;}

Tablero::Tablero(){
	srand(time(NULL));
	char tmp[5]={'1', '2', '3', '4', '5'};
	nFilas=5;
	nCols=5;
	int random=0;
	matriz=(Ficha**)malloc(sizeof(Ficha*)*nFilas);
	for(int i=0; i<nFilas; i++){
		matriz[i]=(Ficha*)malloc(sizeof(Ficha)*nCols);
		for(int j=0; j<nCols; j++){
			Ficha ficha;
			random=rand()%5;
			ficha.setSimbolo(tmp[random]);
			ficha.setEtiqueta(ficha.getSimbolo());
			ficha.setIndiceI(i);
			ficha.setIndiceJ(j);
			matriz[i][j]=ficha;
		}
	}
}
Tablero::~Tablero(){}

void Tablero::dibujarse(){
	for(int i=0; i<nFilas; i++){
		for(int j=0; j<nCols; j++){
			cout<<" "<<matriz[i][j].getSimbolo();
		}
		cout<<endl;
	}
}
vector<Ficha> Tablero::buscarTripletaFila(int i){
	vector<Ficha> tripletas;
	int c=1;
	for(int j=0; j<nCols-1; j++){
		if(matriz[i][j].getSimbolo()==matriz[i][j+1].getSimbolo()){
			tripletas.push_back(matriz[i][j]);
			c++;
			if(c==3){
				tripletas.push_back(matriz[i][j+1]);
				return tripletas;
			}
		}else{
			if(c>1){
				tripletas.clear();
			}
			c=1;
		}
	}
	return tripletas;
}

vector<Ficha> Tablero::buscarTripletaCol(int j){
	vector<Ficha> tripletas;
	int c=1;
	for(int i=0; i<nFilas-1; i++){
		if(matriz[i][j].getSimbolo()==matriz[i+1][j].getSimbolo()){
			tripletas.push_back(matriz[i][j]);
			c++;
			if(c==3){
				tripletas.push_back(matriz[i+1][j]);
				return tripletas;
			}
		}else{
			if(c>1){
				tripletas.clear();
			}
			c=1;
		}
	}
	return tripletas;
}

void Tablero::cambiarFicha(Ficha ficha_){
	matriz[ficha_.getIndiceI()][ficha_.getIndiceJ()]=ficha_;
}

void Tablero::cambiarFicha(char simbolo, char etiqueta, int x, int y){
	Ficha f;
	f.setSimbolo(simbolo);
	f.setEtiqueta(etiqueta);
	f.setIndiceI(x);
	f.setIndiceJ(y);
	matriz[x][y]=f;
}

void Tablero::cambiarTripleta(vector<Ficha> tripleta){	
	for(int i=0; i<3; i++){
		cambiarFicha(tripleta[i]);
	}
}

Ficha Tablero::getFicha(int i, int j){
	return matriz[i][j];
}

void Tablero::setMatriz(Ficha** m){
	matriz=m;
}
