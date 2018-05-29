/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz  							   		*
 *   angelbravosaenz@gmail.com  														   *
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
#include <limits>
using namespace std;
			
int main() {
	cout << "Tamaño de los datos" <<endl;
	cout << "Tamaño short: " << sizeof(short) << endl;
	cout << "Tamaño unsigned short: " << sizeof(unsigned short) << endl;
	cout << "Tamaño int: " << sizeof(int) << endl;
	cout << "Tamaño unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Tamaño unsigned long int: " << sizeof(unsigned long int) << endl;
	cout << "Tamaño unsigned long long int: " << sizeof(unsigned long long int) << endl;
	cout << "Tamaño long int: " << sizeof(long int) << endl;
	cout << "Tamaño long long int: " << sizeof(long long int) << endl;
	cout << "Tamaño float: " << sizeof(float) << endl;
	cout << "Tamaño double: " << sizeof(double) << endl;
	cout << "Tamaño long double: " << sizeof(long double) << endl;
	cout << "Límite de los datos" <<endl;
	cout << "Límite mínimo en short: " << numeric_limits<short>::min() << endl;
	cout << "Límite máximo en short: " << numeric_limits<short>::max() << endl;
	cout << "Límite mínimo en unsigned short int: " << numeric_limits<unsigned short int>::min() << endl;
	cout << "Límite máximo en unsigned short int: " << numeric_limits<unsigned short int>::max() << endl;
	cout << "Límite mínimo en int: " << numeric_limits<int>::min() << endl;
	cout << "Límite máximo en int: " << numeric_limits<int>::max() << endl;
	cout << "Límite mínimo en long int: " << numeric_limits<long int>::min() << endl;
	cout << "Límite máximo en long int: " << numeric_limits<long int>::max() << endl;
	cout << "Límite mínimo en long long int: " << numeric_limits<long long int>::min() << endl;
	cout << "Límite máximo en long long int: " << numeric_limits<long long int>::max() << endl;    
	cout << "Límite mínimo en unsigned int: " << numeric_limits<unsigned int>::min() << endl;
	cout << "Límite máximo en unsigned int: " << numeric_limits<unsigned int>::max() << endl;
	cout << "Límite mínimo en unsigned long int: " << numeric_limits<unsigned long int>::min() << endl;
	cout << "Límite máximo en unsigned long int: " << numeric_limits<unsigned long int>::max() << endl;
	cout << "Límite mínimo en unsigned long long int: " << numeric_limits<unsigned long long int>::min() << endl;
	cout << "Límite máximo en unsigned long long int: " << numeric_limits<unsigned long long int>::max() << endl;    
    cout << "Límite mínimo en float: " << numeric_limits<float>::min() << endl;
	cout << "Límite máximo en float: " << numeric_limits<float>::max() << endl;
	cout << "Límite epsilon en float: " << numeric_limits<float>::epsilon() << endl;
    cout << "Límite mínimo en double: " << numeric_limits<double>::min() << endl;
	cout << "Límite máximo en double: " << numeric_limits<double>::max() << endl;
	cout << "Límite epsilon en double: " << numeric_limits<double>::epsilon() << endl;
	cout << "Límite mínimo en long double: " << numeric_limits<long double>::min() << endl;
	cout << "Límite máximo en long double: " << numeric_limits<long double>::max() << endl;
	cout << "Límite epsilon en long double: " << numeric_limits<long double>::epsilon() << endl;
    return 0;
}
