#include "lista.h"
#include<iostream>
#include<cstdlib>
using namespace std;
lista::lista() {
	cabeza = NULL;
	temp = NULL;
	fin = NULL;
}

void lista::agregarinicio(int adddata){
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
void lista::eliminar(int data) {
	temp = cabeza;
	while (temp->siguiente->data ==data) {
		temp = temp->siguiente;
	}
	if (temp->siguiente->data = data) {
		temp->siguiente = temp->siguiente->siguiente;
	}
	else
	{
		cout << "no hay nada";
	}
		
	}
void lista::mostrar() {
	temp = cabeza;
	while (temp!=NULL) {
		cout << temp->data << endl;
		temp = temp->siguiente;
	}
}


