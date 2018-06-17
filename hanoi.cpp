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

void mover (int numDiscos, char torre1, char torre2, char torre3);

int main() {
	char torre1 = 'A';
	char torre2 = 'B';
	char torre3 = 'C';
	int numDiscos;
	std::cout << "Número de discos >> ";
	std::cin >> numDiscos;
	mover(numDiscos, torre1, torre2, torre3);
	return 0;
}

void mover (int numDiscos, char torreInicial, char torreAuxiliar, char torreFinal) {
	if ( numDiscos == 1){
		std::cout << "Mover disco desde " << torreInicial << " a " << torreFinal << '\n';
	} else {
		mover (numDiscos-1, torreInicial, torreFinal, torreAuxiliar);
		std::cout << "Mover disco desde " << torreInicial << " a " << torreFinal << '\n';
		mover (numDiscos-1, torreAuxiliar, torreInicial, torreFinal) ;
	}
}
