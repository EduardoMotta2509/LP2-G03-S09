#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"
#include "HabitacionSimple.h"
#include "HabitacionDoble.h"
#include "Suite.h"

class Hotel; // Agregación

class Administrador : public Usuario {
private:
    Hotel* hotel;
public:
    Administrador(string n, string d, string nac, string c, string p, Hotel* h)
        : Usuario(n, d, nac, c, p), hotel(h) {}

    void agregarHabitacion(string tipo, string codigo, double precio) {
        if (tipo == "Simple") hotel->agregarHabitacion(new HabitacionSimple(codigo, precio));
        else if (tipo == "Doble") hotel->agregarHabitacion(new HabitacionDoble(codigo, precio));
        else if (tipo == "Suite") hotel->agregarHabitacion(new Suite(codigo, precio));
    }

    void gestionarDisponibilidad(string codigo, bool estado) {
        if (estado) hotel->desbloquearHabitacion(codigo);
        else hotel->bloquearHabitacion(codigo);
    }

    void verReportesOcupacion() const { hotel->verOcupacion(); }
    void verReportesIngresos() const { hotel->verIngresos(); }
};

#endif
