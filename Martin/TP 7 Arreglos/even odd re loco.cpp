#include <iostream>
#define MAX 1000
using namespace std;
void QuickSort(unsigned int a[] , int n)
{
	int tope, ini, fin , pos;
	int may[MAX],menor[MAX];
	tope=0;
	menor[tope]=0;
	may[tope]=n-1;
	while(tope>=0)
	{
		ini = menor[tope];
		fin = may[tope];
		tope--;
		
		int izq,der,aux;
		bool band;
		izq=ini;
		der=fin;
		pos=ini;
		
		band=true;
		
		while(band==true)
		{
			while((a[pos]<a[der]) && ( pos!=der ))
				der--;
			
			if(pos==der)
				band=false;
			else
			{
				aux=a[pos];
				a[pos]=a[der];
				a[der]=aux;
				pos=der;
			}
			
			while((a[pos]>a[izq]) && ( pos!=izq ))
				izq++;
			
			if(pos==izq)
				band=false;
			else
			{
				aux=a[pos];
				a[pos]=a[izq];
				a[izq]=aux;
				pos=izq;
			}
			
			
		}
		
		if(ini<=(pos-1))
		{
			tope++;
			menor[tope]=ini;
			may[tope]=pos-1;
			
		}
		
		if(fin>=(pos+1))
		{
			tope++;
			menor[tope]=pos+1;
			may[tope]=fin;
		}
		
		
		
		
	}
	
}

void OrdRapMay(unsigned int lista[],int inf,int sup)
{
	int elem_div = lista[sup];
	int i = inf - 1;
	int j = sup;
	bool cont = true;
	if (inf >= sup){
		return;
	}
	while (cont){
		i++;
		while (lista[i] < elem_div && cont)
		{
			j--;
			while (lista[j] > elem_div && cont)
			{
				if (i < j){
					int temp = lista[i];
					lista[i] = lista[j];
					lista[j] = temp;
				}
				else{
					cont = false;
				}
			}
		}
	}
	int temp = lista[i];
	lista[i] = lista[sup];
	lista[sup] = temp;
	
	OrdRapMay (lista, inf, i - 1);
	OrdRapMay (lista, i + 1, sup);
}

int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	unsigned int *list= NULL;
	list=new unsigned int[n];
	unsigned int in;
	unsigned int even=0;
	unsigned int odd=n-1;
	for (int i=0;i<n;i++){
		cin>>in;
		if (in % 2==0){
			list[even]=in;
			even++;
		}
		else{
			list[odd]=in;
			odd--;
		}
	}
	unsigned int *pares=NULL;
	pares= new unsigned int[even];
	
	int tam=n-even;
	unsigned int *inpares=NULL;
	inpares= new unsigned int[tam];
	
	for(int i=0;i<even;i++){
		pares[i]=list[i];
	}
	for(int i=0;i<tam;i++){
		inpares[i]=list[i+even];
	}
	
//	OrdRapMay(pares,0,even-1);
//	OrdRapMay(inpares,0,tam-1);
	QuickSort(pares,even);
	QuickSort(inpares,tam);
	for(int i=0;i<even;i++){
		cout<<pares[i]<<endl;
	}
	
	for(int i=tam-1;i>=0;i--){
		cout<<inpares[i]<<endl;
	}
	return 0;
}
