/*Implementar una función recursiva que dado un numero entero lo muestre de forma invertida.
Ej: 10523 mostrar 32501. Dar aviso de error en caso de uso de numeros negativos y mostrar primero el numero a invertir
y despues el numero invertido*/

#include <iostream>

using namespace std;

int invertir(int x, int acumulador)
{
	if (x == 0)
	{
		return acumulador;
	}
	else
	{
		return (invertir(x / 10, acumulador * 10 + x % 10));
	}
};

int main()
{
	int x, resto = 0;
	cout << "Ingrese numero a invertir: ";
	cin >> x;
	cout << "Resultado: " << invertir(x, resto);
	return 0;
};