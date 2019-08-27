#include "nodo.h"

// Constructor por defecto
template<typename T>

nodo<T>::nodo()
{
	data = NULL;
	next = NULL;
}

// Constructor por parámetro
template<typename T>
nodo<T>::nodo(T data_)
{
	data = data_;
	next = NULL;
}

// Eliminar todos los Nodos
template<typename T>
void nodo<T>::delete_all()
{
	if (next)
		next->delete_all();
	delete this;
}

// Imprimir un Nodo
template<typename T>
void nodo<T>::print()
{
	//cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
	cout << data << "-> ";
}

template<typename T>
nodo<T>::~Node() {}
