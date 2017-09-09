#include <iostream>
using namespace std;

void ordenarMen(unsigned int vector[],int i,int size){
	bool ord;
	int aux;
	
	do
	{
		ord=true;
		i++;
		for(int j=0;j<size-i;j++)
		{
			if (vector[j]>vector[j+1])
			{
				ord=false;
				aux=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=aux;
			}
		}
	} while(i<size-1 && (ord==false));
}
void ordenarMay(unsigned int vector[],int com,int size){
	bool ord;
	int aux;
	int i=0;
	do
	{
		ord=true;
		i++;
		for(int j=com;j<size-i;j++)
		{
			if (vector[j]<vector[j+1])
			{
				ord=false;
				aux=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=aux;
			}
		}
	} while(i<size-1 && (ord==false));
}
int main(int argc, char *argv[]) {
	unsigned int n;
	unsigned int odd=0;
	unsigned int *list= NULL;
	unsigned int in;
	cin>>n;
	unsigned int even=n-1;
	list= new unsigned int[n];
	for (int i=0;i<n;i++){
		cin>>in;
		if (in % 2==0){
			list[odd]=in;
			odd++;
		}
		else{
			list[even]=in;
			even--;
		}
	}
//	ordenarMen(list,0,odd);
//	ordenarMay(list,odd,n);
	for(int i=0;i<n;i++){
		cout<<list[i]<<endl;
	}
	
	return 0;
}

