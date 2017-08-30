#include<iostream>
using namespace std;

int main(){
	float vector[10];
	cout<<"Ingrese las componentes del vector:\n";
	for (int i=0;i<10;i++){
		cin>>vector[i]; 
	}
	
	bool tiene;
	bool cero;
	for(int i=0;i<10;i++){
		if(vector[i]<0){
			tiene=1;
		}
		
		if(vector[i]==0){
			cero=1;
		}
	}
	
	if (tiene){
		cout<<"EL vector tiene componentes negativas\n";
	}
	else{
		if(cero==0){
			cout<<"EL vector tiene todas sus componentes positivas\n";
		}
	}
	
	if(cero){
		cout<<"El vector tiene algún cero";
	} //hola
}
