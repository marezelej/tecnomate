//https://www.urionlinejudge.com.br/judge/en/problems/view/1251
//Dada una línea de caracteres, imprimir la ocurrencia de cada caracter en forma ordenada

#include <iostream>
#include<string>
using namespace std;

struct nodo{ //Nodos para contener la información...
	int car=0; //el código del caracter
	int count=0; //cuántas ocurrencias hubo de dicho caracter
};

void ordenar(nodo v[],int ult) //Ordenamiento burbuja... eficiencia n^2, con máximo 100 elementos
{
	bool ordenado=false;
	int u=1;
	nodo aux;
	while(!ordenado)
	{
		ordenado=true;
		for(int i=0;i<ult-u;i++)
		{
			if(v[i].count>v[i+1].count){ //Ordenar de forma ascendente por la ocurrencia
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				ordenado=false;
			}
			else if (v[i].count==v[i+1].count) //si la ocurrencia es igual
				if(v[i].car<v[i+1].car){ //ordenar de forma descendente por código ascii
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				ordenado=false;
			}
		}
		u++;
	}
}
void insertar(nodo v[],char a,int &ult){ //Para insertar los nodos en el vector
	int i=0;
	while(v[i].car!=0 && v[i].car!=int(a)){ //Buscamos si el nodo ya existe (por codigo ASCII) o si hay nodos vacios
		i++;
	}
	if(v[i].car==0) ult++; //Si cargamos en un nodo vacio, incrementamos ultimo
	v[i].car=int(a); //cargamos el codigo, si ya estaba cargado no importa sobreescribir, son iguales
	v[i].count++; //incrementamos la ocurrencia en uno
}
int main(int argc, char *argv[]) {
	bool primero=true; //Para saber si la imput tratada es la primera o no (por los saltos de línea)
	string palabra; //String donde cargamos linea por linea
	nodo vector[100]; //Vector de 100 nodos, total son del 32 al 128 en ascii
	int ult=0; //Cuántos elementos posee cargado el vector?
	while(cin){ //Mientras tengamos entrada...
		getline(cin,palabra); //Obtenemos la línea
		for(int i=0;i< palabra.length();i++){ //Para todos los elementos del string
			insertar(vector,palabra[i],ult); //insertamos caracter a caracter
		}
		ordenar(vector,ult); //Ordenamos el vector
		if(!primero && cin) cout<<endl; //Imprimimos una línea si no es el primero ni el último
		for(int i=0;i<ult;i++){ //Para todo el vector
				cout<< vector[i].car<<" "<<vector[i].count<<endl; //Imprimimos la info
				vector[i].car=0; //reseteamos el vector
				vector[i].count=0;
		}
		ult=0; //reseteamos último
		primero=false; //Ya no es el primero, lero lero
	}
	return 0; //FIN
}

