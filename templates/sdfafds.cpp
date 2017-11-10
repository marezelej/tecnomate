#include <iostream>
#include <string>
using namespace std;

int sumar(string m)
{
	int count=0;
	for(int i=0;i<m.size();i++)
	{
		count+=int(m[i]-'0');
	}
	return count;
}
int main(int argc, char *argv[]) {
	string s,r;
	int a,b; //contadores
	getline(cin,s,' ');
	getline(cin,r);
	while(s!="0" || r!="0")
	{
		a=sumar(s);
		b=sumar(r);
		while(a>9 || b>9)
		{
			s=to_string(a);
			r=to_string(b);
			a=sumar(s);
			b=sumar(r);
		}
		if(a==b){ cout<<"0"<<endl;}
		else if (a>b) {cout<<"1"<<endl;}
		else cout<<"2"<<endl;
		getline(cin,s,' ');
		getline(cin,r);
	}
	return 0;
}

