#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	int pos,n,a,b,caso;
	int vec[200] = {0};
	cin>>n;
	caso=0; //Número de cidade
	unsigned long int consumo,personas;
	while(n!=0)
	{
		consumo=0.;
		personas=0.;
		caso++;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			pos=trunc(b/a)-1;
			vec[pos] += a; //Se almacena las personas que consumen x litros
			personas+=a;
			consumo+=b;
		}
		bool primero=true;
		
		if(caso>1) cout<<endl;
		cout<<"Cidade# "<<caso<<":"<<endl;
		for(int i=0;i<200;i++)
		{
			if(vec[i]!=0)
			{
				if(primero) {cout<<vec[i]<<"-"<<i+1; primero=false;}
				else
				   cout<<" "<<vec[i]<<"-"<<i+1;
				vec[i]=0;
			}
		}
		cout<<endl<<"Consumo medio: "<<fixed<< setprecision(2)<<(trunc((double)consumo*100/personas))/100<<" m3."<<endl;
		cin>>n;
	}
	return 0;
}


