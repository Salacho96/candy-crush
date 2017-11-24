#ifndef _NUM_ALEATORIO_H_
#define _NUM_ALEATORIO_H_

#include <string>

using namespace std;

class NumAleatorio{
	private:
		string cadSimbolos;
	public:
		NumAleatorio(string cadSimbolos);
		char getSimboloAleatorio();
	
};

#endif
