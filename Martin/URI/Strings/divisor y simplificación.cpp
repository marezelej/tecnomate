#include <iostream>
using namespace std;

int dcm(int a, int b){
	int mod= a%b;
	if (mod==0){
		return b;
	}
	else{
		a=mod;
		dcm(b,a);
	}
}
int main(int argc, char *argv[]) {
	int a;
	int b;
	cin>>a;
	cin>>b;
	int div=dcm(a,b);
	a=a/div;
	b=b/div;
	cout<<a<<"/"<<b<<endl;
	return 0;
}

