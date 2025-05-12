#ifndef CLIENTESEGURO_H
#define CLIENTESEGURO_H

#include "Cliente.h"

class ClienteSeguroPublico : public Cliente {
private:
    string clave;

public:
    ClienteSeguroPublico(string nom, string dir, string tel, double sal, string cla) 
        : Cliente(nom, dir, tel, sal) {
        clave = cla;
    }

    bool verificarAutenticidad(string claveIngresada) {
        return claveIngresada == clave;
    }

    void mostrarInfoSeguro(string claveIngresada) {
        if (verificarAutenticidad(claveIngresada)) {
            cout << "Herencia pública: Información Autenticada:" << endl;
            mostrarInfo();
        } else {
            cout << "Autenticación fallida (pública)." << endl;
        }
    }

    ~ClienteSeguroPublico() {
        cout << "Destructor ClienteSeguroPublico ejecutado" << endl;
    }
};

class ClienteSeguroProtegido : protected Cliente {
private:
    string clave;

public:
    ClienteSeguroProtegido(string nom, string dir, string tel, double sal, string cla) 
        : Cliente(nom, dir, tel, sal) {
        clave = cla;
    }

    bool verificarAutenticidad(string claveIngresada) {
        return claveIngresada == clave;
    }

    void mostrarInfoSeguro(string claveIngresada) {
        if (verificarAutenticidad(claveIngresada)) {
            cout << "Herencia protegida: Información Autenticada:" << endl;
            mostrarInfo();
        } else {
            cout << "Autenticación fallida (protegida)." << endl;
        }
    }

    ~ClienteSeguroProtegido() {
        cout << "Destructor ClienteSeguroProtegido ejecutado" << endl;
    }
};

class ClienteSeguroPrivado : private Cliente {
private:
    string clave;

public:
    ClienteSeguroPrivado(string nom, string dir, string tel, double sal, string cla) 
        : Cliente(nom, dir, tel, sal) {
        clave = cla;
    }

    bool verificarAutenticidad(string claveIngresada) {
        return claveIngresada == clave;
    }

    void mostrarInfoSeguro(string claveIngresada) {
        if (verificarAutenticidad(claveIngresada)) {
            cout << "Herencia privada: Información Autenticada:" << endl;
            mostrarInfo();
        } else {
            cout << "Autenticación fallida (privada)." << endl;
        }
    }

    ~ClienteSeguroPrivado() {
        cout << "Destructor ClienteSeguroPrivado ejecutado" << endl;
    }
};

#endif
