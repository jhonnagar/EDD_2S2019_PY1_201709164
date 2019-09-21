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
string arbol::inorder(nodo* root) {
	string inor="";
	if (root != NULL) {
		inor=inor+inorder(root->izq);
		inor= inor+root->nombre + ";";
		inor=inor+inorder(root->der);
	}
	return inor;

}
string arbol::preorder(nodo* root) {
	string inor = "";
	if (root != NULL) {
		inor = inor + root->nombre+";";
		inor = inor + preorder(root->izq);
		inor = inor + preorder(root->der);
	}
	return inor;
}
string arbol::postorder(nodo* root) {
	string inor = "";
	if (root != NULL) {
		inor = inor + postorder(root->izq) ;
		inor = inor + postorder(root->der) ;
		inor = inor + root->nombre+";"  ;
	}
	return inor;
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
