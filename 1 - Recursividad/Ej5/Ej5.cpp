/*Crear un programa que pida al usuario un número entero positivo "n" y un dígito "d". Luego crear una función recursiva
que determine si “d” está en “n”. Si está, la función debe retornar verdadero y si no está debe retornar falso.
Ej.: si n=1323 y d = 5, retorna Falso y si d= 1 retorna verdadero.*/

#include <iostream>

using namespace std;

bool esta_el_digito(int n, int d)
{
    if (n % 10 == d)
        return true;
    if (n < 10)
    {
        return false;
    }
    else
    {
        return esta_el_digito(n / 10, d);
    }
}

int main()
{
    int n, d;
    cout << "Ingrese entero positivo N: ";
    cin >> n;
    if (n < 1)
        throw "Error. Ingrese entero positivo";
    else
    {
        cout << "Ingrese digito D->";
        cin >> d;
    }
    cout << boolalpha; // hace que imprima true/false en vez de 1/0
    cout << "Resultado ->" << esta_el_digito(n, d) << endl;

    return 0;
};