#include <iostream>
using namespace std;

struct Nodo{ 
	int info; // valor que contiene el nodo 
	Nodo* sig; // puntero al siguiente nodo 
};

void insertarPar(Nodo*& p, int v) 
{ 
	Nodo* nuevo = new Nodo(); 
	nuevo->info = v; 
	nuevo->sig = NULL; 
	Nodo* ant = NULL; 
	Nodo* aux = p; 
	while( aux!=NULL && aux->info<v )
	{ 
		ant = aux; aux = aux->sig; 
	} 
	if( ant==NULL )
	{ 
		p = nuevo; 
	} 
	else 
	{ 
		ant->sig = nuevo; 
	} 
	nuevo->sig = aux;
}

void insertarInpar(Nodo*& p, int v) 
{ 
	Nodo* nuevo = new Nodo(); 
	nuevo->info = v; 
	nuevo->sig = NULL; 
	Nodo* ant = NULL; 
	Nodo* aux = p; 
	while( aux!=NULL && aux->info>v )
	{ 
		ant = aux; aux = aux->sig; 
	} 
	if( ant==NULL )
	{ 
		p = nuevo; 
	} 
	else 
	{ 
		ant->sig = nuevo; 
	} 
	nuevo->sig = aux;
}

void mostrar(Nodo* p) { 
	Nodo* aux = p; 
	while( aux!=NULL ) { 
		cout << aux->info << endl; 
		aux = aux->sig; 
	} 
}

int main(int argc, char *argv[]) {
	Nodo* even = NULL;
	Nodo* odd = NULL;
	unsigned int in;
	unsigned int n;
	cin>>n;
	for (unsigned int i=0;i<n;i++){
		cin>>in;
		if (in % 2==0){
			insertarPar(even,in);
		}
		else{
			insertarInpar(odd,in);
		}
	}
	
	mostrar(even);
	mostrar(odd);
	return 0;
}

