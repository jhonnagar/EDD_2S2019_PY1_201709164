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
		n->siguiente = cabeza;
		cabeza = n;
	}

}
	
void lista::mostrar() {
	temp = cabeza;
	while (temp!=NULL) {
		temp->data.mostrar();
		temp = temp->siguiente;
		cout << "////////////"<<endl;
	}
}


