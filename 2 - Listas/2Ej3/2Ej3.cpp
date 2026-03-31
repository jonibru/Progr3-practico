/*Implementar una función que intercambie los elementos entre 2 listas de números enteros
que recibe como parámetros. Si los tamaños de las listas son distintos, igual debe cambiar los
datos y cambiarían los tamaños de cada lista. Ejemplo sea lista1= 15->1->8->35->40->25->12 y
lista2= 3->4->912->45->66 al ejecutar la función quedarían lista1= 3->4->912->45->66 y
lista2=15->1->8->35->40->25->12.*/

#include <iostream>
#include "../Lista.h"
#include "../nodo.h"

using namespace std;

void intercambiar_lista(Lista<int> &lista1, Lista<int> &lista2)
{ // creo copias locales de lista1 y lista2 para facilitar
    Lista<int> nueva_lista1;
    Lista<int> nueva_lista2;

    for (int i = 0; i < lista1.getTamanio(); i++)
    {
        nueva_lista1.insertarUltimo(lista1.getDato(i));
    }
    lista1.vaciar();

    for (int i = 0; i < lista2.getTamanio(); i++)
    {
        nueva_lista2.insertarUltimo(lista2.getDato(i));
    }
    lista2.vaciar();

    for (int i = 0; i < nueva_lista2.getTamanio(); i++)
    {
        lista1.insertarUltimo(nueva_lista2.getDato(i));
    }
    for (int i = 0; i < nueva_lista1.getTamanio(); i++)
    {
        lista2.insertarUltimo(nueva_lista1.getDato(i));
    }
}

int main()
{
    Lista<int> lista1;
    Lista<int> lista2;

    lista1.insertarUltimo(17);
    lista1.insertarUltimo(33);
    lista1.insertarUltimo(3);
    lista1.insertarUltimo(51);
    lista1.insertarUltimo(1021);
    lista1.insertarUltimo(121);
    cout << "Lista 1: ";
    lista1.print();

    lista2.insertarUltimo(28);
    lista2.insertarUltimo(84);
    lista2.insertarUltimo(764);
    lista2.insertarUltimo(12);
    cout << "Lista 2: ";
    lista2.print();

    intercambiar_lista(lista1, lista2);

    cout << "\n\nNuevo:\nLista 1: ";
    lista1.print();

    cout << "Lista 2: ";
    lista2.print();

    return 0;
};