// HabitacionSimple.h
#ifndef HABITACION_SIMPLE_H
#define HABITACION_SIMPLE_H
#include "Habitacion.h"

class HabitacionSimple : public Habitacion {
public:
    HabitacionSimple(string c, double p) : Habitacion(c, "Simple", p) {}
    double calcularTarifa(int dias) const override { return dias * precio; }
};
#endif
