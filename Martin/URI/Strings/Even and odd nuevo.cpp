#include <iostream>
using namespace std;
//
//void ordenarOdd(unsigned int vector[],int i,int size,int x){
//	bool ord;
//	int aux;
//	if (vector[0]=0)
//	{
//		vector[size]=x;
//	}
//	else
//	{
//		for(int i=0;i<size;i++)
//		{
//			if (vector[i]>x)
//			{
//				aux=vector[i];
//				vector[i]=x;
//				ord=true;
//			}
//			if (ord)
//			{
//				x=vector[i+1];
//				vector[i+1]=aux;
//				aux=vector[i+2];
//			}
//		}
//	}
//}

void ordSeleccion (unsigned int a[], int n)
{
	int indiceMenor, i, j;
	/* ordenar a[0]..a[n-2] y a[n-1] en cada pasada */
	for (i = 0; i < n-1; i++)
	{
		/* comienzo de la exploración en índice i */
		indiceMenor = i;
		/* j explora la sublista a[i+1]..a[n-1] */
		for (j = i+1; j < n; j++)
			if (a[j] < a[indiceMenor])
				indiceMenor = j;
		/* sitúa el elemento más pequeño en a[i] */
		if (i != indiceMenor)
		{
			double aux = a[i];
			a[i] = a[indiceMenor];
			a[indiceMenor] = aux ;
		}
	}
}

void ordMen (unsigned int a[],int em, int n)
{
	int indiceMenor, i, j;
	/* ordenar a[0]..a[n-2] y a[n-1] en cada pasada */
	for (i = n; i > em+1; i--)
	{
		/* comienzo de la exploración en índice i */
		indiceMenor = i;
		/* j explora la sublista a[i+1]..a[n-1] */
		for (j = i-1; j > em; j--)
			if (a[j] > a[indiceMenor])
				indiceMenor = j;
		/* sitúa el elemento más pequeño en a[i] */
		if (i != indiceMenor)
		{
			double aux = a[i];
			a[i] = a[indiceMenor];
			a[indiceMenor] = aux ;
		}
	}
}
int main(int argc, char *argv[]) {
	unsigned int n;
	unsigned int odd=0;
	unsigned int *list= NULL;
	unsigned int in;
	cin>>n;
	unsigned int even=n-1;
	list= new unsigned int[n];
	for (int i=0;i<n;i++){
		cin>>in;
		if (in % 2==0){
			list[odd]=in;
			odd++;
		}
		else{
			list[even]=in;
			even--;
		}
	}
	ordSeleccion(list,odd);
	ordMen(list,odd,n);
	for(int i=0;i<n;i++){
		cout<<list[i]<<endl;
	}
	return 0;
}

