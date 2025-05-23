// HabitacionDoble.h
#ifndef HABITACION_DOBLE_H
#define HABITACION_DOBLE_H
#include "Habitacion.h"

class HabitacionDoble : public Habitacion {
public:
    HabitacionDoble(string c, double p) : Habitacion(c, "Doble", p) {}
    double calcularTarifa(int dias) const override { return dias * precio; }
};
#endif
