/*Ejercicio 1: Organización de una biblioteca
Problema: Estás organizando una biblioteca familiar. Cada libro tiene un número único de
identificación (ID) y quieres organizar los libros en un sistema que te permita agregarlos,
eliminarlos y buscarlos fácilmente.
● Tarea: Inserta los libros con los siguientes IDs en el sistema de gestión (árbol): 101,
52, 198, 36, 75, 150, 200.
● Desafío: Busca el libro con el ID 75 y verifica si está en la biblioteca. Luego elimina
el libro con el ID 52 porque fue prestado. Imprime la estructura del sistema después
de la eliminación.
*/

#include <iostream>
#include <string>
using namespace std;

#include "Arbol/ArbolBinario.h"

int main()
{
    ArbolBinario<int> biblioteca;
    cout << "Cargando libros\n"
         << endl;
    biblioteca.put(101);
    biblioteca.put(52);
    biblioteca.put(198);
    biblioteca.put(36);
    biblioteca.put(75);
    biblioteca.put(150);
    biblioteca.put(200);

    cout << "Buscando libros con ID = 75" << endl;

    try
    {
        int libro1 = biblioteca.search(75);
        cout << "El libro con ID=75 está en la biblioteca\n"
             << endl;
    }
    catch (int err)
    {
        throw "No se encuentra el libro";
    }

    try
    {
        biblioteca.remove(52);
        cout << "El libro con ID=52 fue eliminado\n"
             << endl;
    }
    catch (int err)
    {
        throw "No se encuentra el libro";
    }

    biblioteca.print();

    return 0;
}
