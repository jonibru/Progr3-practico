/*ej2: Hallar el factorial de un numero a partir de un bucle*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Ingrese el numero: ";
    cin >> num;

    int resultado = num;
    int i = num - 1;

    while (i >= 1)
    {
        resultado *= i;
        i--;
    }

    if (num == 0)
        resultado = 1;

    cout << "Su factorial es = " << resultado << endl;

    return 0;
}