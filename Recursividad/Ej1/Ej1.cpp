/*Implemente una funcion para potencias enteras con recursividad. Definicion recursiva para elevar un numero a una potencia:
Un numero elevado a la potencia cero produce 1. La potencia de un numero se obtiene multiplicandolo por si mismo elevando
a la potencia menos uno.*/

#include <iostream>

using namespace std;

int potencia(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
        return x * potencia(x, n - 1);
};

int main()
{
    int x, n;
    cout << "Ingrese un numero entero: ";
    cin >> x;
    cout << "Ingrese la potencia entera positiva: ";
    cin >> n;

    cout << "El resultado es: " << potencia(x, n) << endl;

    return 0;
};