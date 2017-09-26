#include <iostream>
using namespace std;

struct node {
	int num; 
	node* sig; 
	node* ant;
};

node* createnode (int x,node* ant,node* p){
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
	l->ant=ant;
}
void borrar(node* l,int x)
{
	while(l->num!=x){
		l=l->sig;
	}
	l->sig->ant=l->ant;
	l->ant->sig=l->sig;
	delete(l);
}
int main(int argc, char *argv[]) {
	node*h=new node();
	int N,k,m;
	cin>>N>>k>>m;
	link(N,h);
	node*cr=h;
	node*r=h->ant;
	node*aux=h;	
	
	for(int i=1;i<=10;i++){
		cout<<aux->num;
		aux=aux->sig;
	}
	
	while(N>2){
		for(int i=1;i<k;i++){
			cr=cr->sig;
		}
		for(int i=1;i<m;i++){
			r=r->ant;
		}
		if(cr->num==r->num){
			int x=r->num;
			cout<<" "<<x<<",";
			cr=cr->sig;
			r=r->ant;
			borrar(h,x);
			N--;
		}
		else
		{
			cout<<"  "<<cr->num<<"  "<<r->num<<",";
			int x=cr->num;
			int y=r->num;
			cr=cr->sig;
			if (cr->num==r->num){
				cr=cr->sig;
			}
			borrar(h,x);
			r=r->ant;
			borrar(h,y);
			N--;
			N--;
		}
	}
	cout<<"  "<<r->num;
	return 0;
}
