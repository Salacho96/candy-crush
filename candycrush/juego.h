#ifndef _JUEGO_H_
#define _JUEGO_H_

#include <string>
#include <new>
#include "tablero.h"


using namespace std;

class Juego{
	private:
		int puntaje;
		string jugador;
		Tablero* tablero;
	public:
		int numMovimientos;
		Juego();
		Juego(string nombre);
		Juego(string nombre_, int numMovimientos_);
		~Juego();		
		int getPuntaje();
		void reiniciar();
		void aumentarPuntaje(int nCandys);
		int reducirMovimientos();
		void checkTablero();
		void mover(int i, int j, string cmd);
		void play();
		void dibujarse();
		int string2dec(const std::string &str, int base);
		Tablero* getTablero();
};


#endif
