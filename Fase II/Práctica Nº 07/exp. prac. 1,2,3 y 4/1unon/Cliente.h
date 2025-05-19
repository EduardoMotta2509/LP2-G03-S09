#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente {
protected:
    string nombre;
    string direccion;
    string telefono;
    double saldo;

public:
    Cliente(string nom, string dir, string tel, double sal) {
        nombre = nom;
        direccion = dir;
        telefono = tel;
        saldo = sal;
    }
    
    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Teléfono: " << telefono << endl;
        cout << "Saldo: " << saldo << " soles" << endl;
    }
};
#endif