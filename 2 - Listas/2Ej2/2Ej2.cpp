/*Implementar una función que recibe una lista de números enteros y un número entero “n” y
que modifique la lista borrando todos los elementos de la lista que tengan el número “n”.
Imprimir la lista antes de hacer el llamado a la función y luego del llamado a la función para
mostrar que la lista original cambió. ej: lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe
pasar con la función a 1->2->4->5->7->8->10.*/

#include <iostream>
#include "../Lista.h"
#include "../nodo.h"

using namespace std;

void eliminar_elemento(Lista<int> &lista, int n)
{
    int i = 0;
    while (i < lista.getTamanio())
    {
        if (lista.getDato(i) == n)
        {
            lista.remover(i);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    Lista<int> lista;
    lista.insertarUltimo(1);
    lista.insertarUltimo(2);
    lista.insertarUltimo(3);
    lista.insertarUltimo(4);
    lista.insertarUltimo(5);
    lista.insertarUltimo(3);
    lista.insertarUltimo(7);
    lista.insertarUltimo(8);
    lista.insertarUltimo(3);
    lista.insertarUltimo(10);
    lista.print();
    int n;
    cout << "Ingrese numero a eliminar: ";
    cin >> n;
    eliminar_elemento(lista, n);
    lista.print();
    return 0;
};