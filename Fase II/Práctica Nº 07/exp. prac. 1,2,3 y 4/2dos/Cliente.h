#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>
using namespace std;

class Cliente {
protected:
    string nombre;
    string direccion;
    string telefono;
    double saldo;

    string encriptar(string texto) {
        string resultado = "";
        for (char c : texto) {
            resultado += c + 1;
        }
        return resultado;
    }

public:
    Cliente(string nom, string dir, string tel, double sal) {
        nombre = encriptar(nom);
        direccion = encriptar(dir);
        telefono = encriptar(tel);
        saldo = sal;
    }

    void mostrarInfo() {
        cout << "Nombre encriptado: " << nombre << endl;
        cout << "Dirección encriptada: " << direccion << endl;
        cout << "Teléfono encriptado: " << telefono << endl;
        cout << "Saldo: " << saldo << " soles" << endl;
    }
};

#endif
