#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

int dcm(int a, int b){
	int mod= a%b;
	if (mod==0){
		return b;
	}
	else{
		a=mod;
		dcm(b,a);
	}
}

int main(int argc, char *argv[]) {
	unsigned short int n;
	cin>>n;
	string cadena;
	getline(cin,cadena);
	
	for(int i=1;i<=n;i++){
		getline(cin,cadena);
		int n=0;
		int inf=0;
		while(cadena[n]!='/' && n<cadena.size()){
			n++;
		}
		int a1 = atoi(cadena.substr(inf,n).c_str()); //cargar el entero	
		n++;
		inf=n;
		
		while(cadena[n]!='+' && cadena[n]!='-' && cadena[n]!='*' && cadena[n]!='/' && n<cadena.size()){
			n++;
		}
		//n-inf no es el final de la cadena, sino que es el largo a partir de inf que deseo tomar
		int a2 = atoi(cadena.substr(inf,n-inf).c_str());//cargar el entero
		char op=cadena[n];//Carga el operador
		n++;
		inf=n;
		
		while(cadena[n]!='/' && n<cadena.size()){
			n++;
		}
		int b1 = atoi(cadena.substr(inf,n-inf).c_str());//cargar el entero
		n++;
		inf=n;
		while(n<cadena.size()){
			n++;
		}
		int b2 = atoi(cadena.substr(inf,n-inf).c_str());//cargar el entero
		int n1;
		int n2;
		switch (op){
		case '+':
			n1=(a1*b2)+(a2*b1);
			n2=(a2*b2);
			break;
		case '-':
			n1=(a1*b2)-(a2*b1);
			n2=(a2*b2);
			break;
		case '*':
			n1=(a1*b1);
			n2=(b2*a2);
			break;
		case '/':
			n1=(a1*b2);
			n2=(a2*b1);
			break;
		};
		cout<<n1<<"/"<<n2<<" = ";
		int div=dcm(n1,n2);
		n1=n1/div;
		n2=n2/div;
		if (n2<0 && n1>0){
			n1=n1*-1;
			n2=n2*-1;
		}
		cout<<n1<<"/"<<n2<<endl;
	}
	
	return 0;
}

