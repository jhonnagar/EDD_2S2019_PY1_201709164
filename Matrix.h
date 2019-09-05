#pragma once
class Matrix
{
private:
	typedef struct nodo {
		int rojo;
		int verde;
		int azul;
		nodo* arri;
		nodo* aba;
		nodo* izqu;
		nodo* der;
	}* nodoptr;

	nodoptr cabeza;
	nodoptr finder;
	nodoptr finaba;
	nodoptr temp;
public: 
	Matrix();

};

