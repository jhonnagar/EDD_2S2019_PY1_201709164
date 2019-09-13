#include "lectorcsv.h"
#include<stdlib.h>
#include<fstream>
#include <iostream>
#include <string>
using namespace std;

void lectorcsv::lectura(std::string ruta )
{
	ifstream archivo;
	string texto;
	archivo.open(ruta.c_str(), ios::in);

	if (archivo.fail())

	{
		cout << "no hay archivo";
		return;
	}
	while (!archivo.eof())
	{
		getline(archivo,texto);
		cout<<texto;

	}
	archivo.close();

}