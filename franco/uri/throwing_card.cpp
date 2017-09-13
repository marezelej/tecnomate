#include <iostream>
#include <deque>
using namespace std;

void asignar(deque <int>& mazo, int n){
	for(int i = 0; i<n; i++){
		mazo[i] = i+1;
	}
}

int main(int argc, char *argv[]) {
	int n;
	deque <int> mazo;
	
	cin >> n;
	while(n != 0){
					
		mazo.resize(n);
		asignar(mazo, n);
		cout << "Discarded cards: ";
		if(n!=1){
			cout << mazo[0];
			mazo.pop_front();
			mazo.push_back(mazo[0]);
			mazo.pop_front();
					
			while(mazo.size() > 1)
			{
				cout << ", " << mazo[0];
				mazo.pop_front();
				mazo.push_back(mazo[0]);
				mazo.pop_front();
			}
		}
		cout << endl << "Remaining card: " << mazo[0] << endl;
		cin >> n;
		} ;
			
	
	return 0;
}
