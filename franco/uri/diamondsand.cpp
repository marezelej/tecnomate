#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[]) 
{
	int casos; //cantidad de casos
	string caso; // lee los diamantes y puntitos
	int c1,c2,dia; //contadores
	
	cin>>casos;
	for(int i=0;i<casos;i++)
	{	
	    //reinician cada vez
		c1 = 0;
		c2 = 0;
		dia = 0;
		cin>>caso;
		for (auto c : caso) //recorre cada elemento del string caso, desde el primero al último, con índice "c" es variable auxiliar
		{
			if(c == '<')
				c1 = c1 + 1;
			else if(c == '>')
				c2 = c2 + 1;
		}
		dia = min(c1,c2); // la cantidad de diamantes totales es igual al mínimo entre los dos extremos
		cout<<dia<<endl;
	}
	
	return 0;
}
