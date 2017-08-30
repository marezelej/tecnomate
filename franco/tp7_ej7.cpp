#include <iostream>
#include <array>
using namespace std;


void busq_max(int v[], int sizev, int* posic, int* max){
	posic = 0;
	max = v[0];
	for(int i = 0; i = sizev; i++){
		if(v[i] > max){
			posic = i;
			max = v[i];
		}
	}
}

int main(int argc, char *argv[]) {
	int j;
	cin j;
	array <int, j> a;
	
	for (i = 0; i < j+1; i++){
		cin >> a[i];
	}
	
	int tamaño;
	tamaño = a.size();
	
	int lugar;
	int mayor;
	busq_max(a, tamaño, lugar, mayor);
	
	cout << lugar << mayor;
	
	return 0;
}
