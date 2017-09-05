#include <iostream>
using namespace std;

//void ordenar(unsigned short int vector[],int size){
////	bool ordenado;
////	int aux;
////	int i=0;
////	do{
////		i++;
////		ordenado=true;
////		for (int i=0;i<n-i;i++){
////			if(v[i+1]<v[i]){
////				ordenado=false;
////				aux=v[i+1];
////				v[i+1]=v[i];
////				v[i]=aux;
////			}
////		}
////	}while((ordenado==false)&&(i<n-1));
//	bool ord;
//	char aux;
//	int i=0;
//	
//	do
//	{
//		ord=true;
//		i++;
//		for(int j=0;j<size-i;j++)
//		{
//			if (vector[j]>vector[j+1])
//			{
//				ord=false;
//				aux=vector[j];
//				vector[j]=vector[j+1];
//				vector[j+1]=aux;
//			}
//		}
//	} while(i<size-1 && (ord==false));
//}

int buscar(unsigned short int v[],unsigned short int clave,unsigned short int n){
	int count=0;
	bool esta=false;
	for (int i=0;i<n;i++){
		if(v[i]<clave){
			count++;
		}
		if(clave==v[i]){
			esta=true;
		}
	}
	if (esta){
		return count+1;
	}
	else{
		return -1;
	}
}

//int buscar(unsigned short int v[],unsigned short int clave,unsigned short int n){
//	int pos= -1;
//	int i=0;
//	while((i<=n)&&(clave!=v[i])){
//		i++;
//	}
//	if (clave==v[i]){
//		pos=i+1;
//	}
//	return pos;
//}
int main(int argc, char *argv[]) {
	unsigned short int n,q,in;
	int indice;
	unsigned short int caso=0;
	unsigned short int *lista= NULL;
	do{
		caso++;
		cin>>n>>q;
		lista=new unsigned short int[n];
		for(int i=0;i<n;i++){
			cin>>lista[i];
		}
		/*ordenar(lista,n);*/
//		for (int i=0;i<n;i++){
//			cout<<lista[i]<<" ";
//		}
		if(q!=0 && n!=0){
			cout<<"CASE# "<<caso<<":"<<endl;
		}
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

