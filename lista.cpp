#include "lista.h"
#include<iostream>
#include<cstdlib>
using namespace std;
lista::lista() {
	cabeza = NULL;
	temp = NULL;
	fin = NULL;
}
string lista::getnombre() {
	string nombre = cabeza->nombre;
	return nombre;
}
void lista::agregarinicio(Matrix adddata,std::string name){
	nodoptr n = new nodo;
	n->siguiente = NULL;
	n->data = adddata;
	n->nombre = name;
	if (cabeza == NULL) {
		cabeza = n;
		fin = n;
	}
	else
	{
		fin->siguiente = n;
		fin =n;
	}

}
void lista::config(int ancho, int alto, int px, int py, std::string nomb) {
	nodoptr n = new nodo;
	n->siguiente = NULL;
	n->alto = alto;
	n->ancho = ancho;
	n->pixelx = px;
	n->pixely = py;
	n->nombre = nomb;
    cabeza=n;
	fin = n;
}
	
void lista::mostrar() {
	temp = cabeza;
	temp = temp->siguiente;
	while (temp!=NULL) {
		cout << temp->nombre<<endl;
		Matrix te= temp->data;
		te.tempy = te.cabeza;
		te.tempx = te.cabeza;
		
		while (te.tempy != NULL) {
			te.tempx = te.tempy;
			while (te.tempx != NULL) {
				cout << te.tempx->x << "," << te.tempx->y << " ";
				te.tempx = te.tempx->der;
			}
			te.tempy = te.tempy->aba;
			cout << "---------" << endl;

		}
		temp = temp->siguiente;
		cout << "////////////"<<endl;
	}
}


