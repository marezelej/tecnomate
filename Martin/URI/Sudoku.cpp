//https://www.urionlinejudge.com.br/judge/en/problems/view/1383
#include <iostream>
#include<bitset>
using namespace std;

bitset <9> juan;
bool comprobar(int m[9][9])
{
	for(int i=0;i<9;i++){
		bitset<9> juan;
		for(int j=0;j<9;j++){
			juan.set(m[i][j]-1);
		}
		if(juan.count()!=9) return false;
	}
	for(int i=0;i<9;i++){
		bitset<9> juan;
		for(int j=0;j<9;j++){
			juan.set(m[j][i]-1);
		}
		if(juan.count()!=9) return false;
	}
	
	for(int i=0;i<9;i+=3){
		for(int j=0;j<9;j+=3){
			bitset<9> juan;
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					juan.set(m[i+k][j+l]-1);
				}
			}
			if(juan.count()!=9) return false;
		}
	}
	return true;
}

int main() {
	int n,x;
	cin>>n;
	int m[9][9];
	for(int hola=0;hola<n;hola++){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>m[i][j];
			}
		}
		cout<<"Instancia "<<hola+1<<endl;
		if(comprobar(m))
			cout<<"SIM"<<endl;
		else
			cout<<"NAO"<<endl;
		cout<<endl;
	}
	return 0;
}

