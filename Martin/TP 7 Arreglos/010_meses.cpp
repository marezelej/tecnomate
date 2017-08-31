#include <iostream>
#include <iomanip>
using namespace std;

void bus_max(double vector[], int size, double& max, int& pos){
	pos = 0;
	max = vector[0];
	
	for(int j = 1; j<size; j++){
		if(max<vector[j]){
			pos = j+1;
			max = vector[j];
		}
	}
}

void bus_min(double vector[], int size, double& min, int& pos){
	pos = 0;
	min = vector[0];
	
	for(int j = 1; j<size; j++){
		if(min>vector[j]){
			pos = j+1;
			min = vector[j];
		}
	}
}
int main(int arg, char *argv[]){ 
	const int tam = 12;
	double ventas[tam];
	double total;
	
	for(int i = 0; i<tam; i++){
		cout << "Ingrese las ventas en el mes: " << i+1 << endl;
		cin >> ventas[i];
		total += ventas[i];
	} 

	cout << fixed << setprecision(3); //cambia la precisión.
	cout << "El promedio de ventas fue: " << total/12.0 << endl;
	cout << "En el mes 10 se vendio: " << ventas[9] << endl;
	 
	double mayor;
	int pos;
	bus_max(ventas, tam, mayor, pos);
	cout << "El mes de mayor ventas fue: " << pos+1 << " donde se vendio: " << mayor << endl;
	
	
	double menor;
	int pos_2;
	bus_min(ventas, tam, menor, pos_2);
	cout << "El mes de menor ventas fue: " << pos_2+1  << " donde se vendio: " << menor << endl;

return 0;
}
