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
Matrix lectura(std::string ruta,int x,int y);
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
	
	string hola = "carro\\prueba.csv";
	Matrix mat = lectura(hola,4,3);
	list.agregarinicio(mat);
	list.mostrar();

}
Matrix lectura(std::string ruta, int x, int y)
{

	ifstream archivo;
	string texto;
	string linea;
	Matrix mat;
	for (int i=0; i < x; i++) {
		mat.nuevacolumna();
	}
	for (int i=0; i < y; i++) {
		mat.nuevafila();
	}
	//empieza a leer el archivo --------
	archivo.open(ruta, ios::in);

	if (archivo.fail())

	{
		cout << "no hay archivo";
		return mat;
	}

		for (int yi = 1; yi <= y; yi++) {
			//se para por lineas el archivo 
			getline(archivo, linea, '\n');
			std::istringstream lin(linea);
			cout << linea << endl;
			for (int xi = 1; xi <= x; xi++) {

				// separa por comoas cada linea 
				getline(lin, texto, ',');
				cout << texto << endl;
				if (strstr(texto.c_str(), "x")) {
				
				}
				else
				{
					//separa por - cada espacio que tiene numeros 
					std::istringstream ss(texto);

					string color;
					getline(ss, color, '-');
					int red;
					int green;
					int blue;
					std::istringstream rojo(color);
					rojo >> red;

					getline(ss, color, '-');
					std::istringstream verde(color);
					verde >> green;

					getline(ss, color,'\n');
					std::istringstream azul(color);
					azul >> blue;

					mat.colocarnodo(red, green, blue, xi, yi);
				
				}

			}

		}
	
	archivo.close();
	return mat;
}
lista llenarlista(std::string ruta) {
	lista list;	

	ifstream archivo;
	string texto;
	archivo.open(ruta, ios::in);
	if (archivo.fail())
	{
		cout << "no hay archivo";
	}
	while (!archivo.eof()) {
		getline(archivo, texto, ',');
		if (strstr(texto.c_str(), "x")) {

		}
		getline(archivo, texto, '\n');
	}
	return list;
};
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
