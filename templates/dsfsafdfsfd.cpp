#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	int a,b,c,res;
	
	cin>>a>>b>>c;
	res = min(2*a+2*c,4*c+2*b);
	res = min(res, 4*a+2*b);
	cout<<res<<endl;
	
	return 0;
}

