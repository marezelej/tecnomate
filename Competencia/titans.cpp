#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	string m;
	string n;
	int x,y,num;
	cin>>x>>y;
	cin.ignore();
	vector <string> nodos;
	for(int i=0;i<x;i++)
	{
		getline(cin,n,' ');
		getline(cin,m,' ');
		cin>>num;
		cin.ignore();
		if(num>=y) nodos.push_back(n+" "+m);
	}
	for(int i=0;i<nodos.size();i++)
	{
		cout<<nodos[i]<<endl;
	}
	return 0;
}

