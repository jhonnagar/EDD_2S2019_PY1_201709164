#include "Matrix.h"
#include<iostream>
#include<cstdlib>
using namespace std;
Matrix::Matrix() 
{
	cabeza = NULL;
	finder = NULL;
	finaba = NULL;
	tempx = NULL;
    tempy = NULL;
}
void Matrix::nuevacolumna() 
{
	nodoptr n = new nodo;

	if (cabeza ==NULL)
	{
		nodoptr m = new nodo;
		cabeza = m;
		cabeza->x = 0;
		cabeza->y = 0;
		finaba = cabeza;
		n->y = 0;
		n->x = 1;
		n->der = NULL;
		n->aba = NULL;
		cabeza->der = finder = n;
		finder->izqu = cabeza;
		
	}
	else
	{
		int x = finder->x + 1;
		n->y = 0;
		n->x = x;
		n->izqu = finder;
		n->der= NULL;
		n->aba = NULL;
		finder->der = n;
		finder = n;
		

	}
}
void Matrix::nuevafila()
{
	nodoptr n = new nodo;

	if (cabeza == NULL)
	{
		nodoptr m = new nodo;
		cabeza = m;
		cabeza->x = 0;
		cabeza->y = 0;
		finder  = cabeza;
		n->y = 1;
		n->x = 0;
		n->aba = NULL;
		n->der = NULL;
		cabeza->aba = finaba = n;
		finaba->arri = cabeza;
		
	}
	else
	{
		int y = finaba->y + 1;
		n->x = 0;
		n->y = y;
		n->arri = finaba;
		n->aba = NULL;
		n->der = NULL;
		finaba->aba = n;
		finaba = n;
	

	}
}
void Matrix:: mostrar() 
{
	tempy = cabeza;
	tempx = cabeza;
	
	while (tempx != NULL) {
		tempy = tempx;
		while (tempy != NULL) {
		cout << tempy->x<<","<<tempy->y << endl;
		tempy = tempy->aba;
	}
		tempx = tempx->der;
		cout <<  "---------" << endl;
	
	}
}
void Matrix::colocarnodo(int rojo , int verde , int azul,int x, int y) 
{
	nodoptr n = new nodo;
	tempx = cabeza;
	tempy = tempx;
	while (tempx->x != x) {
		tempx = tempx->der;
	}
	while (tempy->y!= y) {
		tempy = tempy->aba;
	}
	while (tempx->aba!=NULL) {
		tempx = tempx->aba;
	}
	while (tempy->der !=NULL) {
		tempy = tempy->der;
	}
	n->x = x;
	n->y = y;
	n->rojo = rojo;
	n->verde = verde;
	n->azul = azul;
	n->arri = tempx;
	n->izqu = tempy;
	n->aba = NULL;
	n->der = NULL;
	tempy->der = n;
	tempx->aba = n;
	
}