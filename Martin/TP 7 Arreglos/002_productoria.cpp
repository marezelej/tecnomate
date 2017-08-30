#include <iostream>
using namespace std;

int main(){
	int lista[100];
	int product=1;
	int i=0;
	
	cin>>lista[i];
	while(lista[i]!=0){
		i++;
		cin >> lista[i];
	}
	
	for(int j=0;j<i;j++){
		product=product*lista[j];
	}
	
	cout<<product;
	return 0;
}
