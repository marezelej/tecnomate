#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct nodo{
	int a;
	int b;
};


int partition (vector <nodo> &v, const int &left, const int &right){
	int mid = left + (right - left) / 2;
	int pivot = v[mid].b;
	
	std::swap(v[mid],v[left]);
	int i = left +1;
	int j = right;
	
	while(i <= j){
		while(i <= j && v[i].b <= pivot){
			i++;
		}
		
		while(i <= j && v[j].b > pivot){
			j--;
		}
		
		if(i < j){
			std::swap(v[i],v[j]);
		}
		
	}
	std::swap(v[i-1],v[left]);
	return i-1;
}

void quicksort(vector <nodo> & v, const int& left, const int& right){
	
	if (left >= right)	return;
	
	int part = partition(v, left, right);
	
	quicksort(v, left, part - 1);
	quicksort(v, part + 1, right);
}

int main(int argc, char *argv[]) {
	vector <nodo> intervalos(100000);
	int n,count;
	
	while(cin)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>intervalos.at(i).a>>intervalos.at(i).b;
		}
		
		quicksort(intervalos,0,n-1);
		for(int i=0;i<n;i++)
		{
			cout<<intervalos.at(i).a<<" "<<intervalos.at(i).b<<endl;
		}
		int i=0;
		int actual=intervalos.at(i++).b;
		count=1;
		while(i<n)
		{
			while(i<n && intervalos.at(i).a<=actual) i++;
			if(i==n) break;
			else
			{
				count++;
				actual=intervalos.at(i++).b;
			}
		}
//		count=0;
//		tam=0;
//		max=0;
//		x=1;
//		
//		for(int i=0;i<n;i++)
//		{
//			if(intervalos.at(i).a==x)
//			{
//				if(intervalos.at(i).b>max) max=intervalos.at(i).b;
//			}
//			else
//			{
//				maximos.at(tam).a=intervalos.at(i-1).a;
//				maximos.at(tam).b=max;
//				tam++;
//			}
//		}
//		for(int i=0;i<tam;i++)
//		{
//			if (maximos.at(i).a>x)
//			{
//				++count;
//				x=maximos.at(i).b;
//			}
//		}
		cout<<count<<endl;
	}
	return 0;
}

