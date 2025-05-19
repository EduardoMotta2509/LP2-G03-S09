#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
using namespace std;

class Vehiculo {
public:
    virtual void acelerar() {
        cout << "Acelerando el vehiculo" << endl;
    }
};

#endif
