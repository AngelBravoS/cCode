#include <iostream>

double SumarNumeros(double num1, double num2) {
    double resultado = num1 + num2;
    return resultado;
}

double DividirNumeros(double num1, double num2) {
    double resultado = num1 / num2;
    return resultado;
}

void MostrarResultados(double resultadoSuma, double resultadoDivision) {
    std::cout << "Suma de los números: " << resultadoSuma << "\n";
    std::cout << "División de los números: " << resultadoDivision << "\n";
}

void CalcularOperaciones(double num1, double num2) {
    double resultadoSuma = SumarNumeros(num1, num2);
    double resultadoDivision = DividirNumeros(num1, num2);
    MostrarResultados(resultadoSuma, resultadoDivision);
}

int main() {
    double numero1 = std::rand() / static_cast<double>(RAND_MAX);
    double numero2 = std::rand() / static_cast<double>(RAND_MAX);

    std::cout << "Número 1: " << numero1 << "\n";
    std::cout << "Número 2: " << numero2 << "\n";

    CalcularOperaciones(numero1, numero2);
    return 0;
}
