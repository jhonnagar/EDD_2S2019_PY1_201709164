#pragma once
#include <string>
#include <string>
class Matrix
{
private:
	typedef struct nodo {
		int rojo;
		int verde;
		int azul;
		int x;
		int y;
		nodo* arri;
		nodo* aba;
		nodo* izqu;
		nodo* der;
	}*nodoptr;

	
public:
	nodoptr cabeza;
	nodoptr finder;
	nodoptr finaba;
	nodoptr tempy;
	nodoptr tempx;
	Matrix();

	void nuevacolumna();

	void nuevafila();

	void mostrar();

	void colocarnodo(int rojo, int verde, int azul, int x, int y);


	



};

