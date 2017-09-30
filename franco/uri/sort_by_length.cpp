//https://www.urionlinejudge.com.br/judge/en/problems/view/1244

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

void OrdVecStr (vector <string> & v)
{
	for(int i=0; i<v.size();i++)
	{
		for(int j=0; j<v.size()-i;j++)
		{
			if(v[j].length() > v[j+1].length())
			{
				string aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
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
		  //si hay que ordenarlo lo ordena y si no hay que ordenarlo lo ordena :)  
            for(std::vector<string>::reverse_iterator j = v.rbegin(); j != v.rend(); j++) //j es de tipo iterador de vector de strings. cosas de la vida, no pregunten
		    {
			    cout << *j; //el iterador es un puntero porque sí
			    if(j != v.rend() -1) cout << " ";
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
