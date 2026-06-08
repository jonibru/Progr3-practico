// QUICK SORT + BUSQUEDA BINARIA

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

int particion(int arr[], int inicio, int fin, int &cantidad)
{
    int pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++)
    {
        cantidad++;
        if (arr[j] < pivote)
        {
            i++;
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    int aux = arr[i + 1];
    arr[i + 1] = arr[fin];
    arr[fin] = aux;

    return i + 1;
}

void quicksort(int arr[], int inicio, int fin, int &cantidad)
{
    cantidad++;
    if (inicio < fin)
    {
        int posicionPivote = particion(arr, inicio, fin, cantidad);

        quicksort(arr, inicio, posicionPivote - 1, cantidad);
        quicksort(arr, posicionPivote + 1, fin, cantidad);
    }
}

// FUNCION DE BUSQUEDA BINARIA

int busquedaBinaria(int arr[], int n, int busqueda, int &cantidad)
{
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin)
    {
        cantidad++;
        int medio = (inicio + fin) / 2;

        if (busqueda == arr[medio])
        {
            return medio;
        }
        cantidad++;
        if (busqueda < arr[medio])
        {
            fin = medio - 1;
        }
        else
        {
            inicio = medio + 1;
        }
    }
    return -1; // no se encontro
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
    cout << "Cantidad de condicionales evaluados en QuickSort: "
         << contadorCondicionales << endl;

    int buscado;
    cout << endl;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> buscado;

    int contadorBusqueda = 0;
    int posicion = busquedaBinaria(datos, TAM, buscado, contadorBusqueda);

    cout << endl;

    if (posicion != -1)
    {
        cout << "El numero " << buscado << " fue encontrado en la posicion "
             << posicion << " del arreglo ordenado." << endl;
    }
    else
    {
        cout << "El numero " << buscado << " no fue encontrado en el arreglo." << endl;
    }

    cout << "Cantidad de condicionales evaluados en la busqueda binaria: "
         << contadorBusqueda << endl;

    return 0;
}