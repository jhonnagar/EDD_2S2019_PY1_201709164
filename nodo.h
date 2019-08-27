#pragma once
#include<iostream>
using namespace std;
template <class T>
class nodo
{       
        public:
		nodo();
		nodo(T);
		~nodo();

		nodo* next;
		
		T data;

		void delete_all();
		void print();
};

