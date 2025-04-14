#ifndef SUITE_H
#define SUITE_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Suite : public Habitacion {
public:
    Suite(int _codigo, double _precio) : Habitacion(_codigo, "Suite", _precio) {}
    double calcularTarifa() override {
        cout << "Suite: calcularTarifa" << endl;
        return precio * 1.30;
    }
};
#endif