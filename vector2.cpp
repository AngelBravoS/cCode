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

class Vector {
public:
  int getLength();
  void setLength(int Publiclength);
	void createVector();
	void showVector();
private:
	int length;
	int *vector; 
};

int Vector::getLength(){
	return length;
}

void Vector::setLength(int Publiclength){
	length = Publiclength;
}

void Vector::createVector(){
	int n;
  std::cout << "Vector length: ";
  std::cin >> n;
  setLength(n);
	vector = new int[getLength()];
	for(int i=0; i < getLength(); i++) {
		std::cout << "Element " << i+1 << " of vector" << "\n";
    std::cin >> vector[i];
    }
}

void Vector::showVector(){   
  std::cout << "The vector is"<< "\n";
	std::cout << "( ";
	for(int i=0; i < getLength(); i++) {
		std::cout << vector[i] << ", ";
  }
  std::cout << ")";
  std::cout << "\n";
    }

int main() {
	Vector menu;
  menu.createVector();
  menu.showVector();
  return 0;
}
