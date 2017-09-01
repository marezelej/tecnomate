/*Una empresa posee 20 sucursales con 30 típos de artícuos. Se desea acumular
cantidad de ventas por sucursal y por artículo*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int matriz[30][20]={0}; //Matriz para 30 artículos (filas) de cada sucursal (columnas)
	char tec;
	cout<<"ingrese 0 para salir"<<endl;
	cin>>tec;
	int suc,art;
	while (tec!='0'){
		cout<<"Ingrese sucursal: ";
		cin>>suc;
		cout<<"Ingrese N° de articulo vendido: ";
		cin>>art;
		suc--;
		art--;
		++matriz[art][suc];
		cout<<"ingrese 0 para salir, m para mostrar..."<<endl;
		cin>>tec;
		if(tec=='m'){
			cout<<"SUCURSAL:"<<endl;
			for(int i=0;i<30;i++){
				for(int j=0;j<20;j++){
					cout<<matriz[i][j]<<"|";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}

