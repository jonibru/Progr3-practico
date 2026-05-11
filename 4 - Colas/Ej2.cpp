/*Implementar una función que suprima de la cola todos los elementos mayores que un número
“n” dado como límite. Al final se debe imprimir la cola depurada sin perder el orden que había
desde la cola original.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void suprimir(Cola<int> &c1, int n)
{
    Cola<int> aux;
    while (!(c1.esVacia()))
    {
        int valor = c1.desencolar();
        if (valor <= n)
        {
            aux.encolar(valor);
        }
    }
    while (!(aux.esVacia()))
    {
        c1.encolar(aux.desencolar());
    }
}

void mostrarCola(Cola<int> &c1)
{
    int valor;
    while (!(c1.esVacia()))
    {
        valor = c1.desencolar();
        cout << valor << " -> ";
    }
    cout << "NULL";
}
void encolar(Cola<int> &c1)
{
    cout << "\nIngrese valores, 0 para terminar:" << endl;
    int s;
    while (true)
    {
        cin >> s;
        if (s == 0)
            break;
        c1.encolar(s);
    }
}

int main()
{
    Cola<int> cola1;
    int n;
    cout << "Ejercicio N° 2" << endl;
    encolar(cola1);
    cout << "Ingrese n:";
    cin >> n;
    suprimir(cola1, n);
    mostrarCola(cola1);

    return 0;
}
