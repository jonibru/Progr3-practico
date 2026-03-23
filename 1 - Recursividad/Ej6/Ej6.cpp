/*Crear un programa que pida al usuario un número entero positivo "n". Luego implementar una función recursiva que cuente
la cantidad de dígitos pares que ocupan posiciones impares (identificándolas de izquierda a derecha) en "n".
Ej.: si el número es 22005 el resultado es 2, y si fuera 1414 el resultado es 0*/

#include <iostream>

using namespace std;

int cantidad_digitos(int n, int i)
{
    if (n == 0)
    {
        return 0;
    }
    return cantidad_digitos(n / 10, i + 1);
}

int main()
{
    int n;
    cout << "Ingrese entero positivo N: ";
    cin >> n;
    if (n < 1)
        throw "Error. Ingrese entero positivo";
    else
    {
    }

    return 0;
};