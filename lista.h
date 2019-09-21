#pragma once
#include"Matrix.h"
using namespace std;
class lista

{
private:
	typedef struct nodo {
		Matrix data;
		int alto=NULL;
		int ancho=NULL;
		int pixelx = NULL;
		int pixely = NULL;
		string nombre;
		nodo* siguiente = NULL;
	}*nodoptr;


public:
	lista();
	nodoptr cabeza;
	nodoptr fin;
	nodoptr temp;
	string getnombre();

	void agregarinicio(Matrix adddata,std::string name);
	void config(int ancho, int alto, int px, int py, std::string nomb);
	void mostrar(std::string name);
};

