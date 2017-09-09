#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	unsigned int n;
	cin>>n;
	bool odd[100001]= {false};
	unsigned long in;
	
	for (unsigned long i=0;i<n;i++){
		cin>>in;
		if (in % 2==0){
			odd[in]=true;
		}
		else{
			odd[in]=true;
		}
	}
	for(long i=2;i<=100000;i=i+2){
		if(odd[i]){
			cout<<i<<endl;
		}
	}
	for(long i=99999;i>=1;i=i-2){
		if(odd[i]){
			cout<<i<<endl;
		}
	}
	return 0;
}

