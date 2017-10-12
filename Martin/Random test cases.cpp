#include <iostream>

using namespace std;

int main() {
	int k,m,n;
	k=3;
	m=1000;
	n=1024;
	char a,b;
	cout<<k<<" "<<m<<" "<<n<<endl;
	cout<<"ban"<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<char((rand() % 26)+97);
	}
	cout<<endl;
	for (int i=0;i<n;i++)
	{
		a = char((rand() % 26)+97);
		b = char((rand() % 26)+97);
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
