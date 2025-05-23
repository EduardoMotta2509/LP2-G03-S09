// Suite.h
#ifndef SUITE_H
#define SUITE_H
#include "Habitacion.h"

class Suite : public Habitacion {
public:
    Suite(string c, double p) : Habitacion(c, "Suite", p) {}
    double calcularTarifa(int dias) const override { return dias * precio + 100; }
};
#endif
