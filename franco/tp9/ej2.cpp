#include <iostream>
using namespace std;
/* tp9_ej2: Se carga un vector de números enteros y se desea saber si entre dichos números
se encuentra un valor leído anteriormente. En caso afirmativo, visualizar su posición en la lista.
Resolver por Búsqueda a-secuencial y b-binaria
Resolución binaria:*/

/*función búsqueda binaria:
Falta cargar el int con el que se compara (como parámetro por ej)*/
void bus_bin(int v[], int size, int pos, int clave, int pri){
	int j, u, m; //donde carajo usa j
	pos = -1;
	pri = 1;
	u = size -1;
	
	while(pri < u)
	{
		m = (pri + u)/2;
		if(v[m] == clave) //o sea que encontró la posición del elemento
		{
			pos = m;
			pri = m;
		}
		else
		{
			if(clave > v[m])
			{
				pri = m+1; //y al calcular pri+u/2 ahora amplía el rango de búsqueda
			}
			else
			{
				u = m-1; //Ya que es ascendente, si la clave es menor, elimina el último elemento
			}
		};
	}	
}
//incluir función de ordenamiento (burbuja o inserion)

int main(int argc, char *argv[]) {
	const int size = 5;
	int v[size];
	
	for(int i=0; i<size; i++){
		cout << "Ingrese un elemento" << endl;
		cin >> v[i];
	}
		
	int clave =4;
	int pos, pri;
	bus_bin(v, size, pos, clave, pri);
	cout << "pos: " << pos << " pri: " << pri << endl;
	return 0;
}
