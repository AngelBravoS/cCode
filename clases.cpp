#include <iostream>

class Figura {
	private:
		int longitud;
		int anchura;	
	protected:
		int lado;
	public:
		void presentar(){
			std::cout << "Introduce los datos de la figura: " << "\n";
		}
		void recogerDatos(){
			std::cout << "Longitud: ";
			std::cin >> longitud;
			std::cout << "Anchura: ";
			std::cin >> anchura;
			if (longitud == anchura){
				lado = longitud;
				}
		}
		void mostrarDatos(){
			std::cout << "La figura tiene " << longitud << " de longitud y " << anchura << " de anchura." << "\n";
		}	
};

class Cuadrado : public Figura {
	public:
		// sobreescribe la función heredada
		void mostrarDatos(){
			std::cout << "Es un cuadrado que tiene " << lado << " de lado" << "\n";
		}	
};	

int main() {
	Figura miFigura;
	miFigura.presentar();
	miFigura.recogerDatos();
	miFigura.mostrarDatos();
	
	Cuadrado miCuadrado;
	miCuadrado.presentar();
	miCuadrado.recogerDatos();
	miCuadrado.mostrarDatos();
	return 0;
}
