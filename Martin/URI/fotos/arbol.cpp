#include <iostream>
using namespace std;
struct nodo{
	int min,max;
	struct nodo *izq, *der;
};
typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
para mayor facilidad de creacion de variables */

ABB crearNodo(int A,int B)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->min= A;
	nuevoNodo->max= B;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	
	return nuevoNodo;
}

bool incluido(ABB &arbol, int A, int B)
{
	if(A<=arbol->min && B>=arbol->max)
	{
		arbol->min=A;
		arbol->max=B;
		return true;
	}
	return false;
}

void insertar(ABB &arbol, int A, int B)
{
	if(arbol==NULL)
	{
		arbol = crearNodo(A,B);
	}
	else if(incluido(arbol,A,B));
	else if(A < arbol->min)
		insertar(arbol->izq, A,B);
	else if(A >= arbol->max)
		insertar(arbol->der, A,B);
	else if(B >= arbol->max)
		insertar(arbol->der, A,B);
}


void enOrden(ABB arbol)
{
	if(arbol!=NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->min <<" "<<arbol->max <<endl;
		enOrden(arbol->der);
	}
}

int recorrer(ABB arbol,int count)
{
	int X=0;
	if(arbol!=NULL)
	{
		recorrer(arbol->izq,count);
		if (arbol->max>X)
		{
			++count;
			X=arbol->max;
		}
	}
	recorrer(arbol->der,count);
	return count;
}
int main(int argc, char *argv[]) {
	int n;
	ABB arbol = {NULL};   // creado Arbol
	
	while(cin>>n)
	{
		int count=0,X=0;
		for (int i=0;i<n;i++)
		{
			int A,B;
			cin>>A>>B;
			insertar(arbol,A,B);
		}
	}
	enOrden(arbol);
	cout<<recorrer(arbol,0)<<endl;
	return 0;
}
