/*Cargar un vector con N elementos. Emitir el valor mínimo y la cantidad de veces que se repitió ese valor.*/
#include <iostream>
using namespace std;

void bus_min(int v[], int size, int* count, int* min){

*min = v[0];
*count = 0;
	
	for (int i = 1; i < size; i++){
		if (v[i] < *min){
			*min = v[i];
			*count=0;
		}
		else if(v[i]==*min){
			*count+=1;
		}
	}
} 


int main (int argc, char *argv[]){
	const int n=5;
	int min;
	int cant;

	int a[n]={0};

	cout <<"Ingrese los elementos del vector (" << n << ")." <<endl;
	for (int i=0;i<n;i++){
		cin>>a[i];
}

bus_min(a,n,&cant,&min);
cout<<"Mínimo es "<<min<<" y se repitió "<<cant<<endl;
	
}

