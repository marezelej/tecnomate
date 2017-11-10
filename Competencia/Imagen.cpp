#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n,m,a,b;
	char k;
	char mat[50][50];
	cin>>n>>m;
	while(n!=0 && m!=0)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				cin>>k;
				mat[i][j]=k;
			}
		}
		cin>>a>>b;
		a=a/n;
		b=b/m;
		for (int i=0;i<n;i++)
		{
			for(int x=0;x<a;x++)
			{
				for (int j=0;j<m;j++)
				{
					for(int y=0;y<b;y++) cout<<mat[i][j];
				}
				cout<<endl;
			}
		}
		cout<<endl;
		cin>>n>>m;
	}
	return 0;
}

