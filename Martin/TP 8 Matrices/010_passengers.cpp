#include <iostream>
using namespace std;
const int m=3;
const int n=4;//columnas

int suma_fila(int v[][n],int fila){
	int suma=0;
	for(int i=0;i<n;i++){
		suma+=v[fila][i];
	}
	return suma;
}

int suma_colum(int v[][n],int colum){
	int suma=0;
	for(int i=0;i<m;i++){
		suma+=v[i][colum];
	}
	return suma;
}
int max_fila(int v[][n]){
	int max=suma_fila(v,0);
	int pos=0;
	for(int i=1;i<m;i++){
		if(suma_fila(v,i)>max){
			max=suma_fila(v,i);
			pos=i;
		}
	}
	return pos;
}
int max_fila(int v[][n]){
	int max=colum(v,0);
	int pos=0;
	for(int i=1;i<n;i++){
		if(suma_colum(v,i)>max){
			max=suma_colum(v,i);
			pos=i;
		}
	}
	return pos;
}
int main(int argc, char *argv[]) {

	int mat[m][n]={{2,3,4,5},{3,14,15,9},{2,3,5,7}};
	int suma=suma_fila(mat,1);
	int suma2=suma_colum(mat,2);
	cout<<suma<<"     "<<suma2<<endl;
	
	cout<<"SUCURSAL:"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int max=max_fila(mat);
	cout<<max;
	return 0;
}

