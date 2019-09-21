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
string arbol::grafica(int nod,nodo* root) {
	string grafic = " ";

	if (root != NULL) {
		grafic ="nodo"+to_string(nod)+ root->nombre+" [label =\"<C0>|" +root->nombre+ "|<C1>\"];\n";

		if (root->izq != NULL) {
			
			grafic =  grafica(nod+1,root->izq)+grafic;
			grafic = grafic + "nodo" + to_string(nod) + root->nombre + ":C0->" + "nodo" + to_string(nod + 1) + root->izq->nombre+"\n";
		}
		if (root->der != NULL) {
			grafic =  grafica(nod+1,root->der)+grafic;
			grafic = grafic + "nodo" + to_string(nod) + root->nombre + ":C1->" + "nodo" + to_string(nod + 1) + root->der->nombre + "\n";
		}
		if (root->der == NULL && root->izq == NULL) {
			grafic = "nodo" + to_string(nod) + root->nombre + " [label =\"" + root->nombre + "\"];\n";
		}
	}
	return grafic;

};
