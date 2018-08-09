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
using std::cin;
using std::cout;
using std::endl;

/*int main (){
int x = 4;
int *px = &x;
int **ppx = &px;
cout << "Valor de x: " << x << endl;
cout << "Valor de x: " << *px << endl;
cout << "Valor de x: " << **ppx << endl;
cout << "Direccion de x: " << &x << endl;
}*/

/*void sumar(int);

int main() {
int n = 4;
sumar(n);
cout << n << endl;
return 0;
}

void sumar(int x) {
x++;
cout << x << endl;
}*/

/*void sumar(int *);
int main() {
int n = 4;
sumar(&n);
cout << n << endl;
return 0;
}

void sumar(int *x) {
*x = *x + 1;
cout << *x << endl;
}*/

/*int main() {
int n = 4;
int &ref_n = n;
cout << ref_n << endl;
}*/

void sumar(int &);
int main() {
int n = 4;
sumar(n);
cout << n << endl;
return 0;
}

void sumar(int &x) {
x = x + 1;
cout << x << endl;
}
