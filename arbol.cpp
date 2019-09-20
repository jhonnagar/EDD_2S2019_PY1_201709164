#include "arbol.h"
#include <iostream>
bool arbol::insert(std::string item, nodo* raiz_actual) {
     	nodoptr n = new nodo();
		n->nombre = item;
	if (root == NULL) {
		root = n;
		return true;
	}
	else if (item < raiz_actual->nombre) {
		if (raiz_actual->izq == NULL) {
			raiz_actual->izq = n;
			return true;
		}
		else {
			return insert(item, raiz_actual->izq);
		}
	}
	else if (item > raiz_actual->nombre) {
		if (raiz_actual->der == NULL) {
			raiz_actual->der = n;
			return true;
		}
		else {
			return insert(item, raiz_actual->der);
		}
	}
	else {
		return false;
	}
}
void arbol::inorder(nodo* root) {
	if (root != NULL) {
		inorder(root->izq);
		cout << " " << root->nombre << " ->";
		inorder(root->der);
	}

}

void arbol::preorder(nodo* root) {
	if (root != NULL) {
		cout << " " << root->nombre << " ->";
		preorder(root->izq);
		preorder(root->der);
	}

}


void arbol::postorder(nodo* root) {
	if (root != NULL) {
		postorder(root->izq);
		postorder(root->der);
		cout << " " << root->nombre << " ->";

	}

}