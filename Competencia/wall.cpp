#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct nodo{
	string nombre;
	string firma;
};


int busqueda(nodo v[],string clave,int n)
{
	for(int i=0;i<n;i++)
	{
		if(v[i].nombre==clave) return i;
	}
}

bool evaluar(string m, string f)
{
	int count =0;
	//cout<<m<<f<<endl;
	for(int i=0;i<m.size();i++)
	{
		if(m[i]!=f[i]) count++; 
	}
	//cout<<count<<endl;
	if (count>1) return false;
	else return true;
}

string pasaje(string & s,int &n)
{
	string limite = " ";
	size_t pos = 0;
	string sub;
	string aux
	while(((pos = s.find(limite)) != std::string::npos))
	{
		sub = s.substr(0, pos);
		
		if(aux!="")aux+=" "+sub;
		else aux+=sub;
		s.erase(0, pos + limite.length()); //porque find() cuenta desde 1
	}
	n=stoi(sub);
	return aux;
}

int main(int argc, char *argv[]) {
	nodo nombres[100];
	string nom,f;
	int n;
	cin>>n;
	
	while(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			getline(cin,nom);
			
			getline(cin,nombres[i].firma);
		}
		cin>>n;
		int count=0;
		for(int i=0;i<n;i++)
		{
			getline(cin,nom,' ');
			getline(cin,f);
			int pos=busqueda(nombres,nom,n);
			if(!evaluar(nombres[pos].firma,f)) count++;
		}
		cout<<count<<endl;
		cin>>n;
		cin.ignore();
	}
	return 0;
}

