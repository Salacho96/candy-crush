#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Terminal{
	public:
		Terminal();
		~Terminal();
		vector<string> leerMovimiento();
		void limpiarPantalla();
		void cerrar();
};

#endif
