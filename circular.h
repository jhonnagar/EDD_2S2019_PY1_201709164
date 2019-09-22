#pragma once
#include"lista.h"
using namespace std;
class circular
{
	private:
	typedef struct nodo {
		lista data;
		int pos;
		string nombre;
		nodo* sig=NULL;
		nodo* ant=NULL;
	}*nodoptr;
public:
	circular();
	void borrar();
	int numero;
	nodoptr cabeza;
	nodoptr fin;
	nodoptr temp;
	void agregar(lista adddata, std::string name);

};

