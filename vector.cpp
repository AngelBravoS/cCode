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
 
