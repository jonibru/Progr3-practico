/*Crea un programa que gestione una lista circular de contactos. Cada contacto contiene un
nombre (cadena de caracteres) y un número de teléfono (cadena de caracteres).
Tareas
1. Agregar Contactos:
○ Usa los métodos de CircList para agregar varios contactos a la lista. Deberás
insertar al menos cinco contactos con nombres y números de teléfono distintos.
2. Mostrar Contactos:
○ Implementa una función que recorra la lista circular y muestre todos los
contactos en orden. Usa el método imprimir() de CircList.
3. Buscar un Contacto por Nombre:
○ Implementa una función que busque un contacto por su nombre. Usa el método
getDato(int pos) para acceder a los datos de los nodos y busca el
contacto en la lista.
4. Eliminar un Contacto por Nombre:
○ Implementa una función que elimine un contacto por su nombre. Deberás usar
los métodos getDato(int pos) y eliminarPorValor(T valor) (supón
que eliminarPorValor está implementado, aunque no esté explícito en el
código proporcionado).
5. Contar Contactos:
○ Usa el método getTamanio() para contar el número de contactos en la lista y
muestra el resultado.*/

#include <iostream>
#include "../Lista.h"
#include "../ListaDoble.h"
#include "../nodo.h"
#include "../CircList.h"

using namespace std;

int main()
{
    int x;

    cout << "MENU:\n1- Agregar contacto\n2- Mostrar contactos\n"
            "3- Buscar contacto por Nombre\n4- Eliminar contacto por Nombre\n"
            "5- Contar contactos\n9- SALIR\n\n ->"
         << endl;
    cin >> x;
    while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5)
    {
        switch (x)
        {
        case 1:
        }
    }

    return 0;
};