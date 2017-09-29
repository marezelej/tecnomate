// https://www.urionlinejudge.com.br/judge/en/problems/view/1574

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) 
{
	int casos, mov; 
	vector <int> v;
	string instrucc;
	cin >> casos; 
	
	for(int i=0; i<casos; i++) 
	{
		cin>>mov;
		int pos = 0;
		int idem;
		for(int j=1;j<=mov;j++) 
		{
			getline(cin,instrucc);
			if(instrucc.length() == 5)
			{
				pos = pos +1;
				v.push_back(1);	
			}
			else if(instrucc.length() == 4)
			{	
			    pos = pos -1;
				v.push_back(-1);
			}
			else if(instrucc.length() == 9)
			{
			    /* string toint */
				idem = instrucc[8];
				cout<<v[idem];
				pos = pos + v[idem];
			    v.push_back(v[idem]);
			}
		}
		cout<<pos<<endl;
	}
	return 0;
}
