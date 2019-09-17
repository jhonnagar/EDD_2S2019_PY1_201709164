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
	while (temp!=NULL) {
		cout << temp->nombre<<endl;
		temp->data.mostrar();
		temp = temp->siguiente;
		cout << "////////////"<<endl;
	}
}


