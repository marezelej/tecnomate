#include <iostream>
#include <deque>
using namespace std;

struct nodo{
	int info;
	struct nodo *sig;
};

nodo crear(int x,nodo *siguiente)
{
	nodo nuevoNodo = new nodo();
	nuevoNodo->info=x;
	nuevoNodo->sig=siguiente;
	return nuevoNodo;
}

void insertar()
{
	
}
int main(int argc, char *argv[]) {
	
	do
	{
		cin>>n;
	} while(n!=0);
	return 0;
}

