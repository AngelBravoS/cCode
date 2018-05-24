#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*int main (){
int x = 4;
int *px = &x;
int **ppx = &px;
cout << "Valor de x: " << x << endl;
cout << "Valor de x: " << *px << endl;
cout << "Valor de x: " << **ppx << endl;
cout << "Direccion de x: " << &x << endl;
}*/

/*void sumar(int);

int main() {
int n = 4;
sumar(n);
cout << n << endl;
return 0;
}

void sumar(int x) {
x++;
cout << x << endl;
}*/

/*void sumar(int *);
int main() {
int n = 4;
sumar(&n);
cout << n << endl;
return 0;
}

void sumar(int *x) {
*x = *x + 1;
cout << *x << endl;
}*/

/*int main() {
int n = 4;
int &ref_n = n;
cout << ref_n << endl;
}*/

void sumar(int &);
int main() {
int n = 4;
sumar(n);
cout << n << endl;
return 0;
}

void sumar(int &x) {
x = x + 1;
cout << x << endl;
}
