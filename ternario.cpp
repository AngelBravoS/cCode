#include <iostream>

int main () {
	bool boolean; 
	char pregunta;
	std::cout << "¿Es cierto?" << '\n';
	std::cout << "s/n:";
	std::cin >> pregunta;
	/*if(pregunta == 's') {
		boolean = true;
	} else {
		boolean = false;
	}	
		mismo resultado que	\
									|
									V
	*/
	pregunta == 's' ? boolean = true: boolean = false;
	std::cout << "resultado:" << boolean << std::endl;
	return 0;
}
