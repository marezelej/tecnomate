#include <iostream>
#include <array>
using namespace std;


int busq_max(int v[], int sizev){
	int posic;
	posic = 0;
	int max;
	max = v[0];
	for(int i = 0; i = sizev; i++){
		if(v[i] > max){
			posic = i;
			maximo = v[i];
		}
	}
	return posic;
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
	
	busq_max(a[], tamaño)
	
	return 0;
}
