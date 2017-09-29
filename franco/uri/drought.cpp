// https://www.urionlinejudge.com.br/judge/en/problems/view/1023

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct nodo
{
	int personas;
	int consumo;
	int promedio;
	struct nodo *izq,*der;
};

typedef struct nodo *ABB; 

ABB crearNodo(int a, int b)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->personas= a;
	nuevoNodo->consumo= b;
	nuevoNodo->promedio = trunc(b/a);
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	return nuevoNodo;
}

void insertar(ABB &arbol, int a, int b)
{
    int aux = trunc(b/a);
	if(arbol==NULL)
	{
		arbol = crearNodo(a,b);
	}
	else if(aux == arbol->promedio)
		arbol->personas = arbol->personas + a;
	else if(aux > arbol->promedio)
		insertar(arbol->der, a,b);
	else if(aux < arbol->promedio)
		insertar(arbol->izq,a,b);
}

void enOrden(ABB arbol)
{   
	if(arbol!=NULL)
	{
		enOrden(arbol->izq);
		cout<< arbol->personas <<"-"<<arbol->promedio <<endl;
		enOrden(arbol->der);
	}
}

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
	
	int prop,c, resi, cons;
	c=1;
	double cm, cresi, ccons = 0;
	ABB arbol = {NULL};
	cin>>prop;
	while(prop != 0)
	{   
	    cresi = 0.0;
	    ccons = 0.;
	    for(int i=0;i<prop;i++)
	    {
	        cin>>resi>>cons;
		    cresi = cresi + resi;
		    ccons = ccons + cons;
		    insertar(arbol, resi, cons);  
	    }
	    cout<<endl<<" "<<endl<<"Cidade# "<<c<<":"<<endl;
		enOrden(arbol);
		cm = cm + (ccons/cresi);
		cout<<"Consumo medio: " << fixed << setprecision(2)<<(trunc(cm*100))/100<<" m3.";
		cm = 0;
		cin>>prop;
		matar(arbol);
		c++;
	 }
	return 0;
}
