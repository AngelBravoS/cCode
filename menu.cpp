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

int main (){
	int opcion;
	while(1) {
		std::cout << "Elige una opción:" << "\n";
		std::cout << "1) Pastilla azul" << "\n";
		std::cout << "2) Pastilla roja" << "\n";
		std::cout << "0) Para salir" << "\n";
		std::cout << "> ";
		std::cin >> opcion;	
		bool salir = false;
		switch (opcion) {
			case 0 :
				salir = true;
				std::cout << "Saliendo del programa..." << "\n";
				break;
			case 1 :
				std::cout << "Has elegido la pastilla azul." << "\n";
				break;
			case 2 :
				std::cout << "Has elegido la pastilla roja." << "\n";
				break;
			default :
				std::cout << "Tecla equivocada." << "\n";
				break;
		}
		if (salir) break;
	}
	return 0;
}
