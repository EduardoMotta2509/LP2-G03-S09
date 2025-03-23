#include <iostream>
#include "Persona.h"
#include "CuentaBancaria.h"
#include "Libro.h"
#include "Factura.h"
using namespace std;

int main(){
    Persona p1(74821536, "Calle 123", "Casado", "Juan Perez", 19, "Masculino" );
    Persona p2(30947852, "Av Ejercito 156", "Soltera", "Grace Molina", 18, "Femenino");
    cout<<"DNI de "<<p1.nombre<<": "<<p1.getDNI()<<endl;
    p1.setDNI(11111111);
    cout<<"NUEVO DNI de "<<p1.nombre<<": "<<p1.getDNI()<<endl;
    cout<<"DNI de "<<p2.nombre<<": "<<p2.getDNI()<<endl;;
    p2.setDNI(22222222);
    cout<<"NUEVO DNI de "<<p2.nombre<<": "<<p2.getDNI()<<endl;

    CuentaBancaria cb1("Juan perez", "12536235", 20000, 1.7);
    CuentaBancaria cb2("Laura Polo", "23784872", 20, 2.3);
    cb1.depositar(12);
    cb1.retirar(5000);
    cb2.depositar(10);
    cb2.retirar(50);

    Libro l1("Don quijote", "Miguel de Cervantes Saveedra", 1605, 10);
    Libro l2("Orgullo y prejuicio", "Jane Austen", 1813, 20);
    l1.mostrarInfo();
    l2.mostrarInfo();

    Factura f1(001,"01-Mar-2025","Juan Torres", 10,200);
    Factura f2(002, "01-Mar-2025", "Juan Torres",2,113.5);
    f1.mostrarFactura();
    f2.mostrarFactura();
    return 0;
}