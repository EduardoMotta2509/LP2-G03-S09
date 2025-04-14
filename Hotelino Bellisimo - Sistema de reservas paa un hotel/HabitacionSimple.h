#ifndef HABITACIONSIMPLE_H
#define HABITACIONSIMPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Habitacion.h"
using namespace std;

class HabitacionSimple : public Habitacion {
public:
    HabitacionSimple(int _codigo, double _precio): Habitacion(_codigo, "Simple", _precio) {}
    double calcularTarifa() override {
        cout << "HabitacionSimple::calcularTarifa" << endl;
        return precio;
    }
};
#endif