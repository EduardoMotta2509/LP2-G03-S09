#include <iostream>
#include "Contenedor.h"
using namespace std;

int main() {
    Contenedor<int> contInt;
    contInt.agregar(5);
    contInt.agregar(10);
    contInt.agregar(15);
    cout << "Contenedor de enteros: ";
    contInt.mostrar();

    Contenedor<string> contStr;
    contStr.agregar("Hola");
    contStr.agregar("Mundo");
    cout << "Contenedor de strings: ";
    contStr.mostrar();

    cout << "Elemento [1] del contInt: " << contInt.obtener(1) << endl;
    cout << "Tamaño del contStr: " << contStr.tamaño() << endl;

    return 0;
}