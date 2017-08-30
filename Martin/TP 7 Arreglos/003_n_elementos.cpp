#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"¿Cuantos elementos posee el vector a ingresar? : ";
	cin>>n;
	int vector[n];
	
	for(int i=0;i<n;i++){
		cout<<"\nIngrese un elemento: ";
		cin>>vector[i];
	}
	
	int suma=0;
	for(int i=2;i<n;i+=2){
		suma+= vector[i];
	}
	cout<<suma;
	return 0;
}
