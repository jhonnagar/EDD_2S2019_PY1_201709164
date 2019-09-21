#pragma once
#include"lista.h"
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
using namespace std;
class arbol
{
public:
	typedef struct nodo {
		lista data;
		string nombre;
		nodo* der = NULL;
		nodo* izq = NULL;
	}*nodoptr;	
	nodoptr root;
	nodoptr temp;
	arbol() {
		root = NULL;
		temp = NULL;
	}

  
	bool insert(std::string  data,lista list) {
		return insert(data, root,list);
	};
	lista buscar(std::string data) {
		return
			
			busca(data, root);
	};
	void inorder() {
		ofstream archivo;
		string line;
		string linea = inorder(root);
		string texto = "1";
		string texto1 = " ";
		std::istringstream lin(linea);
		archivo.open("report\\inorder.dot", ios::out);
		archivo << "digraph R { \n";
		archivo << "node[shape = record];\n";
		getline(lin, texto1, ';');
		while (texto != "") {
			getline(lin, texto, ';');
			if (texto == "") {
				texto = "";
			}
			else
			{
				cout << texto + "-";
				line = texto1 + "->" + texto + "\n" + line;
				texto1 = texto;
			}



		}
		archivo << line + ";}";
		archivo.close();
		system("dot -Tpng report\\inorder.dot -o report\\inorder.png");
	};
	void postorder() {
		ofstream archivo;
		string line;
		string linea=postorder(root);
		string texto = "1";
		string texto1 = " ";
		std::istringstream lin(linea);
		archivo.open("report\\postorder.dot", ios::out);
		archivo << "digraph R { \n";
		archivo << "node[shape = record];\n";
		getline(lin, texto1, ';');
		while (texto != "") {
			getline(lin, texto, ';');
			if (texto == "") {
				texto = "";
			}
			else
			{
                cout << texto+"-";
				line= texto1 + "->" + texto + "\n"+line;
				texto1 = texto;
			}
			
				
		    
		}
		archivo << line+";}";
		archivo.close();
		system("dot -Tpng report\\postorder.dot -o report\\postorder.png");
	
	};
	void preorder() {
		ofstream archivo;
		string line;
		string linea = preorder(root);
		string texto = "1";
		string texto1 = " ";
		std::istringstream lin(linea);
		archivo.open("report\\preorder.dot", ios::out);
		archivo << "digraph R { \n";
		archivo << "node[shape = record];\n";
		getline(lin, texto1, ';');
		while (texto != "") {
			getline(lin, texto, ';');
			if (texto == "") {
				texto = "";
			}
			else
			{
				cout << texto + "-";
				line = texto1 + "->" + texto + "\n" + line;
				texto1 = texto;
			}



		}
		archivo << line + ";}";
		archivo.close();
		system("dot -Tpng report\\preorder.dot -o report\\preorder.png");
	};
	string graficar() {
		return grafica(1,root );
	};

	string in() {
		return inorder(root);
	}

	bool insert(std::string item, nodo* raiz_actual,lista list);
	string inorder(nodo* actual);
	string postorder(nodo* actual);
	string grafica(int nod,nodo* root );
	string preorder(nodo* actual);
	lista busca(std::string item, nodo* raiz);
};

