#include <iostream>
using namespace std;
	
int main (){
	int n;
	int *vector;
	cout << "Número de elementos: ";
	cin >> n;
	cout << "la variable X es de " << n << " elementos" << endl;
	vector = new int [n];
	for ( int i = 0; i < n; i++ ) {
		cout << "Elemento " << i + 1  << ": ";
		cin >> vector[i];
	}
	cout << endl;
	cout << "la variable X es:" << endl;
	cout << endl;
	cout << "( ";
	for ( int i = 0; i < n; i++ ) {
		cout << vector[i] << " ";
		}
	cout << ")";
	cout << endl;
	return 0;
}
 
