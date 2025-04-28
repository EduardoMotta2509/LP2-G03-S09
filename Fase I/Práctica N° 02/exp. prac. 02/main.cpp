#include <iostream>
#include "CuentaBancaria.h"
#include "Factura.h"
#include <vector>
using namespace std;

void imprimirDatos(vector){

}

int main(){
    CuentaBancaria cb1("Juan perez", "12536235", 20000, 1.7);
    CuentaBancaria cb2("Laura Polo", "23784872", 20, 2.3);
    CuentaBancaria cb3("Carlos Gómez", "98765432", 5000, 1.5);
    CuentaBancaria cb4("Ana Torres", "56781234", 100, 2.0);
    vector<CuentaBancaria> cuentas = {cb1, cb2, cb3, cb4};

    for (int i=0; i<cuentas.size(); i++){
        elemento=cuentas[i];
        elemento.mostrarInfo();
    }
    
    cb1.depositar(12);
    cb1.retirar(5000);
    cb1.setSaldo(516,7);
    cb1.getSaldo();

    cb2.depositar(10);
    cb2.retirar(50);
    cb2.setSaldo(128,6);
    cb2.getSaldo();

    cb3.depositar(500);
    cb3.retirar(2000);
    cb3.setSaldo(53216,7);
    cb3.getSaldo();

    cb4.depositar(50);
    cb4.retirar(80);
    cb4.setSaldo(325);
    cb4.getSaldo();


    Factura f1(001,"01-Mar-2025","Juan Torres", 10);
    Factura f2(002, "01-Mar-2025", "Juan Torres",2);
    Factura f3("003", "02-Mar-2025", "Carlos Gómez");
    Factura f4("004", "03-Mar-2025", "Ana Torres");
    f1.mostrarFactura();
    f1.setFechaEmision("01-Abril-2001");
    cout << "Nueva fecha de emisión de f1: " << f1.getFechaEmision() << endl;
    f1.getFechaEmision();
    f2.mostrarFactura();
    f2.setFechaEmision("23-Agosto-2020");
    cout << "Nueva fecha de emisión de f2: " << f2.getFechaEmision() << endl;
    f2.getFechaEmision();
    f3.mostrarFactura();
    f3.setFechaEmision("15-Mar-2025");
    cout << "Nueva fecha de emisión de f3: " << f3.getFechaEmision() << endl;
    f4.mostrarFactura();
    f4.setFechaEmision("20-Mar-2025");
    cout << "Nueva fecha de emisión de f4: " << f4.getFechaEmision() << endl;
    return 0;
}