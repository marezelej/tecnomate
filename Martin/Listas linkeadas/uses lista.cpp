#include <iostream>
using namespace std;

struct Nodo{ 
	int info; // valor que contiene el nodo 
	Nodo* sig; // puntero al siguiente nodo 
};

void agregarNodo(Nodo*& p, int x) 
{ 
	Nodo* nuevo = new Nodo(); 
	nuevo->info = x; 
	nuevo->sig = NULL; 
	if( p==NULL ){ 
		p = nuevo; 
	} 
	else { 
		Nodo* aux = p; 
		while(aux->sig!=NULL ){ 
			aux = aux->sig; 
		} 
		aux->sig = nuevo; 
	} 
}

void mostrar(Nodo* p) { 
	Nodo* aux = p; 
	while( aux!=NULL ) { 
		cout << aux->info << endl; 
		aux = aux->sig; 
	} 
}

void liberar(Nodo*& p) { 
	Nodo* aux; 
	while( p!=NULL ){ 
		aux = p; p = p->sig; 
		delete aux; 
	} 
}

int main(int argc, char *argv[]) {
	Nodo* p= NULL;
	
//	for(int i=10;i<100;i=i+13){
//		agregarNodo(p,i);
//	}
	
	agregarNodo(p,20);
	
	mostrar(p);
	
	liberar(p);
	
	mostrar(p);
	return 0;
}

