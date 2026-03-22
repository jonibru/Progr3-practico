/*Consigna*/

#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n < 0)
    {
        throw "No existe factorial de números negativos";
    }
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
};

int main()
{
    int resultado;

    resultado = factorial(4);

    cout << "Resultado = " << resultado << endl;

    return 0;
};