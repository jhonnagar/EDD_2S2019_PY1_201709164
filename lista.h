#pragma once

class lista

{
private:
	typedef struct nodo {
		int data;
		nodo* siguiente;
	}*nodoptr;

	nodoptr cabeza;
	nodoptr fin;
	nodoptr temp;
public:
	lista();

	void agregarinicio(int adddata);
	void eliminar(int data );
	void mostrar();
};

