/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program. If not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>
#include <math.h>

//Prototipos:
//funciones de seleccion y visualizacion
void distribucionSeleccionada();
char menuIntro();
void resultados(char distribucion);

// funciones matematicas
double factorial(double n);
double potencia(double numero, unsigned int potencia);
double binomio(double a, double b);
double e();
unsigned int convierteDoubleEnInt (double_t doble);

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
double multinomial(unsigned int n, unsigned int k);
double valor(unsigned int i, bool esValorXi);

//funciones de seleccion y visualizacion		

void resultados(char distribucion){
	unsigned short int n, N, r, k, probabilidad;
	float p; 
	std::cout << "======================================= " << "\n";
	switch (distribucion) {
	case '1': //Bernouilli
		std::cout << "Valor de x: ";
		std::cin >> probabilidad;
		std::cout << "Valor de p: ";
		std::cin >> p;
		std::cout << "Distribución Bernuilli X~>B("<< p << ")" << "\n";
		std::cout << "P[X=" << probabilidad << "]" << " = "<< 
			bernouilli(p, probabilidad) << "\n";
		break;
	case '2': //Binomial
		std::cout << "Valor de x: ";
		std::cin >> probabilidad;
		std::cout << "Valor de p: ";
		std::cin >> p;
		std::cout << "Valor de n: ";
		std::cin >> n;
		std::cout << "Distribución Binomial X~>B("<< n << ","<< 
			p << ")" << "\n";
		std::cout << "P[X=" << probabilidad << "]" << " = "<< 
			binomial(n, p, probabilidad) << "\n"; 
		break;
	case '3': //Binomial negativa
		std::cout << "Valor de x: ";
		std::cin >> probabilidad;
		std::cout << "Valor de p: ";
		std::cin >> p;
		std::cout << "Valor de n: ";
		std::cin >> n;
		std::cout << "Distribución Binomial negativa X~>BN("<< n << 
			"," << p << ")" << "\n";
		std::cout << "P[X=" << probabilidad << "]" << " = "<< 
			binomialNegativa(n, p, probabilidad) << "\n"; 
		break;	
	case '4': //Hipergeometrica
		std::cout << "Valor de x: ";
		std::cin >> probabilidad;
		std::cout << "Parámetro N: ";
		std::cin >> N;
		std::cout << "Parámetro n: ";
		std::cin >> n;
		std::cout << "Parámetro r: ";
		std::cin >> r;
		std::cout << "Distribución Hipergeométrica X~>H("<< N << 
			","<< n << "," << r << ")" << "\n";
		std::cout << "P[X=" << probabilidad << "]" << " = "<< 
			hipergeometrica(N, n, r, probabilidad) << "\n"; 
		break;	
	case '5': //Poisson
		std::cout << "Valor de x: ";
		std::cin >> probabilidad;
		std::	cout << "Valor de lambda: ";
		std::cin >> p;
		std::cout << "Distribución Poisson X~>P("<< p << ")" << "\n";
		std::cout << "P[X=" << probabilidad << "]" << " = "<< 
		poisson(p, probabilidad) << "\n"; 
		break;
	case '6': //Geometrica
		std::cout << "Valor de x: ";
		std::cin >> probabilidad;
		std::cout << "Valor de p: ";
		std::cin >> p;
		std::cout << "Distribución Geométrica X~>G(" << p << ")" << "\n";
		std::cout << "P[X=" << probabilidad << "]" << " = "<< geometrica(p, probabilidad) << "\n"; 
		break;
	case '7': //Multinomial
		std::cout << "Tamaño de la muestra: ";
		std::cin >> n;
		std::cout << "Número de probabilidades asociadas: ";
		std::cin >> k;
		std::cout << "Distribución Multinomial" << "\n";
		std::cout << multinomial(n, k) << "\n"; 
		//cout << "P[X=" << probabilidad << "]" << " = "<< multinomial(n, k) << endl; 
		break;
	break;
	}
	std::cout << "======================================= " << "\n";
	std::cout << "\n";
}

char menuIntro(){
	char distribucion;
	 std::cout << "Distribuciones de probabilidad discretas" << "\n";
	 std::cout << "Distribuciones a elegir:" << "\n";
	 std::cout << "1.- Bernouilli." << "\n";
	 std::cout << "2.- Binomial." << "\n";
	 std::cout << "3.- Binomial negativa." << "\n";
	 std::cout << "4.- Hipergeométrica." << "\n";
	 std::cout << "5.- Poisson." << "\n";
	 std::cout << "6.- Geométrica." << "\n";
	 std::cout << "7.- Multinomial." << "\n";
	 std::cout << "> ";
	 std::cin >> distribucion;
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

double potencia(double numero, unsigned int potencia) {
	double temporal = numero;
	if (potencia==0){
		numero = 1;
		}
	else{
		for (unsigned int x=1; x<potencia; x++) {
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

double e (){
	double resultado, producto;
	resultado = 1;
	producto = 1;
	for (unsigned int i = 1; i <= 17; i++) {
		producto *= i;
		resultado += 1/producto;
	}
	return resultado;
}
	
unsigned int convierteDoubleEnInt (double_t doble) {
	unsigned int valorEntero = static_cast<unsigned int>(doble);
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
	unsigned short int x=probabilidad;
	resultado = (pow(e(),-lambda)) * (pow(lambda,x) / factorial(x));
	return resultado;
}

double geometrica(float p, unsigned short int probabilidad){
	double resultado;
	float q = 1-p;
	unsigned short int x = probabilidad;
	resultado = (potencia(p*q,x-1));
	return resultado;
	}

double valor(unsigned int i, bool esValorXi){
	double valor;
	esValorXi == true ? std::cout << "introduce X" << i << " = " : std::cout << "introduce P" << i << " = ";
	std::cin >> valor;
	return valor;
	}

double multinomial (unsigned int n, unsigned int k){
	double resultado, xi, pi;
	resultado = 1;
	for (unsigned int i = 1; i <= k; i++) {
		xi = valor(i, true);
		pi = valor(i, false);
		resultado *= 1/factorial(xi) * potencia(pi, convierteDoubleEnInt(xi));
	}
	resultado = factorial(n) * resultado;
	return resultado;
	}
	
int main() {
	distribucionSeleccionada();
	return 0;
}
