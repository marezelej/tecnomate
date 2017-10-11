//https://www.urionlinejudge.com.br/judge/en/problems/view/1162

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void burbuja(vector <short int> & v, int & counter)
{
	counter = 0;
	for (int i=0;i<v.size()-1;i++){
		for(int j=0;j<v.size()-i-1;j++){
			if(v[j]>v[j+1]){
				std::swap(v[j],v[j+1]);
				counter++;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int casos,vagones, orden, counter;
	vector <short int> tren; 
	
	cin>>casos; 
	for(int i=0;i<casos;i++)
	{
		cin>>vagones; 
		for(int j=0; j<vagones;j++)
		{
			cin>>orden; 
			tren.push_back(orden);
		}
		burbuja(tren, counter);
		cout<< "Optimal train swapping takes "<< counter <<" swaps."<<endl;
		tren.clear();
	}
	
	
	return 0;
}
