#include "lista.h"
#include<iostream>
#include<cstdlib>
using namespace std;
lista::lista() {
	cabeza = NULL;
	temp = NULL;
	fin = NULL;
}

void lista::agregarinicio(Matrix adddata){
	nodoptr n = new nodo;
	n->siguiente = NULL;
	n->data = adddata;
	if (cabeza == NULL) {
		cabeza = n;
		fin = n;
	}
	else
	{
		fin->siguiente = n;
		fin = n;
	}

}
void lista::config(int ancho, int alto, int px, int py) {
	nodoptr n = new nodo;
	n->siguiente = NULL;
	n->alto = alto;
	n->ancho = ancho;
	n->pixelx = px;
	n->pixely = py;
    cabeza=n;
	fin = n;
}
	
void lista::mostrar() {
	temp = cabeza;
	while (temp!=NULL) {

		temp->data.mostrar();
		temp = temp->siguiente;
		cout << "////////////"<<endl;
	}
}


