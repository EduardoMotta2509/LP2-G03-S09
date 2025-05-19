#ifndef CLIENTESEGURO_H
#define CLIENTESEGURO_H

#include "Cliente.h"

class ClienteSeguro : public Cliente {
private:
    string clave;

public:
    ClienteSeguro(string nom, string dir, string tel, double sal, string cla) 
        : Cliente(nom, dir, tel, sal) {
        clave = cla;
    }

    string encriptarInformacion() {
        string encriptado = "";
        for (char c : nombre) {
            encriptado += c + 1;
        }
        return encriptado;
    }

    bool verificarAutenticidad(string claveIngresada) {
        return claveIngresada == clave;
    }

    void mostrarInfoSeguro() {
        if (verificarAutenticidad(clave)) {
            cout << "Información ya autenticada: " << endl;
            mostrarInfo();
            cout << "Nombre el cual está encriptado: " << encriptarInformacion() << endl;
        } else {
            cout << "La autenticación falló. Ahora no se puede mostrar la información." << endl;
        }
    }
};
#endif