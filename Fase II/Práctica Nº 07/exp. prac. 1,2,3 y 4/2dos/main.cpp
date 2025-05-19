#include <iostream>
#include "ClienteSeguro.h"

using namespace std;

int main() {
    ClienteSeguro cliente1("Francisco Filinich", "Av. Hermosa 123", "987654321", 1500.50, "12345");
    string claveUsuario;
    cout << "Introduce la clave de autenticación: ";
    cin >> claveUsuario;
    cliente1.mostrarInfoSeguro(claveUsuario);

    return 0;
}