#ifndef TELEFONOYTABLET_H
#define TELEFONOYTABLET_H

#include "Movil.h"

class Telefono : public Movil {
public:
    Telefono(string m, string mod, string so) : Movil(m, mod, so) {
        cout << "Constructor de Telefono" << endl;
    }

    ~Telefono() {
        cout << "Destructor de Telefono" << endl;
    }
};

class Tablet : public Movil {
public:
    Tablet(string m, string mod, string so) : Movil(m, mod, so) {
        cout << "Constructor de Tablet" << endl;
    }

    ~Tablet() {
        cout << "Destructor de Tablet" << endl;
    }
};

#endif
