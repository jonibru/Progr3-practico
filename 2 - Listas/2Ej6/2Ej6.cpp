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
#include <string>
#include "../Lista.h"
#include "../nodo.h"
#include "../CircList.h"

using namespace std;

void agregarContacto(Lista<string> &nombres, Lista<string> &numeros, string name, string number)
{
    nombres.insertarUltimo(name);
    numeros.insertarUltimo(number);
}

void mostrarContactos(Lista<string> &nombres, Lista<string> &numeros)
{
    Lista<string> combinada;
    int n = nombres.getTamanio();
    for (int i = 0; i < n; i++)
    {
        combinada.insertarUltimo(nombres.getDato(i));
        combinada.insertarUltimo(numeros.getDato(i));
    }
    cout << "Contacto = Nombre -> Número" << endl;
    combinada.print();
}

void buscarNombre(Lista<string> &nombres, Lista<string> &numeros, string name)
{
    int n = nombres.getTamanio();
    bool existe = false;
    for (int i = 0; i < n; i++)
    {
        if (name == nombres.getDato(i))
        {
            cout << "Nombre = " << name << " - Numero = " << numeros.getDato(i) << endl;
            existe = true;
            break;
        }
    }
    if (!(existe))
        cout << "Error. Contacto no existente." << endl;
}

void eliminarContacto(Lista<string> &nombres, Lista<string> &numeros, string name)
{
    int n = nombres.getTamanio();
    for (int i = 0; i < n; i++)
    {
        if (name == nombres.getDato(i))
        {
            nombres.remover(i);
            numeros.remover(i);
            break;
        }
    }
    cout << "Error. Contacto no existente." << endl;
}

int contarContactos(Lista<string> &nombres)
{
    return nombres.getTamanio();
}

void mostrarMenu()
{
    cout << "\n------MENU:\n1- Agregar contacto\n2- Mostrar contactos\n"
            "3- Buscar contacto por Nombre\n4- Eliminar contacto por Nombre\n"
            "5- Contar contactos\n9- SALIR\n-------\n ->"
         << endl;
}

int main()
{
    int x;

    Lista<string> nombres, numeros;

    mostrarMenu();
    cin >> x;
    while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5)
    {
        switch (x)
        {
            {
            case 1:
                string name, number;
                cout << "Ingrese el nombre -> ";
                cin >> name;
                cout << "Ingrese el numero -> ";
                cin >> number;
                agregarContacto(nombres, numeros, name, number);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 2:

                mostrarContactos(nombres, numeros);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 3:
                string name;
                cout << "Ingrese nombre: ";
                cin >> name;
                buscarNombre(nombres, numeros, name);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 4:
                string name;
                cout << "Ingrese nombre: ";
                cin >> name;
                eliminarContacto(nombres, numeros, name);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 5:
                cout << "Cantidad de contactos -> " << contarContactos(nombres);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 9:
                break;
            }

            {
            default:
                cout << "Opcion invalida" << endl;
            }
        }
    }

    return 0;
};