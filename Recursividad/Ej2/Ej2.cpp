/*Implementar una función recursiva que determine la suma de los "n" primeros numeros naturales.
Ej: para n=5 mostrar por pantalla 1+2+3+4+5 y luego el resultado de la suma.*/

#include <iostream>

using namespace std;

int factorial_suma(int x)
{
    if (x == 1)
    {
        cout << x << " = ";
        return x;
    }
    else
        cout << x << " + ";
    return (x + factorial_suma(x - 1));
};
int main()
{
    int x;
    cout << "Ingrese un numero entero: ";
    cin >> x;

    cout << "La suma de los " << x << " primeros numeros naturales es: ";
    cout << factorial_suma(x) << endl;

    return 0;
};