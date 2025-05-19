#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H

#include "Vehiculo.h"

class Motocicleta : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando la motocicleta" << endl;
    }
};

#endif
