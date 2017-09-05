#include <iostream>
#include <vector>
using namespace std;

void ordenar(vector <unsigned short int>&vector,int size){
//	bool ordenado;
//	int aux;
//	int i=0;
//	do{
//		i++;
//		ordenado=true;
//		for (int i=0;i<n-i;i++){
//			if(v[i+1]<v[i]){
//				ordenado=false;
//				aux=v[i+1];
//				v[i+1]=v[i];
//				v[i]=aux;
//			}
//		}
//	}while((ordenado==false)&&(i<n-1));
	bool ord;
	char aux;
	int i=0;
	
	do
	{
		ord=true;
		i++;
		for(int j=0;j<size-i;j++)
		{
			if (vector[j]>vector[j+1])
			{
				ord=false;
				aux=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=aux;
			}
		}
	} while(i<size-1 && (ord==false));
}

int buscar(vector <unsigned short int>&v,unsigned short int clave,unsigned short int n){
	int pos= -1;
	int i=0;
	while((i<=n)&&(clave!=v[i])){
		i++;
	}
	if (clave==v[i]){
		pos=i+1;
	}
	return pos;
}
int main(int argc, char *argv[]) {
	unsigned short int n,q,in;
	int indice;
	unsigned short int caso=0;
	vector <unsigned short int> lista;
	do{
		caso++;
		cout<<"CASE# "<<caso<<":"<<endl;
		cin>>n;
		cin>>q;
		for(int i=0;i<n;i++){
			cin>>lista[i];
		}
		ordenar(lista,n);
//		for (int i=0;i<n;i++){
//			cout<<lista[i]<<" ";
//		}
		for(int i=1;i<=q;i++){
			cin>>in;
			indice = buscar(lista,in,n);
			if(-1 == indice){
				cout<<in<<" not found"<<endl;
			}
			else{
				cout<<in<<" found at "<<indice<<endl;
			}
		}
	} while((q!=0) && (n!=0));
	return 0;
}

