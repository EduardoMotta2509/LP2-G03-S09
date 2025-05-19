#include <iostream>
#include "Forma.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"

using namespace std;

int main() {
    Forma* forma = nullptr;
    int opcion;

    cout << "Seleccione una forma:\n1. Círculo\n2. Rectángulo\n3. Triángulo\nOpción: ";
    cin >> opcion;

    switch(opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del círculo: ";
            cin >> radio;
            forma = new Circulo(radio);
            break;
        }
        case 2: {
            double base, altura;
            cout << "Ingrese base y altura del rectángulo: ";
            cin >> base >> altura;
            forma = new Rectangulo(base, altura);
            break;
        }
        case 3: {
            double l1, l2, l3;
            cout << "Ingrese los tres lados del triángulo: ";
            cin >> l1 >> l2 >> l3;
            forma = new Triangulo(l1, l2, l3);
            break;
        }
        default:
            cout << "Opción inválida.\n";
            return 1;
    }

    cout << "Perímetro calculado: " << forma->calcularPerimetro() << endl;

    delete forma;
    return 0;
}
