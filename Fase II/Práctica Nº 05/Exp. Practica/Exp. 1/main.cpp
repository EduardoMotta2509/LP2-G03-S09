#include <iostream>
#include "CuentaBancaria.h"

using namespace std;

int main() {

    CuentaBancaria cuenta1("12345", "Carlos Rodríguez", 1000.0);


    cout << "Detalles de la cuenta 1:" << endl;
    cout << "Número de Cuenta: " << cuenta1.getNumero() << ", Titular: " << cuenta1.getTitular() << ", Saldo: " << cuenta1.getSaldo() << endl;


    cuenta1.depositar(500.0);
    cuenta1.mostrarSaldo();


    cuenta1.retirar(200.0);
    cuenta1.mostrarSaldo();


    CuentaBancaria cuenta2("67890", "Ana Martínez", 0.0);
    cuenta2.setSaldo(1500.0).setTitular("Ana Martínez").setNumero("67890"); 


    cout << "\nDetalles de la cuenta 2:" << endl;
    cout << "Número de Cuenta: " << cuenta2.getNumero() << ", Titular: " << cuenta2.getTitular() << ", Saldo: " << cuenta2.getSaldo() << endl;

    return 0;
}