#include <iostream>
#include<cmath>
using namespace std;
bool primo(int x){
	if(x==2){
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
int main(int argc, char *argv[]) {
	int n,m;
	int P1,P2;
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		if(primo(i)){
			P1=i;
		}
	}
	for(int i=2;i<=m;i++){
		if(primo(i)){
			P2=i;
		}
	}
	cout<<P1*P2<<endl;
	return 0;
}
