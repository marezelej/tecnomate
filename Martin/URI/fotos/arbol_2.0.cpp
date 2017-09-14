#include <iostream>
using namespace std;
struct nodo{
	int min;
	int max;
	struct nodo *izq, *der;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
para mayor facilidad de creacion de variables */

ABB crearNodo(int x,int y)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->min = x;
	nuevoNodo->max = y;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	
	return nuevoNodo;
}

void insertar(ABB &arbol, int x,int y)
{
	if(arbol==NULL)
	{
		arbol = crearNodo(x,y);
	}
	else if(x < arbol->min)
	   insertar(arbol->izq, x,y);
	else if(x > arbol->min)
		insertar(arbol->der, x,y);
	else if(y > arbol->max)
		arbol->max=y;
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

int contar(ABB arbol,int &count)
{
	if(arbol!=NULL)
	{
		contar(arbol->izq,count);
			++count;
		contar(arbol->der,count);
	}
	return count;
}

int main(int argc, char *argv[]) {
	int n;
	int A,B,count;
	while(cin>>n)
	{
		ABB arbol = {NULL};   // creado el Arbol
		for (int i=0;i<n;i++) //para todos los casos
		{
			cin>>A>>B; //ingresar valores de A y B
			insertar(arbol,A,B); //insertar los nodos en el arbol de manera ordenada
		}
		enOrden(arbol); //mostrar el arbol ordenado
		count=0;
		cout<<contar(arbol,count)<<endl; //contar los nodos del arbol
	}
	return 0;
}

