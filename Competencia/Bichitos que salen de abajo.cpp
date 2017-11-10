#include <iostream>
using namespace std;

void contadores(int m[],int contador[],int n)
{
	for(int i=0;i<n;i++){
		int j=m[i]-1;
		int count=1;
		while(i!=j)
		{
			j=m[j]-1;
			count++;
		}
		contador[i]=count;
	}
}

int mcd(int a,int b)
{
	if(b==0) return a;
	else return mcd(b, a % b);
}
int mcm(int a, int b)
{
	return (a*b)/mcd(a,b);
}

int multiplo(int v[],int ant,int mul,int i,int n)
{
	if(i==n) return mcm(ant,mul);
	else 
	{
		i++;
		return multiplo(v,mcm(ant,mul),v[i],i,n);
	}
}
int main(int argc, char *argv[]) {
	int direcciones[200];
	int contador[200];
	int n,count;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>direcciones[i];
	}
	contadores(direcciones,contador,n);
	count = multiplo(contador,contador[0],contador[1],1,n-1);
	cout<<count<<endl;
	//for(int i=0;i<n;i++) cout<<contador[i]<<endl;
	return 0;
}

