/*Implementar una función llamada “printLista” que reciba una lista y una posición “p” e
imprima los elementos de esa lista a partir de la posición “p”. No debe modificarse la lista
original. Ej: listaOriginal: 1->2->3->4->5->6->7->8->9->10 con p=5 Por pantalla se verá:
7->8->9->10*/

#include "../Lista.h"
#include "../nodo.h"
#include <iostream>
using namespace std;

void printLista(Lista<int> lista, int p)
{
    int tamanio = lista.getTamanio();

    for (int i = p + 1; i < tamanio; i++)
    {
        cout << lista.getDato(i) << "->";
    }
    cout << "NULL" << endl;
}

int main()
{
    Lista<int> lista;

    for (int i = 1; i <= 10; i++)
    {
        lista.insertarUltimo(i);
    }
    lista.print();        // Ver lista completa
    printLista(lista, 5); // desde posicion 5 en adelante

    return 0;
};