#include <iostream>
	
int main (){
	int n;
	int *vector;
	
	std::cout << "Número de elementos: ";
	std::cin >> n;
	std::cout << "la variable X es de " << n << " elementos" << "\n";
	
	vector = new int [n];
	
	for ( int i = 0; i < n; i++ ) {
		std::cout << "Elemento " << i + 1  << ": ";
		std::cin >> vector[i];
	}
	
	std::cout << "\n";
	std::cout << "la variable X es:" << "\n";
	std::cout << "\n";
	std::cout << "( ";
	
	for ( int i = 0; i < n; i++ ) {
		std::cout << vector[i] << " ";
		}
	
	std::cout << ")";
	std::cout << "\n";
	
	return 0;
}
 
