/*Crear una función que reciba una pila por referencia y un número. La función debe sacar la
primera ocurrencia de dicho valor de la pila sino se repite el valor en la pila, de lo contrario
debe eliminar todos los valores repetidos a excepción de la primera ocurrencia. Si el valor no
se encuentra en la pila muestra un mensaje indicando que no pertenece a la pila. Imprimir la
pila al final para verificar si hubo o no modificaciones.*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void reemplazar(Pila<int> &pila, int num)
{
    Pila<int> aux;
    int contador = 0;
    int x;
    while (!pila.esVacia())
    {
        x = pila.pop();
        if (x == num)
        {
            contador++;
        }
        aux.push(x);
    }
    if (contador == 0)
    {
        cout << "\n¡El valor no se encuentra en la pila!" << endl;
        pila.push(pila.pop());
    }
    else if (contador == 1)
    {
        while (!aux.esVacia())
        {
            x = aux.pop();
            if (!(x == num))
            {
                pila.push(x);
            }
        }
    }
    else if (contador > 1)
    {
        while (!aux.esVacia())
        {
            x = aux.pop();
            if (x == num && contador > 1)
            {
                contador--;
            }
            else
            {
                pila.push(x);
            }
        }
    }
}

int main()
{

    cout << "Ejercicio N° 3" << endl;

    Pila<int> pila;
    int valor;

    cout << "Ingrese numeros, 0 para terminar: ";
    do
    {
        cin >> valor;
        if (valor != 0)
            pila.push(valor);
    } while (valor != 0);

    reemplazar(pila, 3);

    while (!pila.esVacia())
    {
        int x = pila.pop();
        cout << x << " -> ";
    }

    return 0;
}
