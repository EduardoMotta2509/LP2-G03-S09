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

    bool verificarAutenticidad(string claveIngresada) {
        return claveIngresada == clave;
    }

    void mostrarInfoSeguro(string claveIngresada) {
        if (verificarAutenticidad(claveIngresada)) {
            cout << "Información ya autenticada:" << endl;
            mostrarInfo();
        } else {
            cout << "La autenticación falló. Ahora no se puede mostrar la información." << endl;
        }
    }
};
#endif
