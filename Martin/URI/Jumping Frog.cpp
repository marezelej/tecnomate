//https://www.urionlinejudge.com.br/judge/en/problems/view/1961

#include <iostream>
#include<cmath>
using namespace std;

int main(int argc, char *argv[]) {
	int p,n,a,b;
	cin>>p>>n;
	cin>>a;
	int count=1;
	do{
		b=a;
		cin>>a;
		count++;
	}while(abs(a-b)<=p && count<=n);
	if(count>n){
		cout<<"YOU WIN"<<endl;
	}
	else{
		cout<<"GAME OVER"<<endl;
	}
	return 0;
}
