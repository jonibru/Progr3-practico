//
// Created by Matias on 10-May-26.
//
#include "Hash/HashMapList.h"
#include <iostream>
using namespace std;
/*
 EJERCICIO 1
Consigna: Implementar una función:

int eliminarClavesMenores(HashMapList<int,int>& tabla, int k);

que elimine de una tabla hash de 101 elementos, todas las claves menores que k.

La función debe:

 1. devolver la cantidad de elementos eliminados
 2. utilizar try-catch
 3. trabajar únicamente con los métodos disponibles de la librería
 4. considerar que pueden existir colisiones

 */

int eliminarClavesMenores(HashMapList<int, int> &tabla, int k)
{
    int eliminados = 0;

    for (int i = 0; i < k; i++)
    {
        try
        {
            tabla.remove(i);
            eliminados++;
        }
        catch (int e)
        {
            // error 404
            cout << "Error 404. No existe la clave " << i << endl;
        }
    }
    return eliminados;
}

int main()
{

    HashMapList<int, int> tabla(101);

    tabla.put(1, 50);
    tabla.put(3, 90);
    tabla.put(7, 20);
    tabla.put(8, 20);
    tabla.put(4, 20);
    tabla.put(2, 20);
    tabla.put(9, 20);
    tabla.put(10, 20);

    cout << "Tabla original:" << endl;
    tabla.print();

    int eliminados = eliminarClavesMenores(tabla, 5);

    cout << endl;
    cout << "Eliminados: " << eliminados << endl;

    cout << endl;
    cout << "Tabla final:" << endl;
    tabla.print();

    return 0;
}