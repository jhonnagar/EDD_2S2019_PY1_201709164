// proyectoEDD1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"lista.h"
#include"Matrix.h"
#include"arbol.h"
#include"circular.h"


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
 void seleccionar();
 void pausa();
 void filtros();
 void exporta();
 void reportes();
 void graficaseleccion();
 string nombre;
 arbol tree;
lista list;
lista temp;
circular cicular;
void mostrarcir();
int main()
{
	bool bandera = false;
	char tecla;

	do
	{
		
		system("cls");
		cin.clear();
		cout << "________PHOTGEN++_______" << endl;
		cout << "------------------------" << endl << endl;
		cout << "\t1 .- insertar imagen" << endl;
		cout << "\t2 .- seleccionar imagen" << endl;
		cout << "\t3 .- aplicar filtros " << endl;
		cout << "\t4 .- edicion manuel" << endl;
		cout << "\t5 .- exportar" << endl;
		cout << "\t6 .- reportes" << endl << endl;
		cout << "Elije una opcion: ";
        
		cin >> tecla;

		switch (tecla)
		{
		case '1':
			system("cls");
			cout << "ecribir ruta del archivo.\n";
			cin>>nombre;
			list = llenarlista(nombre);
			
			tree.insert(list.cabeza->nombre, list);
			tree.insert("v", list);
			tree.insert("c", list);
			tree.insert("d", list);
			cicular.borrar();
			temp = list;
			cicular.agregar(list,"original");
			cout << "agregada";
			
			pausa();
			break;

		case '2':
			seleccionar();

			pausa();
			break;

		case '3':
			system("cls");
			filtros();

			pausa();
			break;

		case '5':
			system("cls");
			exporta();
			pausa();
			break;

		case '6':
			reportes();
			break;

		default:
			system("cls");
			cout << "Opcion no valida.\a\n";
			pausa();
			break;
		}
	} while (bandera != true);

	return 0;
}

void pausa()
{
	cout << "Pulsa una tecla para continuar...";
	getwchar();
	getwchar();
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
		return list;
	}else
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
 void seleccionar() {
	 system("cls");
	 string espacio = tree.in();
	 std::istringstream lin(espacio);
	 string texto="1";
	 cout << "---ELIGE UNA IMAGEN----" << endl;
	 int x = 1;
	 while (texto != "") {
		 getline(lin, texto, ';');
		 cout << "\t"+to_string(x)+"  " +texto+"." << endl;
		 x = x + 1;
	 }
	 cout << "---Elige una opcion----"<<endl;
	 cin >> x;

	 std::istringstream line(espacio);
	 for (int i = 0; i < x;i++ ) {
		 getline(line, texto, ';');
	 }
	 temp = tree.buscar(texto);
 };
 void filtros() {
	 cout << "\t 1 - Negativo" << endl;
	 cout << "\t 2 - Blanco y negro" << endl;
	 cout << "\t 3 - Mirrorx" << endl;
	 cout << "\t 4 - Mirrory" << endl;
	 cout << "\t 5 - DobleMirror" << endl;
	 cout << "\t 6 - Expandir" << endl;
	 cout << "\t 7 - Mosaico" << endl;
	 cout << "---elige una opcion---" << endl;
	 char x;
	 int y;
	 int xe;
	 cin >> x;

	 switch (x)
	 {
	 case '1' : 
		 cout << "---elige una capa---" << endl;
		 cin >> y;
		 cicular.agregar(aplicarfiltro(temp,"negativo",y,1,1 ),"negativo");

		 cout << "---filtro agregado ---" << endl;
		 break;
	 case '2':
		 cout << "---elige una capa---" << endl;
		 cin >> y;
		 cicular.agregar(aplicarfiltro(temp, "blancoynegro", y, 1, 1), "blancoynegro");
		 cout << "---filtro agregado ---" << endl;
		 break;
	 case '3':
	
		 cicular.agregar(aplicarfiltro(temp, "mirrorx", 0, 1, 1), "mirrorx");
		 cout << "---filtro agregado ---" << endl;
		 break;
	 case '4':

		 cicular.agregar(aplicarfiltro(temp, "mirrory", 0, 1, 1), "mirrory");
		 cout << "---filtro agregado ---" << endl;
		 break;
	 case '5':

		  cicular.agregar(aplicarfiltro(temp, "doblemirror", 0, 1, 1), "doblemirror");
		  cout << "---filtro agregado ---" << endl;
		  break;
	 case'6':
		 cout << "---cuando copias en Y ---" << endl;
		 cin >> y;
		 cout << "---cuando copias en X ---" << endl;
		 cin >> xe;
		 cicular.agregar(aplicarfiltro(temp, "expandido", 0, xe,y ), "expandido");
		 cout << "---filtro agregado ---" << endl;
		 break;
	 }
	  
 };
 void exporta() {
	 cicular.temp = cicular.cabeza;
	 cout << "Elige un filtro de  " + temp.cabeza->nombre << endl;
	 while (cicular.temp->sig != cicular.cabeza) {
		 cout << to_string(cicular.temp->pos) + " - " + cicular.temp->nombre << endl;
		 cicular.temp = cicular.temp->sig;
	 }
	 cout << to_string(cicular.temp->pos) + " - " + cicular.temp->nombre << endl;

	 int c;
	 cin >> c;
	 cout << c;
	 cicular.temp = cicular.cabeza;
	 while (cicular.temp->pos != c) {
		 cicular.temp = cicular.temp->sig;
	 }
	 exportar(cicular.temp->data);
 };
 void graficaseleccion() {
	 system("cls");
	 string espacio = tree.in();
	 std::istringstream lin(espacio);
	 string texto = "1";
	 cout << "---ELIGE UNA IMAGEN PARA GRAFICAR----" << endl;
	 int x = 1;
	 while (texto != "") {
		 getline(lin, texto, ';');
		 cout << "\t" + to_string(x) + "  " + texto + "." << endl;
		 x = x + 1;
	 }
	 cout << "---Elige una opcion----" << endl;
	 cin >> x;

	 std::istringstream line(espacio);
	 for (int i = 0; i < x; i++) {
		 getline(line, texto, ';');
	 }
	 temp = tree.buscar(texto);
	 temp.mostrar(temp.cabeza->nombre);
 };
 void mostrarcir() {
	 cout << "reporte de filtros" << endl;
	 cout << "------------------" << endl;
	 cout << " 1 repote de la lista de filtros" << endl;
	 cout << " 2 reporte de todos filtros" << endl;
	 cout << " 3 reporte individual de filtros" << endl;

	 cout << "eligir una opcion" << endl;
	 char c;
	 cin >> c;

	 switch (c)
	 {
	 case'1':
		 cicular.mostrar();
		 break;
	 case '2':
		 cicular.mostrartodo();
		 break;
	 case '3':
	 cicular.temp = cicular.cabeza;
	 cout << "Elige un filtro de  " + temp.cabeza->nombre +"para mostrar su reporte" << endl;
	 while (cicular.temp->sig != cicular.cabeza) {
		 cout << to_string(cicular.temp->pos) + " - " + cicular.temp->nombre << endl;
		 cicular.temp = cicular.temp->sig;
	 }
	 cout << to_string(cicular.temp->pos) + " - " + cicular.temp->nombre << endl;

	 int c;
	 cin >> c;
	 cout << c;
	 cicular.temp = cicular.cabeza;
	 while (cicular.temp->pos != c) {
		 cicular.temp = cicular.temp->sig;
	 }
	 cicular.temp->data.mostrar(cicular.temp->nombre);
		 break;
	 default:
		 
		 break;
	 }
 };
 void reportes() {
	 cout << "seleccionar un reporte" << endl;
	 cout << "-1-reporte de arbol" << endl;
	 cout << "-2-reporte lista de filtros" << endl;
	 cout << "-3-reporte de imagenes" << endl;

	 char x;
	 cin>> x;
	 switch (x)
	 {
	 case'1':
		 tree.inorder();
		 tree.preorder();
		 tree.postorder();
		 tree.graficar();
		 cout << "Reportes del arbol generados en carpeta report " << endl;
		 break;
	 case'2': 

		 mostrarcir();
		 break;
	 case'3':
		  graficaseleccion();
	 default:
		 break;
	 }
 };