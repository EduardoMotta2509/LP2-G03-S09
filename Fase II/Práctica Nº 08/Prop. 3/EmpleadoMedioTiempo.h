#ifndef EMPLEADOMEDIOTIEMPO_H
#define EMPLEADOMEDIOTIEMPO_H

#include "Empleado.h"

class EmpleadoMedioTiempo : public Empleado {
private:
    double pagoPorHora;
    int horasTrabajadas;
public:
    EmpleadoMedioTiempo(double pagoHora, int horas) :
        pagoPorHora(pagoHora), horasTrabajadas(horas) {}

    double calcularSalario() const override {
        return pagoPorHora * horasTrabajadas;
    }
};

#endif
