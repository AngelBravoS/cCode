#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
	
	ifstream archivo("vector.dat");
	archivo.seekg (0, archivo.end);

	int n=(archivo.tellg())/2;

	archivo.seekg (0, archivo.beg);

	int vector[n];

	for(int i=0;i<n;i++) {
		archivo>>vector[i];
	}

	double media=0;

	for (int i= 0; i < n; i++) {
			media = media + vector[i];
		}

	media = media/n;
	cout << "media: " << media<< endl;

	return 0;
}


