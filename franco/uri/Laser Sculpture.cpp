//https://www.urionlinejudge.com.br/judge/en/problems/view/1107

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int h,w,x,aux,count;
	cin>>h>>w;
	while(h!=0 && w!=0)
	{
		count=0;
		cin>>x; //Primer entrada
		for(int i=1;i<w;i++) //Un caso menos, despues de todo ya consideramos la primera
		{
			aux=x; //guardamos entrada anterior
			cin>>x; //nueva entrada
			if(x>aux) count+=x-aux; //Contamos las layers
		}
		count+=h-x;
		cout<<count<<endl;
		cin>>h>>w;
	}
	return 0;
}

