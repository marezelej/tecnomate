// https://www.urionlinejudge.com.br/judge/en/problems/view/1771

#include <iostream>
using namespace std;
bool rango(char x,int n)
{
	switch(x)
	{
	case 'B':if(1<=n&&n<=15) return true;
	case 'I':if(16<=n&&n<=30) return true;
	case 'N':if(31<=n&&n<=45) return true;
	case 'G':if(46<=n&&n<=60) return true;
	case 'O':if(61<=n&&n<=75) return true;
	default: return false;
	}
}
bool  
int main(int argc, char *argv[]) {
	int n;
	int m[5][5]={1};
	m[2][2]=35;
	while(cin>>n){
		for (int i=0;i<5;i++){
			for (int j=0;j<5;j++){
				if(i!=2||j!=2){
					m[i][j]=n;
					cin>>n;
				}
			}
		}
	}
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			cout<< m[i][j] <<" ";
		}
		cout<<endl;
	}
	return 0;
}
