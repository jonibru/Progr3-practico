/*Crear un programa que emplee recursividad para calcular el mayor de los
elementos de un vector de “n” tamaño dado por pantalla por el usuario.*/

#include <iostream>

using namespace std;

int maximo_arreglo(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        int max_resto = maximo_arreglo(arr + 1, n - 1);
        if (arr[0] > max_resto)
            return arr[0];
        else
            return max_resto;
    }
}

int main()
{
    int n = 5;
    cout << "Ingrese los 5 elementos del arreglo:" << endl;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "El maximo es: " << maximo_arreglo(arr, n) << endl;

    return 0;
};