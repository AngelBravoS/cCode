#include <iostream>
using namespace std;

double factorial ( unsigned int n ) {
    if ( n == 0 ) {
        return 1;                      // Aseguramos que tenga salida siempre
    }
    else {
        return n * factorial ( n - 1 );
    }                          // Caso general
}

double potencia ( unsigned int numero, unsigned int potencia ) {
    int temporal = numero;
    for ( unsigned int x=1; x<potencia; x++ ) {
        numero=numero*temporal;
    }
    return numero;
}

unsigned long long int conversionResultadoInt (double doble) {
    unsigned long long int valorEntero = (unsigned long long int) doble;
    return valorEntero;
}

int main() {
    unsigned int m, n, cantidadn;
    double resultado;
    char opcion, opcion2;
    cout << "Programa de combinatoria" << endl;
    cout << "¿(p)ermutaciones, (v)ariaciones o (c)ombinaciones?." << endl;
    cout << "=> ";
    cin >> opcion;
    cout << "¿Repetición? (s)í/(n)o" << endl;
    cout << "=> ";
    cin >> opcion2;
    switch ( opcion ) {
    case 'p':
        switch ( opcion2 ) {
        case 's':
            cout << "Permutaciones con repetición " << endl;
            cout << "============================ " << endl;
            cout << "" << endl;
            cout << "Valor de m => ";
            cin >> m;
            cout << "Cantidad de n diferentes => ";
            cin >> cantidadn;
            resultado = 1;
            for ( unsigned short int i = 0; i < cantidadn; i++ ) {
                cout << "Introducir valor de n" << ( i + 1 ) << " " << "=> ";
                cin >> n;
                resultado *= factorial ( n );
            }
            resultado = ( factorial ( m ) / resultado );
            cout << "" << endl;
            cout << "              m! " << endl;
            cout << "PRm,n = -------------- = " << conversionResultadoInt (resultado) << endl;
            cout << "         n1!*n2!..nK! " << endl;
            cout << "" << endl;
            break;

        case 'n':
            cout << "Permutaciones sin repetición " << endl;
            cout << "============================ " << endl;
            cout << "" << endl;
            cout << "Valor de n => ";
            cin >> n;
            resultado = ( factorial ( n ) );
            cout << "" << endl;
            cout << "Pn = n! = " << conversionResultadoInt (resultado) << endl;
            break;
        }

        break;
    case 'v':
        switch ( opcion2 ) {
        case 's':
            cout << "Variaciones con repetición " << endl;
            cout << "============================ " << endl;
            cout << "" << endl;
            cout << "Valor de m => ";
            cin >> m;
            cout << "Valor de n => ";
            cin >> n;
            resultado = potencia ( m, n );
            cout << "" << std::endl;
            cout << "         n" << endl;
            cout << "VRm,n = m = " << conversionResultadoInt (resultado) << endl;;
            break;

        case 'n':
            cout << "Variaciones sin repetición " << endl;
            cout << "============================ " << endl;
            cout << "" << endl;
            cout << "valor de m => ";
            cin >> m;
            cout << "valor de n => ";
            cin >> n;
            resultado = ( factorial ( m ) / factorial ( m - n ) );
            cout << "" << endl;
            cout << "           m! " << endl;
            cout << "Vm,n = ---------- = " << conversionResultadoInt (resultado) << endl;
            cout << "         (m-n)! " << endl;
            cout << "" << endl;
            break;
        }

        break;
    case 'c':
        switch ( opcion2 ) {
        case 's':
            cout << "Combinaciones con repetición " << endl;
            cout << "============================ " << endl;
            cout << "" << endl;
            cout << "Valor de m => ";
            cin >> m;
            cout << "Valor de n => ";
            cin >> n;
            m = m + ( n - 1 );
            resultado = ( factorial ( m ) ) / ( factorial ( n ) * factorial ( m - n ) );
            cout << "" << endl;
            cout << "         (m + n-1) " << endl;
            cout << "CRm,n =  (   n   ) = " << conversionResultadoInt (resultado) << endl;
            cout << "" << endl;
            break;

        case 'n':
            cout << "Combinaciones sin repetición " << endl;
            cout << "============================ " << endl;
            cout << "" << endl;
            cout << "Valor de m => ";
            cin >> m;
            cout << "Valor de n => ";
            cin >> n;
            resultado = ( factorial ( m ) ) / (factorial ( n ) * factorial ( m - n ));
            cout << "" << std::endl;
            cout << "        (m)        m! " << endl;
            cout << "Cm,n =  ( ) = ---------- = " <<  conversionResultadoInt (resultado) << endl;
            cout << "        (n)     n!(m-n)! " << endl;
            cout << "" << endl;
            break;
        }
        break;
    }
    return 0;
}
