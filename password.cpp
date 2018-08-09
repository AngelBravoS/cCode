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
#include <cstdlib>
#include <ctime>
#include <fstream>

static const char alfaNumerico[] =
   "0123456789|!@#$%&^()=`.;-_*"
   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void introduccion();
int longitudClave();
void crearPassword();
bool guardarEnArchivo();
bool incluirNombre();
	
void introduccion() {
	std::cout << '\n';
	std::cout << "             ╔══════════════════════════╗" << '\n';
	std::cout << "             ║          Password        ║" << '\n';
	std::cout << "             ╚══════════════════════════╝" << '\n';
	std::cout << '\n';
}

int longitudClave() {
	unsigned int longitud = 0;
	std::cout << "Longitud de la contraseña: ";
	std::cin >> longitud;
	return longitud;
}

void crearPassword(){
	unsigned int n = longitudClave();
	char *password;
	password = new char [n];
	for(unsigned int i = 0; i < n; i++) {
		password[i] = alfaNumerico[rand() % 79];
	}
	std::cout << "password " << password << '\n';
	if(guardarEnArchivo() == true) {
		std::ofstream archivo("password.dat", std::ios_base::app | std::ios_base::out);
		time_t now = time(0);
		tm *ltm = localtime(&now);
		if(incluirNombre() == true) {
			char buffer[12];
			std::cout << "Nombre de la contraseña: ";
			std::cin >> buffer;
			archivo << "password " << password << " nombrado ''" << buffer << "''" << ", de longitud " << n
			        << " y creado a las " << ltm->tm_hour << ":" << ltm->tm_min
			        << ":" << ltm->tm_sec << std::endl;
		} else {
			archivo << "password " << password << " de longitud " << n
			        << ", creado a las " << ltm->tm_hour << ":" << ltm->tm_min
			        << ":" << ltm->tm_sec << std::endl;
		}
		archivo.close();
	}
}

bool guardarEnArchivo() {
	char respuesta;
	bool grabar;
	std::cout << "La contraseña puede quedar registrada en password.dat" << '\n';
	std::cout << "junto con el tamaño, nombre y la hora de realización." << '\n';
	std::cout << "AVISO, esto puede suponer un problema de seguridad." << '\n';
	std::cout << "¿Guardar? (s)i/(n)o: ";
	std::cin >> respuesta;
	respuesta == 's' ? grabar = true : grabar = false;
	return grabar;
}

bool incluirNombre() {
	char respuesta;
	bool incluir;
	std::cout << "¿Incluir nombre? (máx 12 letras) (s)i/(n)o: ";
	std::cin >> respuesta;
	respuesta == 's' ? incluir = true : incluir = false;
	return incluir;
}

int main() {
	srand((unsigned int)time(NULL));
	introduccion();
	crearPassword();
	return 0;
}
