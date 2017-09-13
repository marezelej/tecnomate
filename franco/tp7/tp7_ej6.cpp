#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

	char a[10]; //Son los elementos del array, no el índice
	char b[10];
	 
	for(int i = 0; i<10; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i<10; i++){
		b[i] = a[i];
	}
	
	for(int i = 0; i<10; i++){
		cout << b[i];
	}
	return 0;
}

