#include <iostream>
#include <math.h> 
using namespace std;

double potencia ( double numero, double potencia ) {
    for (int i = 0; i < potencia; i++){
      numero *= potencia; 
	}
    return numero;
}

double interesNominal(double meses, double tae){
double exponente=1/meses;
double base=tae+1;
double resultado;
resultado=meses*(pow(base, exponente)-1);
return resultado;
}

int main(){
double sumaIntereses, tae;
unsigned short meses;
double capitalInicial, capitalFinal;
cout << "Cálculo del T.A.E." << endl;
cout << "versión 0.02" << endl;
cout << "Capital inicial > ";
cin >> capitalInicial;
cout << "T.A.E. > ";
cin >> tae;
cout << "nº de meses > ";
cin >> meses;
cout << "La tasa nominal es > " << interesNominal(meses, tae) << endl;
cout << "Cobro (cada mes)> " << 100*(interesNominal(meses, tae)/meses)<< endl;
cout << "Total > " << capitalInicial*(1+tae)<< endl;
cout << "Por meses: " << endl;
capitalFinal = capitalInicial;
sumaIntereses = 0;
for (int i = 0; i != meses; i++){
	capitalFinal=capitalFinal+(capitalFinal*(interesNominal(meses, tae)/meses));
	sumaIntereses=sumaIntereses+(100*(interesNominal(meses, tae)/meses));//nop
	cout << capitalFinal <<endl;// << " " << sumaIntereses <<endl;
}

return 0;
}
