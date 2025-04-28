#include <iostream>
#include "CuentaBancaria.h"
#include "Factura.h"
#include "Libro.h"
#include <vector>
using namespace std;

//funcion para buscar un nombre en la lista de objetos de CuentaBancaria
bool buscarXnombre(vector<CuentaBancaria>& listaCuentas, string buscado){
    bool val=false;
    for(int i=0; i<listaCuentas.size(); i++){
        string titular=listaCuentas[i].getTitular();
        if (titular==buscado){
            cout<<"ELEMENTO ENCONTRADO CON ÉXITO, DATOS:"<<endl;
            listaCuentas[i].mostrarInfo();
            val = true;
            break;
        }
        else{
            cout<<"ELEMENTO NO ENCONTRADO"<<endl;
            val = false;
        }
    }
    return val;
}
void eliminarXnombre(vector<CuentaBancaria>& listaCuentas, string buscada){
    if (buscarXnombre(listaCuentas, buscada)){
        for(int i=0; i<listaCuentas.size(); i++){
            string titular=listaCuentas[i].getTitular();
            if (titular==buscada){
                cout<<"---------SE ELIMINARÁ EL OBJETO ("<<buscada<<") ----------"<<endl;
                listaCuentas.erase(listaCuentas.begin() + i);
            }
        }
    }
    else{
        cout<<"ELEMENTO NO ENCONTRADOO"<<endl;
    }
}


int main(){
    CuentaBancaria cb1("Juan perez", "12536235", 20000, 1.7);
    CuentaBancaria cb2("Laura Polo", "23784872", 20, 2.3);
    CuentaBancaria cb3("Carlos Gómez", "98765432", 5000, 1.5);
    CuentaBancaria cb4("Ana Torres", "56781234", 100, 2.0);
    CuentaBancaria cb5("Paulo Londra", "89765544", 10000, 0.89765544);
    vector<CuentaBancaria> cuentas = {cb1, cb2, cb3, cb4};
    cuentas.push_back(cb5);
    
    for (int i=0; i<cuentas.size(); i++){
        CuentaBancaria elemento=cuentas[i];
        elemento.mostrarInfo();
    }
    
    cout<<"-->"<<buscarXnombre(cuentas, "Carlos Gómez")<<endl;
    
    eliminarXnombre(cuentas, "Juan perez");
    for (int i=0; i<cuentas.size(); i++){
        CuentaBancaria elemento=cuentas[i];
        elemento.mostrarInfo();
    }
        
    cb1.depositar(12);
    cb1.retirar(5000);
    cb1.setSaldo(516.7);
    cb1.getSaldo();

    cb2.depositar(10);
    cb2.retirar(50);
    cb2.setSaldo(128.6);
    cb2.getSaldo();

    cb3.depositar(500);
    cb3.retirar(2000);
    cb3.setSaldo(53216.7);
    cb3.getSaldo();

    cb4.depositar(50);
    cb4.retirar(80);
    cb4.setSaldo(325);
    cb4.getSaldo();


    Factura f1(001,"01-Mar-2025","Juan Torres", 10, 234.6);
    Factura f2(002, "01-Mar-2025", "Juan Torres",2, 657.8);
    Factura f3(003, "02-Mar-2025", "Carlos Gómez",4, 12.5);
    Factura f4(004, "03-Mar-2025", "Ana Torres",6, 768.8);
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

    Libro l1("Don quijote", "Miguel de Cervantes Saveedra", 1605, 10);
    Libro l2("Orgullo y prejuicio", "Jane Austen", 1813, 20);
    Libro l3("Don quijote", "Miguel de Cervantes Saveedra", 1605, 10);
    l1.mostrarInfo();
    l2.mostrarInfo();
    if (l1.esIgualA(l3)){
        cout<<"son iguales"<<endl;
    }
    else{
        cout<<"NO son iguales"<<endl;
    }
    return 0;
}