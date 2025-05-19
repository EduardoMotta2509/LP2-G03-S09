#ifndef COCHE_H
#define COCHE_H

#include "Vehiculo.h"

class Coche : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando el coche" << endl;
    }

    void encenderLuces() {
        cout << "Luces del coche encendidas" << endl;
    }
};

#endif
