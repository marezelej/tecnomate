#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n,a,total;
	bool primero;
	cin>>n;
	while(n!=0)
	{
		int uno=0;
		int count=0;
		total=0;
		primero=true;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			
			if(a!=0) primero=false;
			
			if(primero) uno++;
			
			if(a==0 && !primero) count++;
			else
			{
				total += count / 2;
				count = 0;
			}
			
			if(i==n-1) uno += count;
		}
		if(primero) uno++;
		total+=uno/2;
		
		cout<<total<<endl;
		cin>>n;
	}
	return 0;
}
