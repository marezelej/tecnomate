#include <iostream>
using namespace std;

bool posible(int dis,int vel)
{
	int rec=0;
	
	while(vel>0)
	{
		for(int i=0;i<vel;i++)
		{
			rec=rec+vel;
			if (dis==rec) return true;
		}
		vel--;
	}
	return false;
}
int main(int argc, char *argv[]) {
	cout<<posible(14,3);
	return 0;
}

