/*ej1: Tienes dos vasos, uno con jugo de naranja y otro con jugo de manzana.
Desarrollar programa que tenga funcion llamada intercambiarJugos que tome dos vasos y los intercambie.
Luego, en la función main, pedimos al usuario que ingrese la cantidad de jugo en cada vaso.
Llamamos a la funcion intercambiarJugos y mostramos las cantidades después del intercambio*/

#include <iostream>
#include <string>

using namespace std;

class Vaso
{
private:
    string tipo;
    float cantidad;

public:
    void setTipo(string x)
    {
        tipo = x;
    };
    string getTipo()
    {
        return tipo;
    };
    void setCantidad(float x)
    {
        cantidad = x;
    };

    float getCantidad()
    {
        return cantidad;
    };

    void intercambiarJugos(Vaso &otro)
    {
        float aux = cantidad;
        cantidad = otro.cantidad;
        otro.cantidad = aux;
    };
};

int main()
{
    Vaso vaso1, vaso2;
    float c;

    vaso1.setTipo("Naranja");
    vaso2.setTipo("Manzana");

    cout << "Cantidad de jugo de naranja: ";
    cin >> c;
    vaso1.setCantidad(c);
    cout << "\nCantidad de jugo de manzana: ";
    cin >> c;
    vaso2.setCantidad(c);

    vaso1.intercambiarJugos(vaso2);

    cout << "Cantidad nueva de jugo de naranja -> " << vaso1.getCantidad() << "\nCantidad nueva de jugo de manzana -> " << vaso2.getCantidad() << endl;

    return 0;
};
