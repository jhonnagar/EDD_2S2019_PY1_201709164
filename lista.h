#pragma once
#include"Matrix.h"
class lista

{
private:
	typedef struct nodo {
		Matrix data;
		int alto=NULL;
		int ancho=NULL;
		int pixelx = NULL;
		int pixely = NULL;
		nodo* siguiente = NULL;
	}* nodoptr;

	nodoptr cabeza;
	nodoptr fin;
	nodoptr temp;
public:
	lista();

	void agregarinicio(Matrix adddata);
	void config(int ancho, int alto, int px, int py);
	void mostrar();
};

