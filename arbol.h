#pragma once
#include"lista.h"
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
	arbol() {
		root = NULL;
	}

  
	bool insert(std::string  data) {
		return insert(data, root);
	};

	void inorder() {
		inorder(root);
	};
	void postorder() {
		postorder(root);
	};
	void preorder() {
		preorder(root);
	};
	string graficar() {
		return grafica(1,root );
	};

	bool insert(std::string item, nodo* raiz_actual);
	void inorder(nodo* actual);
	void postorder(nodo* actual);
	string grafica(int nod,nodo* root );
	void preorder(nodo* actual);
};

