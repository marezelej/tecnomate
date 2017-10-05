// https://www.urionlinejudge.com.br/judge/en/problems/view/1023

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct nodo
{
	short int personas;
	short int promedio;
	struct nodo *izq,*der;
};

typedef struct nodo *ABB; 

ABB crearNodo(int a, int b)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->personas= a;
	nuevoNodo->promedio = b;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	return nuevoNodo;
}

void insertar(ABB &arbol, short int a, short int b)
{
	if(arbol==NULL)
	{
		arbol = crearNodo(a,b);
	}
	else if(b > arbol->promedio)
		insertar(arbol->der, a,b);
	else if(b < arbol->promedio)
		insertar(arbol->izq,a,b);
	else if(b == arbol->promedio)
	   arbol->personas += a;
}

void enOrden(ABB arbol)
{   
	if(arbol!=NULL)
	{
		enOrden(arbol->izq);
		cout<< arbol->personas <<"-"<<arbol->promedio <<endl;
		enOrden(arbol->der);
		free(arbol);
	}
}

//Funcin obsoleta. El árbol muere a medida que es recorrido.
void matar(ABB arbol)
{
	if(arbol != 0 )
	{
		matar(arbol->izq);
		matar(arbol->der);
		delete(arbol);
	}
}

int main(int argc, char *argv[]) {
	
	short int prop,c, resi, cons;
	c=1;
	float cm, cresi, ccons = 0;
	ABB arbol = 0;
	cin>>prop;
	while(prop != 0)
	{   
		cresi = 0.0;
		ccons = 0.;
		for(int i=0;i<prop;i++)
		{
			cin>>resi>>cons;
			cresi += resi;
			ccons += cons;
			cons=trunc(cons/resi);
			insertar(arbol, resi, cons);  
		}
		cout<<"Cidade# "<<c<<":"<<endl;
		enOrden(arbol);
		cm += (ccons/cresi);
		cout<<"Consumo medio: " << fixed << setprecision(2)<<(trunc(cm*100))/100<<" m3."<<endl;
		cm = 0;
		cin>>prop;
		if(prop!=0) cout<<endl;
		//aumentar numero de ciudades:
		c++;
	}
	return 0;
}
