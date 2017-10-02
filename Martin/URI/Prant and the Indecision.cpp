#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*int letras_favoritas(string &s,string &fav)
{
	int count=0;
	for(unsigned int i=0;i<s.size();i++)
	{
		for(unsigned int j=0;j<fav.size();j++)
		{
			if(s[i]==fav[j]) count++;
		}
	}
	return count;
}

void cambio(string &s,char a,char b)
{
if (a!=b)
{
for(unsigned int i=0;i<s.size();i++)
{
if(s[i]==a) s[i]=b;
else if (s[i]==b) s[i]=a;
}
}
}
*/

unsigned int letras_favoritas(string &fav,vector <unsigned short int> &v)
{
	unsigned int count =0;
	for(int i=0;i<fav.size();i++)
	{
		count = count + v[int(fav[i])-97];
	}
	return count;
}

void contador(string &s,vector <unsigned short int> &v)
{
	for(unsigned int i=0;i<s.size();i++)
	{
		v[int(s[i])-97]++;
	}
}

void cambio(string &s,vector <unsigned short int> &v,char a,char b)
{
	if (a!=b)
	{
		for(unsigned int i=0;i<s.size();i++)
		{
			if(s[i]==a) s[i]=b;
			else if (s[i]==b) s[i]=a;
		}
		int aux=v[int(a)-97];
		v[int(a)-97]=v[int(b)-97];
		v[int(b)-97]=aux;
	}
}
int main(int argc, char *argv[]) {
	int fav,nom,casos;
	string favoritas; //Todas las letras favoritas
	string nombre; //El nombre que se va modificando
	string mejor; //El mejor de todos los nombres
	int count,respuesta; //Letras favoritas
	char a,b; //letras a intercambiar
	//unsigned short int letras[26]={0};
	vector <unsigned short int> letras(26);
	cin>>fav>>nom>>casos;
	cin.ignore();
	getline(cin,favoritas);
	getline(cin,nombre);
	mejor=nombre; //inicializo mejor
	contador(mejor,letras);
	respuesta = letras_favoritas(favoritas,letras); //Inicializo la catidad de letras favoritas en mejor
	
	for(int i=0;i<casos;i++) //Recorrer todos los casos
	{
		cin>>a>>b; //Entrar letras a intercambiar
		cambio(nombre,letras,a,b);
		if(a!=b) count = letras_favoritas(favoritas,letras); //Cuento las letras favoritas
		if(count>respuesta) mejor=nombre; 
	}
	cout<<respuesta<<endl;
	cout<<mejor<<endl;
	return 0;
}

