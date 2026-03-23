/*Crear un programa que pida al usuario un número entero positivo "n". Luego implementar una función recursiva que cuente
la cantidad de dígitos pares que ocupan posiciones impares (identificándolas de izquierda a derecha) en "n".
Ej.: si el número es 22005 el resultado es 2, y si fuera 1414 el resultado es 0*/

#include <iostream>

using namespace std;

int cantidad_digitos(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
        return 1 + cantidad_digitos(n / 10);
}

int cantidad_pares(int n, int total, int i)
{
    int posicion = total - i;
    if (n < 10) // caso base
    {
        if ((posicion % 2) == 1 && ((n % 10) % 2) == 0)
            return 1;
        else
            return 0;
    }
    if ((posicion % 2) == 1 && ((n % 10) % 2) == 0) // sumo 1 si este digito es par en posicion impar + el resto de posiciones
    {
        return 1 + cantidad_pares(n / 10, total, i - 1);
    }
    else
        return 0 + cantidad_pares(n / 10, total, i - 1); // sumo el caso de todo el resto de posiciones
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
        int cantidad = cantidad_digitos(n);
        cout << "Resultado -> " << cantidad_pares(n, cantidad, cantidad) << endl;
    }

    return 0;
};