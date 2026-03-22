/*Crear una clase Calculadora, debe tener los métodos sumar, restar, dividir, multiplicar,
que realizarán operaciones en dos propiedades A y B.
En el método dividir verificar que el divisor no es 0. Si es 0 arrojar una excepcion*/

#include <iostream>
#include <string>

using namespace std;

class Calculadora
{
private:
    float A;
    float B;

public:
    Calculadora(float a, float b)
    {
        A = a;
        B = b;
    };

    float sumar()
    {
        return A + B;
    };
    float restar()
    {
        return A - B;
    };
    float multiplicar()
    {
        return A * B;
    };
    float dividir()
    {
        if (B == 0)
        {
            throw string("No puedo realizar esa operación");
        }
        else
            return A / B;
    };
};

int main()
{
    float a, b, resultado;
    int x;
    cout << "Ingrese la operación que quiere realizar" << endl;
    cout << "1=suma\n2=resta\n3=multiplicacion\n4=división\n->";
    cin >> x;
    cout << "Ingrese ambos números para la operación:\n";
    cin >> a;
    cin >> b;
    Calculadora c1(a, b);

    try
    {
        switch (x)
        {
        case 1:
            resultado = c1.sumar();
            break;
        case 2:
            resultado = c1.restar();
            break;
        case 3:
            resultado = c1.multiplicar();
            break;
        case 4:
            resultado = c1.dividir();
            break;
        default:
            cout << "Opcion Invalida" << endl;
            return 1;
        };
        cout << "Resultado = " << resultado;
    }
    catch (string mensaje)
    {
        cout << "Error -> " << mensaje << endl;
    }

    return 0;
};