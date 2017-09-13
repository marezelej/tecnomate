#include <iostream>
#include <array>
using namespace std;


void busq_max(int v[], int sizev, int* posic, int* max){
	*posic = 0;
	*max = v[0];
	for(int i = 0; i < sizev; i++){
		if(v[i] > *max){
			*posic = i;
			*max = v[i];
		}
	}
}

int main(int argc, char *argv[]) {
	int a[10];
	
	for (int i = 0; i < 10; i++){
		cin >> a[i];
	}
	
	int tam;
	tam = 10;
	
	int lugar;
	int mayor;
	busq_max(a, sizeof(a)/sizeof(*a), &lugar, &mayor);
	
	cout <<"El máximo es "<< mayor <<" de posición " << lugar;
	
	return 0;
}
