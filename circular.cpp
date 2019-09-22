#include "circular.h"
circular::circular() {
	cabeza = NULL;
	fin = NULL;
	temp = NULL;
	numero = 0;
};
void circular::borrar() {
	cabeza = NULL;
	fin = NULL;
	temp = NULL;
	numero = 0;
}
void circular::agregar(lista adddata, std::string name) {
	nodoptr n = new nodo;
	n->data = adddata;
	n->nombre = name;
	numero = numero + 1;
	n->pos = numero;
	if (cabeza == NULL) {
		cabeza = n;
		fin = n;
	}
	else
	{
		fin->sig = n;
		n->ant = fin;
		fin = n;
		fin->sig = cabeza;
		cabeza->ant = fin;
	}

}