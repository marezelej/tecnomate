#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool palindromo(string s)
{
	bool bandera=true; 
	unsigned int n = s.size()-1; //Tamaño
	
	for(unsigned int i=0;i<=n;i++)
	{
		if(s[i]=='.' || s[i]==',') s.erase(i,1); //Descartamos caracteres no deseados
	}
	//cout<<s<<endl;
	n = s.size()-1;
	for(unsigned int i=0;i<=(n+1)/2;i++)
	{
		if(s[i]!=s[n-i]) bandera=false; //Comprobamos si es palíndromo
	}
	return bandera;
}

void suma(string &s,int n)
{
	if(s[n]<'9') s[n]++;
	else 
	{
		if(s[n-1]!='.' && s[n-1]!=',')
		{
			s[n]='0';
			suma(s,n-1);
		}
		else
		{
			s[n]='0';
			suma(s,n-2);
		}
	}
	
}

float digitos(string s)
{
	int i=s.size()-1;
	int count=0;
	int vuelta=0;
	
	while(s[i]!='.'&&i>0)
	{
		count++;
		i--;
	}
	
	return pow(10,count);
}

void decimal(string &s)
{
	bool bandera=false;
	unsigned int n=s.size();
	for(unsigned int i=0;i<n;i++)
	{
		if(s[i]=='.') bandera=true; //Encontramos un punto
	}
	
	if(!bandera) //si no hay puntos
	{
		s+='.'; //agregamos el puntillo
		for(unsigned int i=0;i<n;i++)
		{
			s+='0'; //Agregamos ceros
		}
	}
}
int main(int argc, char *argv[]) {
	string s;
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		getline(cin,s);
		int count=0;
		
		if(!palindromo(s)) decimal(s); //Por si s no tiene coma
		
		while(!palindromo(s))
		{
			count++;
			suma(s,s.size()-1);
		}
		cout<<count/digitos(s)<<endl;
	}
	
	return 0;
}

