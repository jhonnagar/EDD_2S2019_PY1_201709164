#pragma once
#include"Matrix.h"
class lista

{
private:
	typedef struct nodo {
		Matrix data;
		nodo* siguiente;
	}*nodoptr;

	nodoptr cabeza;
	nodoptr fin;
	nodoptr temp;
public:
	lista();

	void agregarinicio(Matrix adddata);
	void mostrar();
};

