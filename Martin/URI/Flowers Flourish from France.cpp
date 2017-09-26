//https://www.urionlinejudge.com.br/judge/en/problems/view/1140

#include <iostream>
#include <string.h>
using namespace std;
char min(char &c)
{
	if((int(c)>=65)&&(int(c)<=90)){
		c=int(c)+32;
	}
	return c;
}

bool evaluar(char c[]){
	char car=min(c[0]);
	for (int i=1;i<(unsigned)strlen(c);i++){
		if(c[i]==' '){
			if(min(c[i+1])!=car){
				return false;
			}
		}
	}
	return true;
}
int main(int argc, char *argv[]) {
	char entrada[2000];
	cin.getline(entrada,2000);
	while(entrada[0]!='*'){
		if(evaluar(entrada)) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
		cin.getline(entrada,2000);
	}
	return 0;
}
