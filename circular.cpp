#include "circular.h"
#include <iostream>
#include <string>
#include<stdlib.h>
#include<fstream>
#include <sstream>
#include <string>
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
void circular::mostrar() {
	ofstream archivo;
	string line;
	archivo.open("report\\circular.dot", ios::out);
	archivo << "digraph R { \n";
	archivo << "node[shape = record];\n";
	temp = cabeza;
	line = line + temp->nombre+to_string(temp->pos) + "->" + temp->sig->nombre + "\n";
	line = line + temp->nombre + to_string(temp->pos) + "->" + temp->ant->nombre + "\n";
	temp = temp->sig;

	while (temp!=cabeza && temp!=NULL) {
		line = line + temp->nombre + to_string(temp->pos) +"->"+temp->sig->nombre+"\n";
		line = line + temp->nombre + to_string(temp->pos) + "->" + temp->ant->nombre + "\n";
		temp = temp->sig;
	}
	archivo << line + ";}";
	archivo.close();
	system("dot -Tpng report\\circular.dot -o report\\circular.png");

};
void circular::mostrartodo() {
	temp = cabeza;
	temp->data.mostrar(temp->nombre + to_string(temp->pos));
	temp = temp->sig;

	while (temp != cabeza && temp != NULL) {
		temp->data.mostrar(temp->nombre + to_string(temp->pos));
		temp = temp->sig;
	}

};