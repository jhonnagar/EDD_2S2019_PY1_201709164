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
lista llenarlista(std::string ruta);
void exportar(std::string filtro, lista list);
 string dehex(int dec);
 string hex(int r, int g, int b);
int main()

{	
	lista list;
	string hola = "Ave\\inicial.csv";
	list=llenarlista(hola);
	exportar("negativo", list);
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
			for (int xi = 1; xi <= x; xi++) {

				// separa por comoas cada linea 
				getline(lin, texto, ',');
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
					if (red > 255) {
						red = 255;
					};
					if (green > 255) {
						green = 255;
					};
					if (blue > 255) {
						blue = 255;
					};
					mat.colocarnodo(red, green, blue, xi, yi);
				
				}

			}

		}
	
	archivo.close();
	return mat;
}
lista llenarlista(std::string ruta) {
	std::istringstream nomb(ruta);
	string nombre,name;
	getline(nomb, nombre, '\\');
	lista list;
	int x = 0;
	int y = 0;
	int px = 0;
	int py = 0;
	string texto;
	ifstream archivo;
	archivo.open(ruta, ios::in);
	if (archivo.fail())
	{
		cout << "no hay archivo";
	}
	getline(archivo, texto, ',');
	getline(archivo, texto, '\n');
	while (!archivo.eof()) {
		getline(archivo, texto, ',');
		name = texto;
		cout << name << endl;
		getline(archivo, texto, '\n');
		cout << texto << endl;
		if (strstr(texto.c_str(), "config.csv")) {
			string text;
			ifstream archi;
			archi.open(nombre+"\\config.csv", ios::in);
			
			while (!archi.eof()) {
				getline(archi, text, ',');
				if (strstr(text.c_str(), "pixel_width")) {
					getline(archi, text, '\n');
					std::istringstream verde(text);
					verde >> px;
				}
				else if (strstr(text.c_str(), "image_width")) {
					getline(archi, text, '\n');
					std::istringstream verde(text);
					verde >> x;
		
				}
				else if (strstr(text.c_str(), "pixel_height")) {
					getline(archi, text, '\n');
					std::istringstream verde(text);
					verde >> py;
					
				}
				else if (strstr(text.c_str(), "image_height")) {
					getline(archi, text, '\n');
					std::istringstream verde(text);
					verde >> y;
					
				}
				
				
			}
			cout << "entro";
          list.config(x,y,px,py,nombre);
		}
		else {
			Matrix mat;
			mat = lectura(nombre+"\\"+texto,x,y);
			list.agregarinicio(mat,name);
		}
	}

	return list;
};
void exportar(std::string filtro, lista list) {

	ofstream archivo;
	string nombre = list.cabeza->nombre;
	archivo.open(nombre+"\\"+nombre+".html",ios::out);
	archivo << "<!DOCTYPE html>\n";
	archivo << "<html>\n";
	archivo << "<head>\n";
	archivo << " <link rel = \"stylesheet\" href = \""+nombre+".scss\">\n";
	archivo << "</head>\n";
	archivo << "<body>\n";
	archivo <<"<div class = \"canvas\">\n";
	int x=list.cabeza->ancho;
	int y = list.cabeza->alto;
	int py = list.cabeza->pixely;
	int px = list.cabeza->pixelx;
	for (int i = 0; i < x * y; i++) {
		archivo << "<div class =\"pixel\"></div>\n";
	}
	archivo << "</div>\n";
	archivo << "</body>\n";
	archivo << "</html>\n";
	archivo.close();

	ofstream filecss;
	filecss.open(nombre + "\\" + nombre + ".scss", ios::out);
	filecss << "body {\n";
	filecss << "background: #ffffff;\n";
	filecss << "height: 100vh;\n";
	filecss << "display: flex;\n";
	filecss << "justify-content: center;\n";
	filecss << "align-items: center;\n }\n";
	int alto = y * py;
	int ancho = x * px;
	filecss << ".canvas{\n";
	filecss << "width: "+ to_string(ancho) +"px;\n";
	filecss << "height: "+ to_string(alto) +"px;\n}\n";
	filecss << ".pixel{\n";
	filecss << "width: "+to_string(px)+"px;\n "; 
	filecss << "height: "+to_string(py)+"px;\n ";
	filecss << "float: right;\n}\n   "; 

	list.temp = list.cabeza->siguiente;
	while (list.temp != NULL) {
		Matrix te =list.temp->data;
		te.tempy = te.cabeza->aba;
		te.tempx = te.cabeza;
	

		while (te.tempy != NULL) {	
			te.tempx = te.tempy->der;
			
			while (te.tempx != NULL) {
				string hec;
				int pos = (te.tempx->y-1) * x + te.tempx->x;
				filecss << " .pixel:nth-child(" + to_string(pos) + ") {\n";

				if (strstr(filtro.c_str(), "blancoynegro")) {
					int black = te.tempx->rojo * 0.3+ te.tempx->verde * 0.59+ te.tempx->azul * 0.11;
					hec = hex(black,black,black);
				}
				else if (strstr(filtro.c_str(), "negativo")) {
					hec = hex(255-te.tempx->rojo ,255-te.tempx->verde,255-te.tempx->azul);
				}
				else {
					hec = hex(te.tempx->rojo, te.tempx->verde, te.tempx->azul); 
				}
					
					filecss << " background: " + hec + ";}\n";
			   
				 
				te.tempx = te.tempx->der;
			}
			te.tempy = te.tempy->aba;

		}
		list.temp = list.temp->siguiente;
	}

	filecss.close();
	

};






 string dehex(int dec) {
	if (dec < 1) return "00";
	
	int hex = dec;
	string hexStr = "";

	while (dec > 0)
	{
		hex = dec % 16;

		if (hex < 10)
			hexStr = hexStr.insert(0, string(1, (hex + 48)));
		else
			hexStr = hexStr.insert(0, string(1, (hex + 55)));

		dec /= 16;
	}

	return hexStr;
}
 string hex(int r,int g,int b) {
	string rs = dehex(r);
	string gs = dehex(g);
	string bs = dehex(b);

	return '#' + rs + gs + bs;
}