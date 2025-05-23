#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
#include <vector>
#include <set>

class Reserva {
private:
    int codigo;
    Usuario* usuario;
    Habitacion* habitacion;
    string fechaInicio;
    string fechaFin;
public:
    Reserva(int _codigo, Usuario* _usuario, Habitacion* _habitacion, string _fechaInicio, string _fechaFin) : codigo(_codigo), usuario(_usuario), habitacion(_habitacion), fechaInicio(_fechaInicio), fechaFin(_fechaFin) {}
    int getCodigo() const {
        cout << "Reserva: getCodigo" << endl;
        return codigo;
    }
    Usuario* getUsuario() const {
        cout << "Reserva: getUsuario" << endl;
        return usuario;
    }
    Habitacion* getHabitacion() const {
        cout << "Reserva: getHabitacion" << endl;
        return habitacion;
    }
    string getFechaInicio() const {
        cout << "Reserva: getFechaInicio" << endl;
        return fechaInicio;
    }
    string getFechaFin() const {
        cout << "Reserva: getFechaFin" << endl;
        return fechaFin;
    }
    void mostrarDetalles() const {
        cout << "Reserva::mostrarDetalles" << endl;
        cout << "Codigo Reserva: " << codigo << ", Fecha Inicio: " << fechaInicio << ", Fecha Fin: " << fechaFin << endl;
        cout << "Datos del Usuario: " << endl;
        cout << "Datos de la Habitacion" << endl;
    }
};
#endif