#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

<<<<<<< HEAD
	char a[10]; //Son los elementos del array, no el índice
	char b[10];
=======
	char a[20];
	char b[20];
>>>>>>> 67dea091d9158f0afe4f3e3661fad06b827bf584
	 
	for(int i = 0; i<10; i++){
		cin >> a[i];
<<<<<<< HEAD
=======
    		b[i] = a[i];
		cout << b[i];
>>>>>>> 67dea091d9158f0afe4f3e3661fad06b827bf584
	}
	
	for(int i = 0; i<10; i++){
		b[i] = a[i];
	}
	
	for(int i = 0; i<10; i++){
		cout << b[i];
	}
	return 0;
}

