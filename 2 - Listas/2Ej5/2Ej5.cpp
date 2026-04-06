/*Crear un programa que pida al usuario dar elementos a una Lista de números enteros. Luego
cree una función que reciba una lista int L1 y devuelva otra lista int L2 conteniendo los
elementos repetidos de L1. Por ejemplo, si L1 almacena los valores 5->2->7-> 2->5->5->1, debe
construirse una lista L2 con los valores 5->2. Si en L1 no hay elementos repetidos se debe
indicar al usuario que no hay elementos repetidos en L1, de lo contrario imprimir ambas listas.*/

#include <iostream>
#include "../Lista.h"
#include "../nodo.h"

using namespace std;

Lista<int> devolver_repetidos(Lista<int> &lista1)
{
    int n = lista1.getTamanio();
    Lista<int> lista2;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n && i != k; k++)
        {
            if (lista1.getDato(i) == lista1.getDato(k))
            {
                lista2.insertarUltimo(lista1.getDato(k));
                k = n;
            }
        }
    }
    return lista2;
}

int main()
{
    Lista<int> lista1;
    int x;
    cout << "Ingresar elementos de lista 1 -> ";
    for (int i = 0; x != -1; i++)
    {
        cin >> x;
        lista1.insertarUltimo(x);
    }

    Lista<int> lista2 = devolver_repetidos(lista1);
    if (lista2.esVacia())
    {
        cout << "No hay valores repetidos";
    }
    else
    {
        cout << "Lista 1: " << endl;
        lista1.print();
        cout << "\nRepetidos: " << endl;
        lista2.print();
    }

    return 0;
};