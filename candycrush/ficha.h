#ifndef _FICHA_H_
#define _FICHA_H_

#include <string>

using namespace std;

class Ficha{
	private:
		char simbolo;
		char etiqueta;
		int x, y;
	public:
		Ficha();
		Ficha(char simbolo_, char etiqueta_);
		~Ficha();
		char getSimbolo();	
		char getEtiqueta();
		void setSimbolo(char simbolo_);
		void setEtiqueta(char etiqueta_);
		int getIndiceI();
		int getIndiceJ();
		void setIndiceI(int x_);
		void setIndiceJ(int y_);
};

#endif
