/*Ejercicio N°3
En una ciudad, se está implementando un sistema de gestión de rutas de transporte entre
distintas estaciones. Cada estación se representa como un nodo, y las rutas directas entre
estaciones se representan como aristas. Tu tarea es diseñar este sistema de rutas utilizando
grafos, donde los ciudadanos puedan interactuar con el sistema para realizar varias
operaciones.

1. Agregar estaciones: El sistema debe permitir agregar nuevas estaciones al mapa. Cada
   estación tiene un nombre único.
2. Conexión de rutas entre estaciones: Las estaciones pueden estar conectadas
   mediante rutas directas. El sistema debe permitir agregar una conexión entre dos
   estaciones, indicando que existe una ruta entre ellas.
3. Eliminar estaciones: Si una estación deja de funcionar, debe ser posible eliminarla del
   sistema. Al eliminar una estación, también deben eliminarse todas las rutas que
   conectan a dicha estación.
4. Eliminar rutas: En caso de que una ruta deje de ser operativa entre dos estaciones, el
   sistema debe poder eliminar esa conexión sin afectar al resto de las estaciones.
5. Consulta de conectividad: Los ciudadanos podrán consultar si existe una ruta directa
   entre dos estaciones específicas. El sistema debe devolver si esas estaciones están
   conectadas por una ruta.
6. Verificar si una estación existe: El sistema debe proporcionar una función para
   verificar si una estación específica existe en el mapa.
7. Imprimir el mapa completo: Finalmente, el sistema debe poder imprimir un listado de
   todas las estaciones y sus conexiones directas, mostrando el estado actual de todas
   las rutas en la ciudad.
*/

#include <iostream>
#include <string>
#include "Grafos/Grafo.h"
#include "Grafos/NodoGrafo.h"

using namespace std;

void agregarEstacion(Grafo<string> &mapa)
{
    string nombre;
    cout << "Ingrese nombre de la nueva estación: ";
    cin.ignore();
    getline(cin, nombre);

    try
    {
        mapa.agregarNodo(nombre);
    }
    catch (int e)
    {
        cout << "Ya existe ese nombre****" << endl;
    }
}

void agregarRuta(Grafo<string> &mapa)
{
    string nombre1, nombre2;
    cout << "Ingrese nombre de las estaciones que quiere conectar: ";
    cin.ignore();
    getline(cin, nombre1);
    getline(cin, nombre2);

    if (mapa.buscarNodo(nombre1) && mapa.buscarNodo(nombre2))
    {
        mapa.agregarArista(nombre1, nombre2);
    }
    else
        cout << "No existe una o ambas estaciones" << endl;
}

void eliminarEstacion(Grafo<string> &mapa)
{
    string nombre;
    cout << "Ingrese la estación que quiere eliminar ";
    cin.ignore();
    getline(cin, nombre);

    if (mapa.buscarNodo(nombre))
    {
        mapa.eliminarNodo(nombre);
    }
    else
        cout << "No existe esa estación" << endl;
}

void eliminarRuta(Grafo<string> &mapa)
{
    string nombre1, nombre2;
    cout << "Ingrese nombre de las estaciones que quiere desconectar: ";
    cin.ignore();
    getline(cin, nombre1);
    getline(cin, nombre2);

    if (mapa.buscarNodo(nombre1) && mapa.buscarNodo(nombre2))
    {
        mapa.eliminarArista(nombre1, nombre2);
    }
    else
        cout << "No existe una o ambas estaciones" << endl;
}

void verificarEstacion(Grafo<string> &mapa)
{
    string nombre;
    cout << "Ingrese la estación: ";
    cin.ignore();
    getline(cin, nombre);

    if (mapa.buscarNodo(nombre))
    {
        cout << "Existe la estación!" << endl;
    }
    else
        cout << "No existe esa estación" << endl;
}

void consultarConectividad(Grafo<string> &mapa)
{
    string nombre1, nombre2;
    cout << "Ingrese nombre de las estaciones que quiere desconectar: ";
    cin.ignore();
    getline(cin, nombre1);
    getline(cin, nombre2);
    try
    {
        if (mapa.estanConectados(nombre1, nombre2))
        {
            cout << "ESTAN CONECTADAS !!" << endl;
        }
        else
            cout << "No están conectadas" << endl;
    }
    catch (int e)
    {
        cout << "No existe alguna***" << endl;
    }
}

void imprimirMapa(Grafo<string> &mapa)
{
    mapa.imprimir();
}

int main()
{
    Grafo<string> mapa;
    int opcion;
    do
    {

        cout << "\n===== SISTEMA DE RUTAS =====" << endl;
        cout << "1. Agregar estacion" << endl;
        cout << "2. Agregar ruta" << endl;
        cout << "3. Eliminar estacion" << endl;
        cout << "4. Eliminar ruta" << endl;
        cout << "5. Consultar conectividad" << endl;
        cout << "6. Verificar estacion" << endl;
        cout << "7. Imprimir mapa" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            agregarEstacion(mapa);
            break;

        case 2:
            agregarRuta(mapa);
            break;

        case 3:
            eliminarEstacion(mapa);
            break;

        case 4:
            eliminarRuta(mapa);
            break;

        case 5:
            consultarConectividad(mapa);
            break;

        case 6:
            verificarEstacion(mapa);
            break;

        case 7:
            imprimirMapa(mapa);
            break;

        case 0:
            cout << "Fin del programa" << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while (opcion != 0);

    return 0;
}