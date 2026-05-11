/*Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar si son
iguales. Nota: los elementos constitutivos de las colas son caracteres.*/

#include <iostream>
#include <string>
using namespace std;

#include "Cola/Cola.h"

bool sonIguales(Cola<char> c1, Cola<char> c2)
{
    while (!(c1.esVacia()) && !(c2.esVacia()))
    {
        if (c1.desencolar() != c2.desencolar())
            return false;
    }
    return ((c1.esVacia()) && (c2.esVacia()));
}

void encolar(Cola<char> &c1)
{
    cout << "\nIngrese valores, punto para terminar:" << endl;
    char s;
    while (true)
    {
        cin >> s;
        if (s == '.')
            break;
        c1.encolar(s);
    }
}

int main()
{
    Cola<char> cola1;
    Cola<char> cola2;
    cout << " Ejercicio 1 " << endl;
    encolar(cola1);
    encolar(cola2);
    if (sonIguales(cola1, cola2))
        cout << "Si, son iguales" << endl;
    else
        cout << "No, no son iguales" << endl;

    return 0;
}
