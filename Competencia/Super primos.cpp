#include <iostream>
#include <string>
#include <cmath>

using namespace std;
bool primo(int x){
	if(x==0) return false;
	if(x==2||x==1){
		return true;
	}
	else
	{
		int tope=sqrt(x);
		for(int i=2;i<=tope;i++) {
			if(x%i==0) return false;
		}
		return true;
	}
}
/*bool digitos(char x,string &s)
{
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			int x=stoi(substr(i,j),size_type);
			if(!primo(x)) super=false;
		}
	}
	if(x=='1' || x=='2' || x=='3' || x=='5' || x=='7') return true;
	else return false;
}*/


int main(int argc, char *argv[]) {
	string m;
	int n;
	while(cin>>n)
	{
		if(primo(n))
		{
			int i=0;
			
			m=std::to_string(n);
			bool super=true;
			int n=s.size();
			for(int i=0;i<n;i++)
			{
				for(j=1;j<n-i;j++)
				{
					int x=stoi(substr(i,j),size_type);
					if(!primo(x)) super=false;
				}
			}
			if(super) cout<<"Super"<<endl;
			else cout<<"Primo"<<endl;
		}
		else cout<<"Nada"<<endl;
	}
	return 0;
}

