//https://www.urionlinejudge.com.br/judge/en/problems/view/2174

#include <iostream>
#include<string>
using namespace std;

int count=0;

typedef struct nodo *ABB;

struct nodo{
	string nro;
	struct nodo *izq, *der;
};

ABB crearNodo(string x)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	
	return nuevoNodo;
}

void insertar(ABB &arbol, string x)
{
	if(arbol==NULL)
	{
		arbol = crearNodo(x);
	}
	else if(x < arbol->nro)
	   insertar(arbol->izq, x);
	else if(x > arbol->nro)
		insertar(arbol->der, x);
}


void enOrden(ABB arbol)
{
	if(arbol!=NULL)
	{
		enOrden(arbol->izq);
		count++;
		enOrden(arbol->der);
	}
}

int main() {
	ABB arbol = NULL; 
	string x;
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin,x);
		insertar(arbol,x);
	}
	enOrden(arbol);
	cout<<"Falta(m) " << 151-count<<" pomekon(s)."<<endl;
}
