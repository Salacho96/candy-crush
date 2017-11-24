#include "juego.h"
#include "terminal.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>


using namespace std;

Juego::Juego(){
	tablero=new Tablero();
	puntaje=0;
	numMovimientos=0;
	jugador="banano";
}

Juego::Juego(string nombre_){
	tablero=new Tablero();
	puntaje=0;
	numMovimientos=0;
	jugador=nombre_;
}

Juego::Juego(string nombre_, int numMovimientos_){
	tablero=new Tablero();
	puntaje=0;
	jugador=nombre_;
	numMovimientos=numMovimientos_;
}

Juego::~Juego(){}

void Juego::reiniciar(){
	delete tablero;
	tablero=new Tablero();
	puntaje=0;
	numMovimientos=0;
}

void Juego::mover(int x, int y, string cmd){
	Ficha** m=tablero->getMatriz();
	Ficha f1=m[x][y];
	Ficha f2=m[x][y];
	if(cmd=="down"){
		f2=m[x+1][y];
	}if(cmd=="up"){
		f2=m[x-1][y];
	}if(cmd=="left"){
		f2=m[x][y-1];
	}if(cmd=="right"){
		f2=m[x][y+1];
	}
	char ss=f1.getSimbolo();
	char se=f1.getSimbolo();
	f1.setSimbolo(f2.getSimbolo());
	f1.setEtiqueta(f2.getEtiqueta());
	f2.setSimbolo(ss);
	f2.setEtiqueta(se);
	m[x][y]=f1;
	if(cmd=="down"){
		m[x+1][y]=f2;
	}if(cmd=="up"){
		m[x-1][y]=f2;
	}if(cmd=="left"){
		m[x][y-1]=f2;
	}if(cmd=="right"){
		m[x][y+1]=f2;
	}
	tablero->setMatriz(m);
	numMovimientos++;
	checkTablero();
}	

void Juego::checkTablero(){
	srand(time(NULL));
	char tmp[5]={'1', '2', '3', '4', '5'};
	vector<Ficha> buff;
	vector<Ficha> buff2;
	for(int i=0; i<5; i++){
		buff=tablero->buscarTripletaFila(i);
		if(buff.size()==3){
			Ficha** m=tablero->getMatriz();
			for(int j=0; j<3; j++){
				Ficha f=buff[j];
				f.setSimbolo(tmp[rand()%5]);
				f.setEtiqueta(f.getSimbolo());
				m[buff[j].getIndiceI()][buff[j].getIndiceJ()]=f;
				//cout<<buff[j].getSimbolo()<<" "<<buff[j].getIndiceI()<<""<<buff[j].getIndiceJ()<<endl;
			}
			tablero->setMatriz(m);
			aumentarPuntaje(3);
		}buff.clear();
	}

	for(int i=0; i<5; i++){
		buff=tablero->buscarTripletaCol(i);
		if(buff.size()==3){
			Ficha** m=tablero->getMatriz();
			for(int j=0; j<3; j++){
				Ficha f=buff[j];
				f.setSimbolo(tmp[rand()%5]);
				f.setEtiqueta(f.getSimbolo());
				m[buff[j].getIndiceI()][buff[j].getIndiceJ()]=f;
				//cout<<buff[j].getSimbolo()<<" "<<buff[j].getIndiceI()<<""<<buff[j].getIndiceJ()<<endl;
			}
			tablero->setMatriz(m);
			aumentarPuntaje(3);
		}buff.clear();
	}
}

void Juego::dibujarse(){
	cout<<"Jugador: "<<jugador<<endl;
	cout<<"Puntaje: "<<puntaje<<endl;
	cout<<"Numero de movimientos: "<<numMovimientos<<endl<<endl;
	tablero->dibujarse();
	cout<<"-----------------------------"<<endl;
}	

void Juego::aumentarPuntaje(int nCandys){
	puntaje+=nCandys;
}

Tablero* Juego::getTablero(){
	return tablero;
}

void Juego::play(){
	cout<<"Nombre jugador: ";
	cin>>jugador;
	cout<<"Bienvenido, "<<jugador<<endl;
	string cmd="";
	vector<string> ordenes;
	int x, y;
	dibujarse();
	while(cmd!="exit"){
		cout<<"comando: ";
		Terminal terminal;
		ordenes=terminal.leerMovimiento();
		cmd=ordenes[0];
		if(cmd=="mover" && ordenes.size()==4){
			x=string2dec(ordenes[1], 10);
			y=string2dec(ordenes[2], 10);
			mover(x, y, ordenes[3]);
			dibujarse();
		}
		ordenes.clear();
	}
}

int Juego::string2dec(const std::string &str, int base)
{
	int result = 0;

	if (base < 0 || base > 36)
		return result;

	for (size_t i = 0, mx = str.size(); i < mx; ++i)
	{
		char ch = tolower(str[i]);
		int num = 0;

		if ('0' <= ch && ch <= '9')
			num = (ch - '0');
		else if ('a' <= ch && ch <= 'z')
			num = (ch - 'a') + 10;
		else
			break;
		if (num > base)
			break;
		result = result*base + num;
	}
	return result;
}
