#include <iostream>
using namespace std;

struct nodo{
	int nro;
	struct nodo *izq, *der;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
para mayor facilidad de creacion de variables */

ABB crearNodo(int x)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	
	return nuevoNodo;
}

void insertar(ABB &arbol, int x)
{
	if(arbol==NULL)
	{
		arbol = crearNodo(x);
	}
	else if(x <= arbol->nro)
	   insertar(arbol->izq, x);
	else if(x >= arbol->nro)
		insertar(arbol->der, x);
}


void enOrden(ABB arbol)
{
	if(arbol!=NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << endl;
		enOrden(arbol->der);
	}
}

void izquierda(ABB arbol)
{
	if(arbol!=NULL)
	{
		izquierda(arbol->der);
		cout << arbol->nro << endl;
		izquierda(arbol->izq);
	}
}
int main()
{
	ABB arbol[2] = {NULL};   // creado Arbol
	
	int n;  // numero de nodos del arbol
	int x; // elemento a insertar en cada nodo
	
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> x;
		insertar(arbol[x % 2], x);
	}
	enOrden(arbol[0]);
	izquierda(arbol[1]);
	return 0;
}

