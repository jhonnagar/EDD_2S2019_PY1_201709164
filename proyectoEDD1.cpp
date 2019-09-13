// proyectoEDD1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"lista.h"
#include"Matrix.h"
#include<stdlib.h>
#include<fstream>
#include <sstream>
#include <string>
using namespace std;
Matrix lectura(std::string ruta);
int main()

{	
	lista list;
	if (false) {
	
		list.config(1, 2, 3, 4);
		for (int i = 0; i < 3; ++i) {
			Matrix hola;

			hola.nuevafila();
			hola.nuevacolumna();
			
			if (i == 1) {
				hola.nuevafila();
			hola.nuevacolumna();
				hola.colocarnodo(110, 200, 300, 1, 1);
			}
			list.agregarinicio(hola);
		}

		list.mostrar();
	}
	
	string hola = "prueba.csv";
	Matrix mat = lectura(hola);
	list.agregarinicio(mat);
	list.mostrar();

}
Matrix lectura(std::string ruta)
{
	Matrix mat;
	mat.nuevafila();
	mat.nuevacolumna();
	ifstream archivo;
	string texto;
	archivo.open(ruta, ios::in);

	if (archivo.fail())

	{
		cout << "no hay archivo";
		
	}
	while (!archivo.eof())
	{
	
		
			getline(archivo, texto, ',');
		
		if (strstr(texto.c_str(), "x")) {
			
		}
		else 
		{
			std::istringstream ss(texto);
		
			string color;
			getline(ss, color, '-');
			int number;
			std::istringstream rojo(color);
			rojo >> number;
			cout << number<< endl;
		
			getline(ss, color, '-');
			std::istringstream verde(color);
			verde >> number;
			cout << number << endl;

			getline(ss, color, '-');
			std::istringstream azul(color);
			azul >> number;
			cout << number << endl;
		}	

		

	}
	archivo.close();
	return mat;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
