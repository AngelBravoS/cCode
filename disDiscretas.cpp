#include <iostream>
#include <math.h>
using namespace std;

//Prototipos:
//funciones de seleccion y visualizacion
void distribucionSeleccionada();
char menuIntro();
void resultados(char distribucion);

// funciones matematicas
double factorial(double n);
double potencia(double numero, int potencia);
double binomio(double a, double b);
unsigned long long int convierteDoubleEnInt (double_t doble);

// funciones de distribuciones de probabilidad
double bernouilli(float p, unsigned short int probabilidad);
double binomial(unsigned short int N, float p, 
	unsigned short int probabilidad);
double binomialNegativa(unsigned short int n, float p, 
	unsigned short int probabilidad);
double hipergeometrica(unsigned short int N, unsigned short int n, 
		unsigned short int r, unsigned short int probabilidad);	
double poisson(float p, unsigned short int probabilidad);	
double geometrica(float p, unsigned short int probabilidad);


//funciones de seleccion y visualizacion		

void resultados(char distribucion){
	unsigned short int n;
	unsigned short int probabilidad;
	unsigned short int N;
	unsigned short int r;
	float p; 
	cout << "======================================= " << endl;
	cout << "Valor de x: ";
	cin >> probabilidad;
	switch (distribucion) {
	case '1': //Bernouilli
		cout << "Valor de p: ";
		cin >> p;
		cout << "Distribución Bernuilli X~>B("<< p << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
			bernouilli(p, probabilidad) << endl;
		break;
	case '2': //Binomial
		cout << "Valor de p: ";
		cin >> p;
		cout << "Valor de n: ";
		cin >> n;
		cout << "Distribución Binomial X~>B("<< n << ","<< 
			p << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
			binomial(n, p, probabilidad) << endl; 
		break;
	case '3': //Binomial negativa
		cout << "Valor de p: ";
		cin >> p;
		cout << "Valor de n: ";
		cin >> n;
		cout << "Distribución Binomial negativa X~>BN("<< n << 
			"," << p << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
			binomialNegativa(n, p, probabilidad) << endl; 
		break;	
	case '4': //Hipergeometrica
		cout << "Parámetro N: ";
		cin >> N;
		cout << "Parámetro n: ";
		cin >> n;
		cout << "Parámetro r: ";
		cin >> r;
		cout << "Distribución Hipergeométrica X~>H("<< N << 
			","<< n << "," << r << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
			hipergeometrica(N, n, r, probabilidad) << endl; 
		break;	
	case '5': //Poisson
		cout << "Valor de lambda: ";
		cin >> p;
		cout << "Distribución Poisson X~>P("<< p << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
		poisson(p, probabilidad) << endl; 
		break;
	case '6': //Geometrica
		cout << "Valor de p: ";
		cin >> p;
		cout << "Distribución Geométrica X~>G(" << p << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< geometrica(p, probabilidad) << endl; 
		break;
	break;
	}
	cout << "======================================= " << endl;
	cout << endl;
}

char menuIntro(){
	char distribucion;
	 cout << "Distribuciones de probabilidad discretas" << endl;
	 cout << "Distribuciones a elegir:" << endl;
	 cout << "1.- Bernouilli." << endl;
	 cout << "2.- Binomial." << endl;
	 cout << "3.- Binomial negativa." << endl;
	 cout << "4.- Hipergeométrica." << endl;
	 cout << "5.- Poisson." << endl;
	 cout << "6.- Geométrica." << endl;
	 cout << "> ";
	 cin >> distribucion;
	 return distribucion;
}

void distribucionSeleccionada(){
	char distribucion = menuIntro();
	resultados(distribucion);
}

// funciones matematicas			

double factorial(double n) {
	if (n==0) {
		// Aseguramos que tenga salida siempre
		return 1;                      
	}
	else {
		// Caso general
		return  n*factorial(n-1);
	 }                          
}

double potencia(double numero, int potencia) {
	double temporal = numero;
	if (potencia==0){
		numero = 1;
		}
	else{
		for (int x=1; x<potencia; x++) {
			numero=numero*temporal;
		}
	}
	 return numero;
}

double binomio(double n, double k){
	double resultado;
	if(k==0){
		resultado = 1;
		}else if (n == 0){
			resultado = 0;	
	} else {
		resultado = factorial(n)/(factorial(k)*factorial(n-k));
	}
	return resultado;
	}
	
unsigned long long int convierteDoubleEnInt (double_t doble) {
	unsigned long long int valorEntero = static_cast<unsigned long long int>(doble);
	return valorEntero;
}

// funciones de distribuciones de probabilidad

double bernouilli(float p, unsigned short int probabilidad){
	double resultado;
	unsigned short int x = probabilidad;
	resultado = potencia(p,x) * potencia(1-p, x-1);
	return resultado;
}

double binomial(unsigned short int n, float p, 
				unsigned short int probabilidad){
	double resultado;
	float q = (1-p);
	unsigned short int x=probabilidad;
	resultado=binomio(n,x) * potencia(p,x) * potencia(q, n-x);
	return resultado;
}

double binomialNegativa(unsigned short int n, float p, 
						unsigned short int probabilidad){
	double resultado;
	int x=probabilidad;
	resultado = binomio (n+(x-1),x) * potencia(p,n) * potencia(1-p, x);
	return resultado;
	}	

double hipergeometrica(unsigned short int N, unsigned short int n, 
						unsigned short int r, 
						unsigned short int probabilidad){
	unsigned short int x = probabilidad;
	float p = r/N;
	double resultado;
	if(n<0.1*N){
		resultado = binomial(n, p, x);
	}
	else{
		resultado = binomio(r,x) * binomio((N-r),(n-x)) / binomio(N,n);
	}
	return resultado;
	}

double poisson(float p, unsigned short int probabilidad){
	double resultado;
	float lambda = p;
	double e = 2.7182818284590;
	unsigned short int x=probabilidad;
	resultado = (pow(e,-lambda)) * (pow(lambda,x) / factorial(x));
	return resultado;
}

double geometrica(float p, unsigned short int probabilidad){
	double resultado;
	float q = 1-p;
	unsigned short int x = probabilidad;
	resultado = (potencia(p*q,x-1));
	return resultado;
	}

int main() {
	distribucionSeleccionada();
	return 0;
}
