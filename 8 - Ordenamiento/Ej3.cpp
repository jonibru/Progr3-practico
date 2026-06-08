// QUICK SORT

#include <iostream>
using namespace std;

void mostrarArreglo(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int particion(int arr[], int inicio, int fin, int &contador_condicionales)
{
    int pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++)
    {
        contador_condicionales++;

        if (arr[j] < pivote)
        {
            i++;
            int aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
    }
    int aux = arr[i + 1];
    arr[i + 1] = arr[fin];
    arr[fin] = aux;

    return i + 1;
}

void quicksort(int arr[], int inicio, int fin, int &contador_condicionales)
{
    contador_condicionales++;

    if (inicio < fin)
    {
        int posicionPivote = particion(arr, inicio, fin, contador_condicionales);

        quicksort(arr, inicio, posicionPivote - 1, contador_condicionales);
        quicksort(arr, posicionPivote + 1, fin, contador_condicionales);
    }
}

int main()
{
    const int TAM = 30;

    int datos[TAM] = {
        42, 17, 89, 3, 56, 74, 21, 9, 65, 38,
        100, 12, 47, 6, 81, 29, 53, 70, 1, 94,
        33, 25, 60, 14, 77, 5, 49, 86, 31, 68};

    int contadorCondicionales = 0;

    cout << "Arreglo original:" << endl;
    mostrarArreglo(datos, TAM);

    quicksort(datos, 0, TAM - 1, contadorCondicionales);

    cout << endl;
    cout << "Arreglo ordenado:" << endl;
    mostrarArreglo(datos, TAM);

    cout << endl;
    cout << "Cantidad de condicionales evaluados: "
         << contadorCondicionales << endl;

    return 0;
}