#include <iostream>
#include "Pila/Pila.h"

using namespace std;

void invertir(Pila<char> &pila)
{
    Pila<char> auxiliar;
}

int main()
{
    Pila<char> pila;
    char caracter;

    cout << "Ingrese palabra o un punto para terminar: ";
    do
    {
        cin.get(caracter);
        if (caracter != '.')
            pila.push(caracter);
    } while (caracter != '.');

    cout << "Palabra o frase invertida -> ";

    while (!pila.esVacia())
    {
        cout << pila.pop();
    }

    cout << endl;

    return 0;
}
