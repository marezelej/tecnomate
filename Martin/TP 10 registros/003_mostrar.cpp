#include <iostream>
#include<string>
#include<sstream>

using namespace std;

int main(int argc, char *argv[]) {
	struct automovil{
		string marca;
		int modelo;
		int year;
		string color;
		const int puertas=4;
		double precio;
	}vw;
	
	struct audio {
		string titulo;
		string autor;
		int year;
		int duracion;
	}cd;
	
	getline(cin,cd.titulo);
	getline(cin,cd.autor);
	cin>>cd.year;
	cin>>cd.duracion;
	
/*	cout<<cd.titulo<<cd.autor<<cd.year<<cd.duracion;*/
	cout<<vw.puertas;
	return 0;
}


