// https://www.urionlinejudge.com.br/judge/en/problems/view/1771

#include <iostream>
using namespace std;
int rango(int n)
{
	if(1<=n&&n<=15) return 0;
	else if(16<=n&&n<=30) return 1;
	else if(31<=n&&n<=45) return 2;
	else if(46<=n&&n<=60) return 3;
	else if(61<=n&&n<=75) return 4;
} 

bool perm(int m[5][5])
{
	int B=0;
	int I=0;
	int N=0;
	int G=0;
	int O=0;
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(i!=2||j!=2){
				switch(m[i][j]){
				case 0:B++; break;
				case 1:I++; break;
				case 2:N++; break;
				case 3:G++; break;
				case 4:O++; break;
				}
			}
		}
	}
	if(B==5&&I==5&&N==4&&G==5&&O==5)return true;
	else
		return false;
}

int evaluar(int m[5][5])
{
	int e=0;
	for (int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(m[j][i]!=i)
			{
				e=2;
				//cout<<"i:"<<i<<" j:"<<j<<"m[j][i]:"<<m[j][i]<<endl;
				if(perm(m))
				{
					e=1; 
				}
			}
		}
	}
	return e;
}
int main(int argc, char *argv[]) {
	int n,res;
	int m[5][5]={1};
	m[2][2]=2;
	while(cin){
		for (int i=0;i<5;i++){
			for (int j=0;j<5;j++){
				if(i!=2||j!=2){
					cin>>n;
					m[i][j]=rango(n);
				}
			}
		}
		res=evaluar(m);
		if(cin){
			if (res==0)cout<<"OK"<<endl;
			else if (res==1)cout<<"RECICLAVEL"<<endl;
			else cout<<"DESCARTAVEL"<<endl;
		}
		/*for (int i=0;i<5;i++){
		for (int j=0;j<5;j++){
		cout<< m[i][j] <<" ";
		}
		cout<<endl;
		}*/
	}
	return 0;
}
