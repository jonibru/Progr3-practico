/*Escribir un programa que pida al usuario una palabra o frase y la almacene en una Lista
separando letra por letra, luego pedirá al usuario una vocal que desee contar y, por último, se
debe imprimir por pantalla la lista y el número de veces que aparece la vocal en la palabra o
frase. Validar que la Lista no esté vacía y que la letra a contar que introduzca el usuario sea una
vocal.
*/

#include <iostream>
#include <string>
#include <cctype>
#include "../Lista.h"
#include "../nodo.h"

using namespace std;

void cargar_frase(Lista<char> &lista)
{
    string frase;
    cout << "Escriba la frase -> ";
    getline(cin, frase);
    for (char c : frase)
    {
        lista.insertarUltimo(c);
    }
}

bool es_vocal(char c)
{
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    else
        return false;
}

int contar_vocal(Lista<char> &lista, char vocal)
{
    int tamanio = lista.getTamanio();
    int contador = 0;
    for (int i = 0; i < tamanio; i++)
    {
        if (tolower(lista.getDato(i)) == tolower(vocal))
        {
            contador++;
        }
    }
    return contador;
}

int main()
{
    Lista<char> lista;
    cargar_frase(lista);
    if (lista.esVacia())
    {
        cout << "lista vacía";
        return 0;
    }
    char vocal;
    cout << "\nIntroduzca la vocal a contar: ";
    cin >> vocal;
    if (es_vocal(vocal))
    {
        int cantidad = contar_vocal(lista, vocal);

        cout << "Frase ->";
        lista.print();
        cout << "\nCantidad de vocales -> " << cantidad;
    }
    else
    {
        cout << "Error. Debe ingresar una vocal" << endl;
    }

    return 0;
};