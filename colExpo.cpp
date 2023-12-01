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

//clases
class Modelo {
	protected:
		double lambda;
		double mu;
		double ro;
		unsigned int n;
	public:
		//======== Constructores ========
		Modelo ();
		Modelo (double lambdaUsuario, double muUsuario, unsigned int nUsuario);
		//======== Cálculos básicos ========
		double factorial(unsigned int k) {
			if(k == 0) {
				// Aseguramos que tenga salida siempre
				return 1;
			} else {
				// Caso general
				return  k * factorial(k - 1);
			}
		}
		double potencia(double numero, unsigned int exponente) {
			double temporal = numero;
			if(exponente == 0) {
				numero = 1;
			} else {
				for(unsigned int x = 1; x < exponente; x++) {
					numero *= temporal;
				}
			}
			return numero;
		}
		double e (){
			double resultado, producto;
			resultado = 1;
			producto = 1;
			for (unsigned int i = 1; i <= 17; i++) {
				producto *= i;
				resultado += 1/producto;
			}
			return resultado;
		}
		//======== Funciones base de todos los modelos ========
		double p0() {
			double resultado;
			resultado = 1 - ro;
			return resultado;
			}
		double pn() {
			double resultado;
			resultado = potencia(ro, n)*p0();
			return resultado;
			};
		double lq() {
			double resultado;
			resultado = potencia(ro, 2)/(1 - ro);
			return resultado;
		}
		double wq() {
			double resultado;
			resultado = lq() / lambda;
			return resultado;
		}
		double w() {
			double resultado;
			resultado = wq() + (1/mu);
			return resultado;
		}
		double l() {
			double resultado;
			resultado = lambda * w();
			return resultado;
		}
	};

class MMI : public Modelo {
	public:
		//======== Constructores ========
		MMI ();
		MMI (double lambda, double mu, unsigned int n);
		//======== Funciones específicas ========
		double lq2 () {
			double resultado;
			resultado = 1/(1 - ro);
			return resultado;
		}
};

class MMIK : public Modelo {
	protected:
		unsigned int k;
		double r, lambdaA;
		bool rIgual1;
	public:
		//======== Constructores ========
		MMIK ();
		MMIK (double lambda, double mu, unsigned int n, unsigned int c );
		//======== Funciones específicas ========
		double p0 () {
			double resultado;
			if (rIgual1 == true) {
				resultado = 1/(k+1);
			}else{
				resultado = (1-r)/(1- potencia(r, k+1));
			}
			return resultado;
		}
		double pn () {
			double resultado;
			if (rIgual1 == true) {// Distribución uniforme
				resultado = 1/(k+1);
			}else{//Distribución geométrica truncada
				resultado = potencia(r, k) * p0();
			}
			return resultado;
		}
		double lq () {
			double resultado;
			if (rIgual1 == true) {// Distribución uniforme
				resultado = (k/2)-ro();
			}else{//Distribución geométrica truncada
				double numerador;
				double denominador;
				numerador = r*(k*potencia(r, k+1)-(k+1)*potencia(r,k)+1);
				denominador = (1-potencia(r, k+1))*(1-r);
				resultado = (numerador/denominador)-ro();
			}
			return resultado;
		}
		double wq () {
			double resultado;
			resultado = lq() / lambdaA;
			return resultado;
		}
		double w() {
			double resultado;
			resultado = wq () + (1/mu);
			return resultado;
		}
		double l () {
			double resultado;
			resultado = lambdaA * w();
			return resultado;
		}
		double ro () {
			double resultado;
			resultado = r * ( 1 - pn() );
			return resultado;
		}
};

class MMC : public Modelo {
	protected:
    double r;
    unsigned int c;
    bool nMayorC;
	public:
    //======== Constructores ========
    MMC ();
    MMC ( double lambda, double mu, unsigned int n, unsigned int c );
    //======== Funciones específicas ========
    double p0 () {
      double resultado, primerSumando, segundoSumando;
		  unsigned int i = 0;
		  unsigned int fin = c-1;
      primerSumando = 0;
      segundoSumando = 0;
      while (i <= fin) {
				primerSumando += potencia (ro,i)/factorial(i);
				++i;
			}
      segundoSumando = (c*potencia(ro,c))/( factorial(c)*(c-ro));
      resultado = 1/(primerSumando+segundoSumando);
      return resultado;
    }
    double pn () {
			double resultado;
    	if (nMayorC == false) {
				resultado = 1/factorial(n)*potencia(r,n)*p0();
    	} else {
				resultado = 1/(potencia(c,n-c)*factorial(c))*potencia(r,n)*p0();
    	}
		return resultado;
    }
    double lq () {
        double resultado;
			resultado = p0()*(ro*potencia(r,c))/(factorial(c)*potencia((1-ro),2));
        return resultado;
    }
    double wq () {
        double resultado;
        resultado = lq() / lambda;
        return resultado;
    }
    double w() {
        double resultado;
        resultado = wq () + ( 1/mu );
        return resultado;
    }
    double l () {
        double resultado;
        resultado = lambda * w();
        return resultado;
    }
};

class MMINFINIT : public Modelo {
    protected:
    double r;
    public:
    //======== Constructores ========
    MMINFINIT ();
    MMINFINIT ( double lambda, double mu, unsigned int n );
    //======== Funciones específicas ========
    double p0 () {
        double resultado;
        resultado = 1/potencia ( e(), r );
		  return resultado;
    }
    double pn () {
        double resultado;
			resultado = 1/factorial(n)*potencia(r,n)*p0();
        return resultado;
    }
    double lq () {
        double resultado = 0;
        return resultado;
    }
    double wq () {
        double resultado = 0;
        return resultado;
    }
    double w () {
        double resultado = 1/mu;
        return resultado;
    }
    double l () {
        double resultado = r;
        return resultado;
    }
};


//Constructores
Modelo::Modelo (){}

Modelo::Modelo (double lambdaUsuario, double muUsuario, unsigned int nUsuario) {
	lambda = lambdaUsuario;
	mu = muUsuario;
	n = nUsuario;
	ro = lambda/mu;
	}

MMI::MMI () {}

MMI::MMI (double lambdaUsuario, double muUsuario, unsigned int nUsuario) {
	lambda = lambdaUsuario;
	mu = muUsuario;
	n = nUsuario;
	ro = lambda/mu;
	}

MMIK::MMIK () {}

MMIK::MMIK (double lambdaUsuario, double muUsuario, unsigned int nUsuario, unsigned int cUsuario) {
	lambda = lambdaUsuario;
	mu = muUsuario;
	n = nUsuario;
	k = cUsuario;
	r = lambda/mu;
	lambdaA = lambda*(1-pn());
	r == 1 ? rIgual1 = true: rIgual1 = false;
	}

MMC::MMC () {}

MMC::MMC ( double lambdaUsuario, double muUsuario, unsigned int nUsuario, unsigned int cUsuario ) {
    lambda = lambdaUsuario;
    mu = muUsuario;
    n = nUsuario;
    c = cUsuario;
    r = lambda/mu;
    ro = r/c;
    if ( ( 1 <= n ) && ( n < c ) ) {
        nMayorC = false;
    } else {
        nMayorC = true;
    }
}

MMINFINIT::MMINFINIT () {}

MMINFINIT::MMINFINIT ( double lambdaUsuario, double muUsuario, unsigned int nUsuario ) {
    lambda = lambdaUsuario;
    mu = muUsuario;
    n = nUsuario;
	 r = lambda/mu;
}



//prototipos funcion main
void menu();
void recogerDatos();
void resultados(double lambdaUsuario, double muUsuario, unsigned int nUsuario, unsigned int cUsuario, unsigned int modeloSeleccionado);

void menu () {
	std::cout << "Modelos de colas exponenciales: " << "\n";
	std::cout << "1) M/M/1" << "\n";
	std::cout << "2) M/M/1/K" << "\n";
	std::cout << "3) M/M/C" << "\n";
	std::cout << "4) M/M/Inf" << "\n";
	std::cout << "> ";
	}

void recogeDatos () {
	unsigned int modeloSeleccionado;
	unsigned int nUsuario, cUsuario = 0;
	double lambdaUsuario, muUsuario;
	std::cin >> modeloSeleccionado;
	std::cout << "Valor Lambda = ";
	std::cin >> lambdaUsuario;
	std::cout << "Valor Mu = ";
	std::cin >> muUsuario;
	switch (modeloSeleccionado) {
		case 2 :
			std::cout << "Valor k para calcular Pk -0 para ninguno- = ";
			std::cin >> nUsuario;
			std::cout << "Valor K = ";
			std::cin >> cUsuario;
			break;
		case 3 :
			std::cout << "Valor n para calcular Pn -0 para ninguno- = ";
			std::cin >> nUsuario;
			std::cout << "Valor c = ";
			std::cin >> cUsuario;
			break;
		default :
			std::cout << "Valor n para calcular Pn -0 para ninguno- = ";
			std::cin >> nUsuario;
			break;
		}
	std::cout << "\n";
	resultados(lambdaUsuario, muUsuario, nUsuario, cUsuario, modeloSeleccionado);
	}

void resultados(double lambdaUsuario, double muUsuario, unsigned int nUsuario, unsigned int cUsuario, unsigned int modeloSeleccionado) {
	std::cout << " ======== Resultados ========" << '\n';
	switch (modeloSeleccionado) {
		case 1 : {
				MMI colaMMI(lambdaUsuario, muUsuario, nUsuario);
				std::cout << "Lq (Número medio de clientes en cola) = " << colaMMI.lq() << "\n";
				std::cout << "L'q (Número medio de clientes en cola cuando no está vacía) = " << colaMMI.lq2() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMMI.l() << "\n";
				std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMI.wq() << "\n";
				//std::cout << "W'q = Tiempo medio de espera en cola cuando no está vacía" << cola.wq2() << "\n";
				std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMI.w() << "\n";
				std::cout << "P0 (Tiempo del sistema ocioso) = " << colaMMI.p0() << "\n";
				if (nUsuario != 0) {
					std::cout << "Valor P" << nUsuario << " = " << colaMMI.pn() << "\n";
					}
				break;
				}

		case 2 : {
				MMIK colaMMIK(lambdaUsuario, muUsuario, nUsuario, cUsuario);
				std::cout << "Valor P0" << " = " << colaMMIK.p0() << "\n";
				std::cout << "Valor P" << nUsuario << " = " << colaMMIK.pn() << "\n";
				std::cout << "Lq (Número medio de clientes en cola) = " << colaMMIK.lq() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMMIK.l() << "\n";
				std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMIK.wq() << "\n";
				std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMIK.w() << "\n";
				break;
				}
		case 3 : {
				MMC colaMMC(lambdaUsuario, muUsuario, nUsuario, cUsuario);
				std::cout << "Valor P0" << " = " << colaMMC.p0() << "\n";
				std::cout << "Valor P" << nUsuario << " = " << colaMMC.pn() << "\n";
				std::cout << "Lq (Número medio de clientes en cola) = " << colaMMC.lq() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMMC.l() << "\n";
				std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMC.wq() << "\n";
				std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMC.w() << "\n";
				break;
				}
		case 4 : {
				MMINFINIT colaMMINFINIT(lambdaUsuario, muUsuario, nUsuario);
				std::cout << "Valor P0" << " = " << colaMMINFINIT.p0() << "\n";
				std::cout << "Valor Pn" << " = " << colaMMINFINIT.pn() << "\n";
				std::cout << "Lq (Número medio de clientes en cola) = " << colaMMINFINIT.lq() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMMINFINIT.l() << "\n";
				std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMINFINIT.wq() << "\n";
				std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMINFINIT.w() << "\n";
				break;
				}
	}
}

int main (){
	menu();
	recogeDatos();
	return 0;
}
