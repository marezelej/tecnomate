//https://www.urionlinejudge.com.br/judge/en/problems/view/1244
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> pasaje(string & s, vector <string> & v)
{
	string limite = " ";
	size_t pos = 0;
	string sub;
	while(((pos = s.find(limite)) != std::string::npos))
	{
		sub = s.substr(0, pos);
		v.push_back(sub);
		s.erase(0, pos + limite.length()); //porque find() cuenta desde 1
	}
	v.push_back(s); //la ultima palabra queda dentro de s porque no tiene espacio al final
	s.clear();
	return v;
}

bool noOrdenar (vector <string> & v)
{
	short int bandera = v[0].length(); 
	for(int i = 1; i < v.size(); i++)
	{
		if(bandera != v[i].length())
		{
			return false;
		}
	}
	return true;
}

//funcion obsoleta
void OrdVecStr (vector <string> &v)
{
	for(int i=0; i<v.size()-1;i++)
	{
		for(int j=0; j<v.size()-1-i;j++)
		{
			if(int(v[j].size()) < int(v[j+1].size()))
			{
				string aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}

void girar(vector <string> &v){
	string aux;
	for (int i=0;i<=v.size()/2-1;i++)
	{
		aux = v[i];
		v[i] = v[v.size()-i];
		v[v.size()-i] = aux;
	}
}

int main(int argc, char *argv[]) 
{
	/*función que encuentra la posición de los espacios en blanco y
	función que ingresa substrings a un vector;
	determinar si hace falta ordenar dentro del vector, usando un recorrido
	mostrar todo.
	pasar un if que dependiendo del iterador muestre espacio o newline;
	*/
	int n; 
	cin>>n;
	string linea;
	vector <string> v;
	//ignore n
	cin.ignore(1,' ');
	for(int h=0;h<n;h++)
	{
		getline(cin,linea);
		//cout << "linea es:"<< linea<<endl;
		pasaje(linea,v);
		if(!noOrdenar(v))
		{
		   OrdVecStr(v); 
		   //sort(v.begin(), v.end(), [](const std::string &s1, const std::string &s2) {return s1.size() < s2.size(); }); 
            for(std::vector<string>::iterator f = v.begin(); f != v.end(); f++)
		    {
		        cout << *f;
		        if(f != v.end() -1) cout << " ";
			    else cout << endl;
		    }
		    v.clear(); //borra el contenido del vector
		} 
		else
		{
		    for(std::vector<string>::iterator f = v.begin(); f != v.end(); f++)
		    {
		        cout << *f;
		        if(f != v.end() -1) cout << " ";
			    else cout << endl;
		    }
		}    
		v.clear(); //borra el contenido del vector
		
	}
	return 0;
}
