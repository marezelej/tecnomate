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
	int idem;
	for(int i=0; i<casos; i++) 
	{
		cin>>mov;
		int pos = 0;
		for(int j=0;j<=mov;j++) 
		{
			getline(cin,instrucc);
			if(instrucc.size() == 5)
			{
				pos = pos + 1;
				v.push_back(1);	
			}
			else if(instrucc.size() == 4)
			{	
			    pos = pos -1;
				v.push_back(-1);
			}
			else if(instrucc.size() == 9)
			{
				idem = instrucc[8] - '0';
				pos = pos + v[idem-1];
			    v.push_back(v[idem-1]);
			}
		}
		cout<<pos<<endl;
		v.erase(v.begin(),v.end());
	}
	return 0;
}
