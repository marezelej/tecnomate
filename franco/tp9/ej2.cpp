#include <iostream>
#include<math.h>
using namespace std;
/* tp9_ej2: Se carga un vector de números enteros y se desea saber si entre dichos números
se encuentra un valor leído anteriormente. En caso afirmativo, visualizar su posición en la lista.
Resolver por Búsqueda a-secuencial y b-binaria
Resolución binaria:*/

/*función búsqueda binaria:
Falta cargar el int con el que se compara (como parámetro por ej)*/

void ord_bur(int v[], int size){
	int i,j,aux=0;
	bool ord;
	do{
		i++;
		ord=true;
		for(int j=0;j<size-i;j++){
			if(v[j]>v[j+1]){
				ord=false;
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	} while((ord==false)&&(i<size-1));
}

int bus_sec(int v[],int clave,int size){
	for(int i=0;i<size;i++){
		if(v[i]==clave){
			return i;
		}
	}
	return -1;
}
int bus_bin(int v[], int size, int clave, int pri){
	int u, m; //donde carajo usa j
	u = size -1;
	
	while(pri <= u)
	{
		m = (pri + u)/2; //Divisi�n entera de enteros
		cout<<"m: "<<m<<endl;
		if(v[m] == clave) //o sea que encontró la posición del elemento
		{
			return m;
		}
		else
		{
			if(clave > v[m])
			{
				pri = m+1; //y al calcular pri+u/2 ahora amplía el rango de búsqueda
				cout<<"pri: "<<pri<<endl;
			}
			else
			{
				u = m-1; //Ya que es ascendente, si la clave es menor, elimina el último elemento
				cout<<"u: "<<u<<endl;
			}
		}
	}	
	return -1;
}
//incluir función de ordenamiento (burbuja o inserion)


int main(int argc, char *argv[]) {
	const int size = 5;
	int v[size];
	
	for(int i=0; i<size; i++){
		cout << "Ingrese un elemento" << endl;
		cin >> v[i];
	}
		
	int clave =4;
	int pri=0;
	ord_bur(v,size);
	for(int i=0;i<size;i++)
	{
		cout<<v[i]<<"  ";
	}
	cout<<endl;
	/*int pos=bus_bin(v, size, clave, pri);*/
	int pos=bus_sec(v,clave,size);
	cout << "pos: " << pos<< endl;
	return 0;
}
