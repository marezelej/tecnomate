#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	while(cin>>n)
	{
		int count=0,X=0;
		for (int i=0;i<n;i++)
		{
			int A,B;
			cin>>A>>B;
			if (A>X)
			{
				++count;
				X=B;
			}
		}
		cout<<count<<endl;
	}
}
