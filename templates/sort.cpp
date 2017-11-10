#include <iostream>
using namespace std;
struct nodo{
	int nro;
	struct nodo *izq, *der;
};


typedef struct nodo *ABB;

ABB crearNodo(int nro)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->nro= nro;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	
	return nuevoNodo;
}

void insertar(ABB &arbol, int nro)
{
	if(arbol==NULL)            arbol = crearNodo(nro);
	else if(nro < arbol->nro)    insertar(arbol->izq, nro);
	else if(nro >= arbol->nro)   insertar(arbol->der, nro);
}

void insertar_par(ABB &arbol, int &x, int&m)
{
	if(arbol==NULL)
	{
		arbol=crearNodo(x);
	}
	else if(x % m > arbol->nro % m)    insertar_par(arbol->izq, x,m);
	else if(x % m < arbol->nro % m)   insertar_par(arbol->der, x,m);
	else if(arbol->nro % 2 ==0)    insertar_par(arbol->der, x,m);
	else if(arbol->nro >x)   insertar_par(arbol->izq, x,m);
	else insertar_par(arbol->der, x,m);
}

void insertar_impar(ABB &arbol, int &x, int&m)
{
	if(arbol==NULL)
	{
		arbol=crearNodo(x);
	}
	else if(x % m > arbol->nro % m)    insertar_impar(arbol->izq, x,m);
	else if(x % m < arbol->nro % m)   insertar_impar(arbol->der, x,m);
	else if(arbol->nro % 2 !=0)    insertar_impar(arbol->izq, x,m);
	else if(arbol->nro <x)   insertar_impar(arbol->izq, x,m);
	else insertar_impar(arbol->der, x,m);
}

void ascendente(ABB arbol)
{
	if(arbol!=NULL)
	{
		ascendente(arbol->izq);
		cout << arbol->nro<<endl;
		ascendente(arbol->der);
		delete(arbol);
	}
}

void descendente(ABB arbol)
{
	if(arbol!=NULL)
	{
		descendente(arbol->der);
		cout << arbol->nro<<endl;
		descendente(arbol->izq);
		delete(arbol);
	}
}
int main(int argc, char *argv[]) {
	int n,m;
	int x;
	cin>>n>>m;
	cout<<n<<" "<<m<<endl;
	while(n!=0 && m!=0)
	{
		ABB arbol= {NULL};
		for(int i=0;i<n;i++){
			cin>>x;
			if(x%2==0) insertar_impar(arbol,x,m);
			else insertar_par(arbol,x,m);
			
		}
		descendente(arbol);
		cin>>n>>m;
		cout<<n<<" "<<m<<endl;
	}
	return 0;
}

