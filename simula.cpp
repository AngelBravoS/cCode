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
using namespace std;

//---función para el generador congruencial mixto---
int congruencialMixto (int a,int b,int m, int x){
	int resultado ;
	resultado=a*x+b;
	if (resultado > m)
		resultado = resultado % m;
	return resultado;
}

//---función para el generador congruencial multiplicativo---
int congruencialMultip (int a,int m, int Xo){
	int resultado;
	resultado=a*Xo;
	if (resultado > m)
		resultado = resultado % m;
	return resultado;
}
int main() {
	int a,b,m,Xo,Xn,i;
	char opcion;
	cout << "Métodos congruenciales" << endl;
	cout << "Escribe x para el generador congruencial mixto." << endl;
	cout << "Escribe m para el generador congruencial multiplicativo." << endl;
	cout << "pulsa cualquier otra para salir." << endl;
	cout << "> ";
	cin >> opcion;
	switch (opcion) {
		case 'x':
			cout << "valor de a: ";
			cin >> a;
			cout << "valor de b: ";
			cin >> b;
			cout << "valor de Xo: ";
			cin >> Xo;
			cout << "valor de m: ";
			cin >> m;
			if (m <= a || m <= b)
				cout << "secuencia no válida (m > a,b).";
			else
				cout << "Para a = " << a << ", b = " << b << ", m = "
				<< m << ", y Xo = " << Xo << ", el resultado es:" << endl;
				cout << "(" << congruencialMixto(a,b,m,Xo);
				//crea el primer valor X1 para usarlo como referencia
				//mientras no coincida con el siguiente sigue calculando
				Xn = congruencialMixto(a,b,m,Xo); 
				i=1;
				while (Xo != Xn) { 			
					cout << " " << congruencialMixto(a,b,m,Xn);
					Xn = congruencialMixto(a,b,m,Xn);
					i++;
				}
				cout << ")" << endl;
				cout << "El período de la secuencia es "<< i << endl;
				if (i==m){ cout << "Es de período completo" << endl;}
		break;
		case 'm':
			cout << "valor de a: ";
			cin >> a;
			cout << "valor de Xo: ";
			cin >> Xo;
			cout << "valor de m: ";
			cin >> m;
			cout << "Para a = " << a << ", m = " << m << ", y Xo = " 
			<< Xo << ", el resultado es:" << endl;
			cout << "(" << congruencialMultip(a,m,Xo);
			//crea el primer valor X1 para usarlo como referencia
			//mientras no coincida con el siguiente sigue calculando
			Xn = congruencialMultip(a,m,Xo); 
			i=1;
			while (Xo != Xn) { 			
				cout << " " << congruencialMultip(a,m,Xn);
				Xn = congruencialMultip(a,m,Xn);
				i++;
			}
			cout << ")" << endl;
			cout << "El período de la secuencia es "<< i << endl;
		break;
    }
return 0;
}
