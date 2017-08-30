#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"¿Cuantos elementos posee el vector a ingresar? : ";
	cin>>n;
	int vector[n];
	int v[n];
	for(int i=0;i<n;i++){
		if ((i+1)%2==0){
			vector[i]=0;
		}
		else{
			vector[i]=1;
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<vector[i];
	}
	return 0;
}
