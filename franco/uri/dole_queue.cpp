#include <iostream>
using namespace std;

struct node {
	int num; 
	node* sig; 
	node* ant;
};

node* createnode (int x,node* &ant,node* &p){
		node* elcoso = new node(); 
		elcoso->num = x;
		elcoso->sig = p; 
		elcoso->ant = ant;
		ant->sig=elcoso;
		return elcoso;
}

void link (int n, node* l){
	l->num=1;
	l->sig=l;
	l->ant=l;
	node*ant=l;
	for(int i=2;i<=n;i++){
		ant=createnode(i,ant,l);
	}
}
int borrar(node* l,int x)
{
	while(l->num!=x){
		l=l->sig;
	}
	int x=l->num;
	l->sig->ant=l->ant;
	l->ant->sig=l->sig;
	free(l);
	return x;
}
int main(int argc, char *argv[]) {
	node*h=new node();
	link(10,h);
	node*aux=h;	
	for(int i=1;i<=10;i++){
		cout<<aux->num;
		aux=aux->sig;
	}
	return 0;
}
