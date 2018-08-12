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

double factorial(unsigned int n);
double potencia(double numero, unsigned int potencia);
double binomio(unsigned int n, unsigned int k);
double e (unsigned int numIteraciones);
char menu();
void calculo();
unsigned int convierteDoubleEnInt (double doble);

double factorial(unsigned int n) {
	if(n == 0) {
		// Aseguramos que tenga salida siempre
		return 1;
	} else {
		// Caso general
		return  n * factorial(n - 1);
	}
}

double potencia(double numero, unsigned int  potencia) {
	double temporal = numero;
	if(potencia == 0) {
		numero = 1;
	} else {
		for(unsigned int x = 1; x < potencia; x++) {
			numero *= temporal;
		}
	}
	return numero;
}

double binomio(unsigned int n, unsigned int k) {
	double resultado;
	if(k==0) {
		resultado = 1;
	} else if(n == 0) {
		resultado = 0;
	} else {
		resultado = factorial(n)/(factorial(k)*factorial(n-k));
	}
	return resultado;
}

unsigned int convierteDoubleEnInt(double doble) {
	unsigned int valorEntero = static_cast<unsigned int>(doble);
	return valorEntero;
}

double e (unsigned int n){
	double resultado, producto;
	resultado = 1;
	producto = 1;
	for (unsigned int i = 1; i <= n; i++) {
		producto *= i;
		resultado += 1/producto;
	}
	return resultado;
}

char menu(){
	char opcion;
	std::cout << "Cálculos matemáticos básicos" << "\n";
	std::cout << "1) Factorial" << "\n";
	std::cout << "2) Potencia" << "\n";
	std::cout << "3) Binomio de Newton" << "\n";
	std::cout << "4) Iteraciones para el número e" << "\n";
	std::cout << "0) Para salir" << "\n";
	std::cout << "> ";
	std::cin >> opcion;
	return opcion;
}

void calculo (){
	unsigned int n, k;
	while(1) {
		bool salir = false;
		switch (menu()) {
			case '0' :
				salir = true;
				std::cout << "saliendo del programa..." << "\n";
				break;
			case '1' :
				std::cout << "Factorial" << "\n";
				std::cout << "n = ";
				std::cin >> n;
				std::cout << n << "! = " << factorial(n) << "\n";
				break;
			case '2' :
				std::cout << "Potencia" << "\n";
				std::cout << "número = ";
				std::cin >> n;
				std::cout << "exponente = ";
				std::cin >> k;
				std::cout << n << "^" << k << " = " 
				<< potencia(n, k) 
				<< "\n";
				break;
			case '3' :
				std::cout << "Binomio de Newton" << "\n";
				std::cout << "n = ";
				std::cin >> n;
				std::cout << "k = ";
				std::cin >> k;
				std::cout << "(" << n << ")" << "\n";
				std::cout << "(" << k << ") = " << binomio(n, k) << "\n";
				break;
			case '4' :
				std::cout << "Número e" << "\n";
				std::cout << "Numero de iteracones para la aproximación = ";
				std::cin >> n;
				std::cout.precision(50);
				std::cout << n << " iteraciones => e = " << e(n) << "\n";
				break;				
			default :
				std::cout << "Opción no válida" << "\n";
				break;
			}
			std::cout << "\n";
			if (salir) break;
	}
}

int main(){
	calculo();
	return 0;
}
