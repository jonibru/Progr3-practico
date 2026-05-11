/*Escribir una función Reemplazar que tenga como argumentos una pila con tipo de elemento
int y dos valores int: viejo y nuevo de forma que, si el primer valor (viejo) aparece en algún
lugar de la pila, sea reemplazado por el segundo (nuevo)..
*/

#include <iostream>
#include "Pila/Pila.h"

using namespace std;

void reemplazar(Pila<int> &p, int viejo, int nuevo)
{
    Pila<int> p_aux;
    while (!p.esVacia())
    {
        int x = p.pop();
        if (x == viejo)
            x = nuevo;
        p_aux.push(x);
    }
    while (!p_aux.esVacia())
    {
        int x = p_aux.pop();
        p.push(x);
    }
}

int main()
{
    Pila<int> pila;
    int valor;

    cout << "Ingrese numeros, 0 para terminar: ";
    do
    {
        cin >> valor;
        if (valor != 0)
            pila.push(valor);
    } while (valor != 0);

    reemplazar(pila, 3, 7);

    while (!pila.esVacia())
    {
        int x = pila.pop();
        cout << x << " -> ";
    }

    return 0;
}
