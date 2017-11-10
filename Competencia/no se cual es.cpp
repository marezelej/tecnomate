#include <iostream>
#include <vector>
using namespace std;

bool intercambio(vector <int> &m,vector<int> &dir, int n)
{
	bool iguales=true;
	vector<int>aux(200);
	for(int i=0;i<n;i++)
	{
		//cout<<m[i];
		aux[dir[i]-1]=m[i];
	}
	for(int i=0;i<n;i++)
	{
		//cout<<aux[i];
		m[i]=aux[i];
	}
	for(int i=0;i<n;i++)
	{
		//4cout<<m[i]<<endl;
		if(m[i]!=dir[i]) iguales=false;
	}
	return iguales;
}
int main(int argc, char *argv[]) {
	vector <int> dir(200);
	vector<int> modi(200);
	int n,b,count;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b;
		dir[i]=b;
		modi[i]=b;
	}
	count=1;
	while(!intercambio(modi,dir,n)) count++;
	cout<<count;
	return 0;
}

