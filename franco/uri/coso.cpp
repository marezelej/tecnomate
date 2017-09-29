#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int casos;
	string caso;
	cin>>casos;
	int c1,c2,dia;
	int j = 0;
	
		for(int i=0;i<casos;i++)
		{	
			c1 = 0;
			c2 = 0;
			dia = 0;
			getline(cin,caso);
			for (auto c : caso)
			{
				
				if(c == '<')
					c1 = c1 + 1;
				else if(c == '>')
					c2 = c2 + 1;
			}
			dia = min(c1,c2);
			cout<<dia<<endl;
		}
	
	return 0;
}
