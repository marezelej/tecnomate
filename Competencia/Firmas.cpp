#include <iostream>
#include <string>
using namespace std;

string pasaje(string & s,int &n)
{
	string limite = " ";
	size_t pos = 0;
	string sub;
	string aux="";
		while(((pos = s.find(limite)) != std::string::npos))
	{
		sub = s.substr(0, pos);
		
		if(aux!="") aux+=" "+sub;
		else aux+=sub;
		s.erase(0, pos + limite.length()); //porque find() cuenta desde 1
	}
		n=std::stoi(sub,nullptr,10);
		return aux;
}

int main(int argc, char *argv[]) {
	string nom,f;
	int n,y,x;
	cin>>n>>y;
	cin.ignore();
	while(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			getline(cin,nom);
			f=pasaje(nom,x);
			if(x>y) cout<<f<<endl;
		}
		cin>>n>>y;
	}
	return 0;
}

