// proyectoEDD1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"lista.h"
#include"Matrix.h"
#include"arbol.h"
#include<stdlib.h>
#include<fstream>
#include <sstream>
#include <string>
using namespace std;
Matrix lectura(std::string ruta,int x,int y);
lista llenarlista(std::string ruta);
void exportar( lista list);
lista aplicarfiltro(lista mat, std::string filtro, int capai,int x, int y);
 string dehex(int dec);
 string hex(int r, int g, int b);
 lista expandir(lista list, int x, int y);
 lista mirrory(lista list);
 lista mirrorx(lista list);
int main()

{	
int m;
	arbol arbol;
	arbol.insert("hola");
	arbol.insert("holas");
	arbol.insert("mario");
	arbol.insert("maria");
	arbol.insert("eduardo");
	arbol.insert("calamar");
	arbol.inorder();
	cout << endl;
	arbol.postorder();
	cout << endl;
	arbol.preorder();
	cout << endl;
    lista list ;
	string hola = "hora_de_aventura\\hora_de_aventura.csv";
	list=llenarlista(hola);
	list.mostrar();
	lista lista2 =aplicarfiltro(list, "doblemirror", 0,1,1);
	exportar(lista2);
	cout << "\t\t\tElija una opcion\n\n";
	cout << "1  Ingresos\n";
	cout << "2  Modificacion\n";
	cout << "3  Consultas\n";
	cout << "4  Reportes\n";
	cout << "5  Utilidades\n";
	cout << "6  Salir\n\n";
	cin >> m;

	switch (m)
	{
	case 1:cout << "Ud tiene S/. 2500" << endl; break;
	case 2:cout << "¿Que desea modificar?" << endl; break;
	case 3:cout << "Escriba su consulta aqui: " << endl; break;
	case 4:cout << "Ud. no presenta reportes" << endl; break;
	case 5:cout << "Este servicio esta bloqueado por el momento" << endl; break;
	case 6:cout << "Ya esta fuera" << endl; break;
	default: cout << "El valor ingresado no esta en el menu" << endl;
	}
	cin.ignore(); return 0;

	
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
		getline(archivo, texto, '\n');
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
void exportar( lista list) {

	ofstream archivo;
	string nombre = list.cabeza->nombre;
	archivo.open("export\\"+nombre+".html",ios::out);
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
	filecss.open( "export\\" + nombre + ".scss", ios::out);
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
					hec = hex(te.tempx->rojo, te.tempx->verde, te.tempx->azul); 
					filecss << " background: " + hec + ";}\n";
			   
				 
				te.tempx = te.tempx->der;
			}
			te.tempy = te.tempy->aba;

		}
		list.temp = list.temp->siguiente;
	}

	filecss.close();
	

};
lista aplicarfiltro(lista mat, std::string filtro, int capa,int x,int y) {
	lista list = expandir(mat,x,y);
	if (strstr(filtro.c_str(), "mirrorx")) {
		list = mirrorx(list);
	}if (strstr(filtro.c_str(), "mirrory")) {
		list = mirrory(list);
	}if (strstr(filtro.c_str(), "doblemirror")) {
		list = mirrorx(list);
		list = mirrory(list);
	}
	list.temp = list.cabeza->siguiente;
	bool todo; 
	if (capa == 0) { todo = true; }
	else { todo = false; }
	while (list.temp != NULL) {	
		if (todo==false) {
			while (list.temp->nombre != to_string(capa) && list.temp != NULL) {
				list.temp = list.temp->siguiente;
			}
		}
		Matrix te = list.temp->data;
		te.tempy = te.cabeza->aba;
		te.tempx = te.cabeza;

	

		while (te.tempy != NULL) {
			te.tempx = te.tempy->der;
		

			while (te.tempx != NULL) {
				if (strstr(filtro.c_str(), "blancoynegro")) {
					int black = te.tempx->rojo * 0.3 + te.tempx->verde * 0.59 + te.tempx->azul * 0.11;
					te.tempx->rojo= black;
					te.tempx->verde = black;
					te.tempx->azul = black;
				}
				else if (strstr(filtro.c_str(), "negativo")) {
					te.tempx->rojo=255 - te.tempx->rojo;
					te.tempx->verde=255 - te.tempx->verde;
					te.tempx->azul=255 - te.tempx->azul;
				}
				
				te.tempx = te.tempx->der;
			}
			te.tempy = te.tempy->aba;
			
		}
		if (todo == false) {
				return list;
			}
		list.temp = list.temp->siguiente;
	}
	return list;

};
lista expandir(lista list, int x, int y) {
	lista expandida;
	string name;
	int alto = list.cabeza->alto * y;
	int ancho = list.cabeza->ancho * x;
	expandida.config(ancho, alto, list.cabeza->pixelx, list.cabeza->pixely, list.cabeza->nombre);
	list.temp = list.cabeza->siguiente;
	
	while (list.temp != NULL) {
		Matrix nueva;
		for (int i = 0; i < ancho; i++) {
			nueva.nuevacolumna();
		}
		for (int i = 0; i < alto; i++) {
			nueva.nuevafila();
		}
		Matrix te = list.temp->data;
		for(int i=0; i<y;i++){
			te.tempy = te.cabeza->aba;
		te.tempx = te.cabeza;
			while (te.tempy != NULL) {
				
				for (int j = 0; j < x; j++) {
					te.tempx = te.tempy->der;
				while (te.tempx != NULL) {
					nueva.colocarnodo(te.tempx->rojo, te.tempx->verde, te.tempx->azul, te.tempx->x + (j * list.cabeza->ancho), te.tempx->y + (i * list.cabeza->alto));
					te.tempx = te.tempx->der;
				}
			}
			te.tempy = te.tempy->aba;
		}
		}
		name= list.temp->nombre;
		expandida.agregarinicio(nueva,name);
		list.temp = list.temp->siguiente;
	}

	return expandida;
};
lista mirrory(lista list) {
	lista expandida;
	string name;
	int alto = list.cabeza->alto;
	expandida.config(list.cabeza->ancho, list.cabeza->alto, list.cabeza->pixelx, list.cabeza->pixely, list.cabeza->nombre);
	list.temp = list.cabeza->siguiente;
	
	while (list.temp != NULL) {
		Matrix nueva;
		for (int i = 0; i < list.cabeza->ancho; i++) {
			nueva.nuevacolumna();
		}
		for (int i = 0; i < list.cabeza->alto; i++) {
			nueva.nuevafila();
		}
		Matrix te = list.temp->data;
			te.tempy = te.finaba;
			while (te.tempy != te.cabeza) {
					te.tempx = te.tempy->der;
					while (te.tempx != NULL) {
						nueva.colocarnodo(te.tempx->rojo, te.tempx->verde, te.tempx->azul,te.tempx->x, alto+1-te.tempx->y);
						te.tempx = te.tempx->der;
					}
				
				te.tempy = te.tempy->arri;
			}
		
		name = list.temp->nombre;
		expandida.agregarinicio(nueva, name);
		list.temp = list.temp->siguiente;
	}

	return expandida;
};
lista mirrorx(lista list) {
	lista expandida;
	string name;
	int ancho = list.cabeza->ancho;
	expandida.config(list.cabeza->ancho, list.cabeza->alto, list.cabeza->pixelx, list.cabeza->pixely, list.cabeza->nombre);
	list.temp = list.cabeza->siguiente;

	while (list.temp != NULL) {
		Matrix nueva;
		for (int i = 0; i < list.cabeza->ancho; i++) {
			nueva.nuevacolumna();
		}
		for (int i = 0; i < list.cabeza->alto; i++) {
			nueva.nuevafila();
		}
		Matrix te = list.temp->data;
		te.tempx = te.finder;
		while (te.tempx != te.cabeza) {
			te.tempy = te.tempx->aba;
			while (te.tempy != NULL) {
				nueva.colocarnodo(te.tempy->rojo, te.tempy->verde, te.tempy->azul,ancho+1- te.tempy->x, te.tempy->y);
				te.tempy = te.tempy->aba;
			}

			te.tempx = te.tempx->izqu;
		}

		name = list.temp->nombre;
		expandida.agregarinicio(nueva, name);
		list.temp = list.temp->siguiente;
	}

	return expandida;
};

 string dehex(int dec) {
	if (dec < 1) return "00";
	if (dec == 1) return"01";
	if (dec ==2) return"02";
	if (dec == 3) return"03";
	if (dec == 4) return"04";
	if (dec == 5) return"05";
	if (dec == 6) return"06";
	if (dec == 7) return"07";
	if (dec == 8) return"08";
	if (dec == 9) return"09";
	if (dec == 10) return"0A";
	if (dec == 11) return"0B";
	if (dec == 12) return"0C";
	if (dec == 13) return"0D";
	if (dec == 14) return"0E";
	if (dec == 15) return"0F";

	
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