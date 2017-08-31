//Permitir la carga, listado, consulta, eliminación de los nombres de los pasajeros
//para una empresa de colectivos.

#include <iostream>
using namespace std;

void ord_burb(char vector[],int size)
{
	bool ord;
	char aux;
	int i=0;
	
	do
	{
		ord=true;
		i++;
		cout<<i<<" ";
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

int main(int argc, char *argv[]) {
	const int tam=5; //Límite de pasajeros que se pueden inscibir.
	char caracteres[tam]={'0'};
	
	cout <<"Ingrese los caracteres:"<<endl;
	for(int i=0;i<tam;i++)
	{
		cin>>caracteres[i];
	}
	
	ord_burb(caracteres,tam);
	
	cout<<endl;
	for(int i=0;i<tam;i++)
	{
		cout<<caracteres[i]<<"  ";
	}
	return 0;
}

