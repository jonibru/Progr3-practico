/*Ejercicio N°3
Registro de productos en una tienda. Almacenar productos de una tienda usando un código
único como clave y el nombre del producto como valor. Usa el HashMap para almacenar los
productos. El código de producto es la clave y el nombre es el valor.
Implementa opciones para:
● Añadir productos.
● Buscar productos por su código.
● Actualizar el nombre de un producto existente.
● Eliminar productos.
● Imprimir todos los productos registrados.
● Desafío adicional: Implementa el manejo de colisiones, y lanza excepciones cuando se
intenten agregar productos con códigos ya existentes o buscar productos no
registrados.*/
#include <iostream>
#include <string>
#include "Hash/HashMap.h"
#include "Hash/HashMapList.h"
using namespace std;

unsigned int Hashstring(string clave)
{
    unsigned int hash = 0;

    for (int i = 0; i < clave.length(); i++)
    {
        hash += clave[i];
    }
    return hash;
}

int main()
{
    unsigned int tamanio = 11;
    HashMap<string, string> catalogo(tamanio, Hashstring);
    cout << "Ejercicio N° 3" << endl;

    int opcion;
    string clave, nombre;

    do
    {
        cout << "1. Añadir producto\n";
        cout << "2. Buscar producto por codigo";
        cout << "3. Actualizar nombre de producto";
        cout << "4. Eliminar producto";
        cout << "5. Imprimir todos los productos registrados";
        cout << "0. Salir\n";

        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese clave del producto: ";
            cin >> clave;
            cin.ignore();
            cout << "Ingrese nombre del producto: ";
            getline(cin, nombre);
            try
            {
                catalogo.put(clave, nombre);
                cout << "Producto agregado exitosamente.";
            }
            catch (int e)
            {
                if (e == 409)
                {
                    cout << "Error. Existe una colisión";
                }
            }
        }
    };

    return 0;
}
