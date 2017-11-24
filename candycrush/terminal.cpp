#include "terminal.h"

using namespace std;

Terminal::Terminal(){}
Terminal::~Terminal(){}
vector<string> Terminal::leerMovimiento(){
	vector<string> ordenes;
	string accion="";
	string dir="";
	string x="0";
	string y="0";
	cin>>accion>>dir>>x>>y;
	ordenes.push_back(accion);
	ordenes.push_back(dir);
	ordenes.push_back(x);
	ordenes.push_back(y);
	return ordenes;
}
