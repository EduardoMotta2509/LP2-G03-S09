#ifndef MOVIL_H
#define MOVIL_H

#include <iostream>
#include <string>
using namespace std;

class Movil {
protected:
    string marca;
    string modelo;
    string sistemaOperativo;

public:
    Movil(string m, string mod, string so) {
        marca = m;
        modelo = mod;
        sistemaOperativo = so;
        cout << "Constructor de Movil: " << marca << " - " << modelo << " - " << sistemaOperativo << endl;
    }

    ~Movil() {
        cout << "Destructor de Movil: " << marca << " - " << modelo << endl;
    }
};

#endif
