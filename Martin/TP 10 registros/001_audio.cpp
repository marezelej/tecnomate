#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	struct audio {
		string titulo;
		string autor;
		int year;
		double duracion;
	}asd;
	
	getline (cin, asd.titulo);
	cout << asd.titulo;
	
	
	return 0;
}

