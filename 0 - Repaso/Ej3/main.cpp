/*ej3: Escribe un programa que tenga una función llamada marcarAsiento que tome un puntero
a un booleano y lo cambie a true para indicar que el asiento está reservado.
Luego, en el main, crea un arreglo que represente los asientos del teatro (inicialmente todos libres).
Pide al usuario que elija un asiento para reservar, llama a la funcion marcarAsiento y muestra el estado
de los asientos antes y después de la reserva. */

#include <iostream>
#include <string>

using namespace std;

class Teatro
{
private:
    bool asientos[20] = {false};

public:
    void marcarAsiento(bool *a)
    {
        *a = true;
    };
    void validarReserva(int x)
    {
        if (x >= 0 && x < 20)
        {
            marcarAsiento(&asientos[x]);
        }
        else
            cout << "Asiento inválido";
    }
    void mostrarAsientos()
    {
        for (int i = 0; i < 20; i++)
        {
            if (!(i % 4))
                cout << "\n";
            if (!(asientos[i]))
                cout << i << " = LIBRE | ";
            else
                cout << i << " = RESERVADO | ";
        };
    }
};

int main()
{
    Teatro lugar;
    int x;
    cout << "Bienvenido al teatro. Estos son los asientos disponibles:";
    lugar.mostrarAsientos();
    cout << "\nPor favor, elija el asiento que desee reservar ->";
    cin >> x;
    lugar.validarReserva(x);
    cout << "Estado después de la reserva:";
    lugar.mostrarAsientos();
    return 0;
};
