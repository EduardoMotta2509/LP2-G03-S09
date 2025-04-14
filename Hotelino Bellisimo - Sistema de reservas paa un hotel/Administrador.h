#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Usuario.h"
using namespace std;
class Hotel;


class Administrador : public Usuario {
public:
    Administrador(string _nombre, string _dni, string _nacionalidad) : Usuario(_nombre, _dni, _nacionalidad) {}
    void agregarHabitacion(Hotel& hotel, int codigo, string tipo, double precio) {
        cout << "Administrador: agregarHabitacion" << endl;
    }
    void gestionarDisponibilidad(Hotel& hotel, int codigo, bool disponible) {
        cout << "Administrador: gestionarDisponibilidad" << endl;
    }
    void verReportesOcupacion(const Hotel& hotel) {
        cout << "Administrador: verReportesOcupacion" << endl;
        cout << "Total de habitaciones: " << endl;
        cout << "Habitaciones ocupadas: " << endl;
        cout << "Habitaciones disponibles: " << endl;
    }
    void verReporteIngresos(const Hotel& hotel) {
        cout << "Administrador::verReporteIngresos" << endl;
         cout << "--- Reporte de Ingresos ---" << endl;
        cout << "Ingresos totales: " << endl;
    }
};
#endif
    