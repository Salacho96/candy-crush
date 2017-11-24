#include "ficha.h"

using namespace std;

Ficha::Ficha(){x=-1; y=-1;}
Ficha::~Ficha(){}
void Ficha::setSimbolo(char simbolo_){simbolo=simbolo_;}
void Ficha::setEtiqueta(char etiqueta_){etiqueta=etiqueta_;}
char Ficha::getSimbolo(){return simbolo;}
char Ficha::getEtiqueta(){return etiqueta;}
int Ficha::getIndiceI(){return x;}
int Ficha::getIndiceJ(){return y;}
void Ficha::setIndiceI(int x_){x=x_;}
void Ficha::setIndiceJ(int y_){y=y_;}
