#include <iostream>
#include "ClienteSeguro.h"

using namespace std;

int main() {
    ClienteSeguroPublico cliente1("Francisco Filinich", "Av. Hermosa 123", "987654321", 1500.50, "12345");
    ClienteSeguroProtegido cliente2("Eduardo Motta", "Calle Copacabana 456", "912345678", 2000.75, "54321");
    ClienteSeguroPrivado cliente3("Fabricio Chirinos", "Av. Alcides Carrión 789", "901234567", 1850.20, "00000");

    string clave;

    cout << "Clave para cliente 1: ";
    cin >> clave;
    cliente1.mostrarInfoSeguro(clave);

    cout << "Clave para cliente 2: ";
    cin >> clave;
    cliente2.mostrarInfoSeguro(clave);

    cout << "Clave para cliente 3: ";
    cin >> clave;
    cliente3.mostrarInfoSeguro(clave);

    return 0;
}
