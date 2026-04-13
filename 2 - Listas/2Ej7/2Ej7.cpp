/*Utiliza la clase ListaDoble para gestionar una lista de estudiantes, donde cada estudiante
tiene un nombre (cadena de caracteres) y una edad (entero). Implementa las siguientes
funcionalidades:
1. Agregar Estudiantes:
○ Usa los métodos de ListaDoble para agregar varios estudiantes a la lista.
Debes insertar al menos cinco estudiantes con nombres y edades diferentes.
2. Mostrar Estudiantes:
○ Implementa una función que recorra la lista y muestre todos los estudiantes en
orden. Utiliza el método imprimir() de ListaDoble.
3. Buscar un Estudiante por Nombre:
○ Implementa una función que busque un estudiante por su nombre. Utiliza el
método getDato(int pos) para acceder a los datos de los nodos y busca al
estudiante en la lista.
4. Eliminar un Estudiante por Nombre:
○ Implementa una función que elimine un estudiante por su nombre. Utiliza los
métodos getDato(int pos) y remover(int pos) para encontrar y
eliminar al estudiante de la lista.
5. Contar Estudiantes:
○ Usa el método getTamanio() para contar el número de estudiantes en la lista
y muestra el resultado.*/

#include <iostream>
#include <string>
#include "../Lista.h"
#include "../nodo.h"
#include "../ListaDoble.h"

using namespace std;

void agregarEstudiante(ListaDoble<string> &nombres, ListaDoble<int> &edades, string name, int edad)
{
    nombres.insertarUltimo(name);
    edades.insertarUltimo(edad);
}

void mostrarEstudiantes(ListaDoble<string> &nombres, ListaDoble<int> &edades)
{
    int n = nombres.getTamanio();
    cout << "Estudiante = Nombre -> Edad" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nombres.getDato(i) << " -> " << edades.getDato(i) << endl;
    }
}

void buscarNombre(ListaDoble<string> &nombres, ListaDoble<int> &edades, string name)
{
    int n = nombres.getTamanio();
    bool existe = false;
    for (int i = 0; i < n; i++)
    {
        if (name == nombres.getDato(i))
        {
            cout << "Nombre = " << name << " - Edad = " << edades.getDato(i) << endl;
            existe = true;
            break;
        }
    }
    if (!(existe))
        cout << "Error. Estudiante no existente." << endl;
}

void eliminarEstudiante(ListaDoble<string> &nombres, ListaDoble<int> &edades, string name)
{
    int n = nombres.getTamanio();
    for (int i = 0; i < n; i++)
    {
        if (name == nombres.getDato(i))
        {
            nombres.remover(i);
            edades.remover(i);
            return;
        }
    }
    cout << "Error. Estudiante no existente." << endl;
}

int contarEstudiantes(ListaDoble<string> &nombres)
{
    return nombres.getTamanio();
}

void mostrarMenu()
{
    cout << "\n------MENU:\n1- Agregar estudiante\n2- Mostrar estudiantes\n"
            "3- Buscar estudiante por Nombre\n4- Eliminar estudiante por Nombre\n"
            "5- Contar estudiantes\n9- SALIR\n-------\n ->"
         << endl;
}

int main()
{
    int x;

    ListaDoble<string> nombres;
    ListaDoble<int> edades;

    mostrarMenu();
    cin >> x;
    while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5)
    {
        switch (x)
        {
            {
            case 1:
                string name;
                int edad;
                cout << "Ingrese el nombre -> ";
                cin >> name;
                cout << "Ingrese la edad -> ";
                cin >> edad;
                agregarEstudiante(nombres, edades, name, edad);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 2:
                mostrarEstudiantes(nombres, edades);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 3:
                string name;
                cout << "Ingrese nombre: ";
                cin >> name;
                buscarNombre(nombres, edades, name);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 4:
                string name;
                cout << "Ingrese nombre: ";
                cin >> name;
                eliminarEstudiante(nombres, edades, name);
                mostrarMenu();
                cin >> x;
                break;
            }

            {
            case 5:
                cout << "Cantidad de estudiantes -> " << contarEstudiantes(nombres);
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
}