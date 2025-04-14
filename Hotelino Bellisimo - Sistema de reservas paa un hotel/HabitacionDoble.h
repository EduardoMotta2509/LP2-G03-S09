#ifndef HABITACIONDOBLE_H
#define HABITACIONDOBLE_H

#include <iostream>
#include <string>
#include <vector>
#include <set>

class HabitacionDoble : public Habitacion {
public:
    HabitacionDoble(int _codigo, double _precio) : Habitacion(_codigo, "Doble", _precio) {}
    double calcularTarifa() override {
        cout << "HabitacionDoble::calcularTarifa" << endl;
        return precio * 1.15;
    }
};
#endif