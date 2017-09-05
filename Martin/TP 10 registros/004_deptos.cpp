#include <iostream>
#include<string>
#include<sstream>
using namespace std;

int main(int argc, char *argv[]) {
	struct depto{
		double elec;
		double gas;
		double guard;
		double lav;
		double cons;
	}inq[4];
	
	double gastos[4]={0};
	for (int i=0;i<4;i++){
		cin>>inq[i].elec;
		cin>>inq[i].gas;
		cin>>inq[i].guard;
		cin>>inq[i].lav;
		cin>>inq[i].cons;
		
		gastos[i]+=inq[i].elec;
		gastos[i]+=inq[i].gas;
		gastos[i]+=inq[i].guard;
		gastos[i]+=inq[i].lav;
		gastos[i]+=inq[i].cons;
	}
	
	for(int i=0;i<4;i++){
		cout<<"$"<<gastos[i]<<endl;
	}
	return 0;
}

