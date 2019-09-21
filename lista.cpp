#include "lista.h"
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include <string>
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
	
void lista::mostrar(std::string name) {

	temp = cabeza;
	temp = temp->siguiente;
	while (temp!=NULL) {	
		string rank="";
	    string texto="";
	    string armado="";
		string nodo = "";
		ofstream archivo;
		archivo.open("report\\"+temp->nombre+name+".dot", ios::out);
		archivo << "digraph R { \n";
		archivo << "node[shape = record];\n";
		Matrix te= temp->data;
		te.tempy = te.cabeza->aba;
		te.tempx = te.cabeza;
		while (te.tempx != NULL) {
			rank = rank+ "nod0" + to_string(te.tempx->x) + to_string(te.tempx->y)+" ";
			nodo = nodo + "nod0" + to_string(te.tempx->x) + to_string(te.tempx->y) + " [label = \"" + "columna   " + to_string(te.tempx->x) + "\" pos = \"" + to_string(te.tempx->x*2) + "," + to_string(te.tempx->y*2) + "!\"]; \n";

			if (te.tempx->aba != NULL) {
				texto = texto + "nod0" + to_string(te.tempx->x) + to_string(te.tempx->y) + "->" + "nodo" + to_string(te.tempx->aba->x) + "_" + to_string(te.tempx->aba->y) + " [dir=\"both\"] \n";
			}
			if (te.tempx->der != NULL) {
				texto = texto + "nod0" + to_string(te.tempx->x) + to_string(te.tempx->y) + "->" + "nod0" + to_string(te.tempx->der->x) + "" + to_string(te.tempx->der->y) + " [dir=\"both\"] \n";
			}
				te.tempx = te.tempx->der;
		}
		armado = armado+"{ rank=same "+rank + " }\n";
		while (te.tempy != NULL) {
			rank = "";
			te.tempx = te.tempy;
			rank = rank + "nodo" + to_string(te.tempx->x) +"_"+ to_string(te.tempx->y) + " ";
			nodo = nodo + "nodo" + to_string(te.tempx->x) +"_"+ to_string(te.tempx->y) + " [label =\"" + "fila" + to_string(te.tempx->y) + "\" pos = \"" + to_string(te.tempx->x*2) + ",-" + to_string(te.tempx->y*2) + "!\"]; \n";
			if (te.tempx->aba != NULL) {
				texto = texto + "nodo" + to_string(te.tempx->x)+"_" + to_string(te.tempx->y) + "->" + "nodo" + to_string(te.tempx->aba->x) + "_" + to_string(te.tempx->aba->y) + " [dir=\"both\"] \n";
			}
			if (te.tempx->der != NULL) {
				texto = texto + "nodo" + to_string(te.tempx->x) +"_"+ to_string(te.tempx->y) + "->" + "nodo" + to_string(te.tempx->der->x) + "_" + to_string(te.tempx->der->y) + " [dir=\"both\"] \n";
			}
			te.tempx = te.tempx->der;
			while (te.tempx != NULL) {
				string color = to_string(te.tempx->rojo) + "-"+to_string(te.tempx->verde) + "-"+to_string(te.tempx->azul) ;
				nodo = nodo + "nodo" + to_string(te.tempx->x) +"_"+ to_string(te.tempx->y) + " [label = \"" + color + "\" pos = \"" + to_string(te.tempx->x*2) + ",-" + to_string(te.tempx->y*2) + "!\"]; \n";
				rank = rank + "nodo" + to_string(te.tempx->x) + "_"+to_string(te.tempx->y) + " ";
				if (te.tempx->aba != NULL) {
					texto = texto + "nodo" + to_string(te.tempx->x) +"_"+ to_string(te.tempx->y) + "->" + "nodo" + to_string(te.tempx->aba->x) + "_" + to_string(te.tempx->aba->y) + " [dir=\"both\"] \n";
				}
				if (te.tempx->der != NULL) {
					texto = texto + "nodo" + to_string(te.tempx->x) +"_"+ to_string(te.tempx->y) + "->" + "nodo" + to_string(te.tempx->der->x) + "_" + to_string(te.tempx->der->y) + " [dir=\"both\"] \n";
				}
				te.tempx = te.tempx->der;
			}
			armado = armado + "{ rank=same " + rank + " }\n";
			te.tempy = te.tempy->aba;
		}
		archivo << nodo;
		archivo <<armado;
		archivo << texto+"}";
		archivo.close();
		string crear = "neato -Tpng report\\" + temp->nombre +name + ".dot -o report\\" + temp->nombre +name+ ".png";
		system(crear.c_str());
		temp = temp->siguiente;
		
	}
	cout <<"terminado";
}


