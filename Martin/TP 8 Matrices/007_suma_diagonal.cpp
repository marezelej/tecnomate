#include <iostream>
using namespace std;

const int m=3;
const int n=3;

int suma_diago(int mat[m][n])
{
	int suma=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (j>i)
			{
				suma+=mat[i][j];
			}
		}
	}
	return suma;
}

int main(int argc, char *argv[]) {
	int matriz[m][n]={{3,2,1},{7,3,4},{8,2,5}};
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<suma_diago(matriz);
	return 0;
}

