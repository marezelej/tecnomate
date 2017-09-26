#include <iostream>
using namespace std;
struct cajero{
	int time;
	int actual;
	unsigned int total=0;
};

void restar(cajero *p,int n,int x)
{
	for(int i=0;i<n;i++)
	{
		p[i].actual=p[i].actual-x;
		p[i].total+=x;
	}
}

int minimo(cajero *p,int n)
{
	int min;
	int indice=0;
	min=p[0].actual;
	for(int i=0;i<n;i++){
		if(p[i].actual<min){
			min=p[i].actual;
			indice=i;
		}
	}
	restar(p,n,min);
	return indice;
}

int maximo(cajero *p,int n)
{
	int max;
	max = p[0].total;
	for(int i=0;i<n;i++){
		p[i].total+=p[i].actual;
		if(p[i].total>max){
			max=p[i].total;
		}
	}
	return max;
}

int main(int argc, char *argv[]) {
	int n,m,t,p,indice;
	cin>>n>>m;
	int libre=0;
	cajero *c= NULL;
	c=new cajero[n];
	for(int i=0;i<n;i++){
		cin>>t;
		c[i].time=t;
	}
	for(int i=0;i<m;i++){
		cin>>p;
		if(libre<n){
			c[libre].actual=p*c[libre].time;
			libre++;
		}
		else{
			indice=minimo(c,n);
			c[indice].actual=p*c[indice].time;
		}
	}
	cout<<maximo(c,n)<<endl;
	return 0;
}

