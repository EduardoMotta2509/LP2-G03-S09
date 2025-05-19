#include <iostream>
#include "Figura.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Pentagono.h"

using namespace std;

int main() {
    Figura* figura = nullptr;
    int opcion;
    double a, b;

    cout << "Seleccione una figura:\n";
    cout << "1. Circulo\n";
    cout << "2. Rectangulo\n";
    cout << "3. Triangulo\n";
    cout << "4. Cuadrado\n";
    cout << "5. Pentagono\n";
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Ingrese el radio del circulo: ";
            cin >> a;
            figura = new Circulo(a);
            break;
        case 2:
            cout << "Ingrese la base del rectangulo: ";
            cin >> a;
            cout << "Ingrese la altura del rectangulo: ";
            cin >> b;
            figura = new Rectangulo(a, b);
            break;
        case 3:
            cout << "Ingrese la base del triangulo: ";
            cin >> a;
            cout << "Ingrese la altura del triangulo: ";
            cin >> b;
            figura = new Triangulo(a, b);
            break;
        case 4:
            cout << "Ingrese el lado del cuadrado: ";
            cin >> a;
            figura = new Cuadrado(a);
            break;
        case 5:
            cout << "Ingrese el lado del pentagono: ";
            cin >> a;
            cout << "Ingrese la apotema del pentagono: ";
            cin >> b;
            figura = new Pentagono(a, b);
            break;
        default:
            cout << "Opcion no valida.\n";
            return 1;
    }

    cout << "El area de la figura es: " << figura->calcularArea() << endl;

    delete figura;
    return 0;
}
