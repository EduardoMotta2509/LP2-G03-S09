#ifndef EMPLEADOTIEMPOCOMPLETO_H
#define EMPLEADOTIEMPOCOMPLETO_H

#include "Empleado.h"

class EmpleadoTiempoCompleto : public Empleado {
private:
    double salarioMensual;
public:
    EmpleadoTiempoCompleto(double salario) : salarioMensual(salario) {}

    double calcularSalario() const override {
        return salarioMensual;
    }
};

#endif
