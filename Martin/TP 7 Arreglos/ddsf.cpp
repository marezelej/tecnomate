#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	string m="123";
	int x = stoi (m,nullptr,10);
	cout<<x;
	return 0;
}

