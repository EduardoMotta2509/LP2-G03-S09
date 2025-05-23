#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Reserva.h"
using namespace std;

class Hotel {
private:
    string nombre, direccion;
    vector<Habitacion*> habitaciones;
    vector<Reserva*> reservas;
public:
    void agregarHabitacion(Habitacion* h) { habitaciones.push_back(h); }
    void eliminarHabitacion(string codigo){
    habitaciones.erase(remove_if(habitaciones.begin(), habitaciones.end(),
        [&](Habitacion* h) { return h->getCodigo() == codigo; }), habitaciones.end());
    }
    Habitacion* buscarHabitacion(string codigo){
        for (auto h : habitaciones)
            if (h->getCodigo() == codigo) return h;
        return nullptr;
    }

    vector<Habitacion*> buscarDisponibles(string tipo, double maxPrecio) {
        vector<Habitacion*> disponibles;
        for (auto h : habitaciones)
            if (h->estaDisponible() && (tipo == "" || h->getTipo() == tipo) && h->getPrecio() <= maxPrecio)
                disponibles.push_back(h);
        return disponibles;
    }

    void registrarReserva(Reserva* r) { reservas.push_back(r); }
    void cancelarReserva(string codigo){
        Reserva* r = buscarReserva(codigo);
        if (r && r->estaActiva()) r->cancelar();
    }
    
    Reserva* buscarReserva(string codigo){
        for (auto r : reservas)
            if (r->getCodigo() == codigo) return r;
        return nullptr;
    }

    void bloquearHabitacion(string codigo){
        Habitacion* h = buscarHabitacion(codigo);
        if (h) h->bloquear();
    }
    void desbloquearHabitacion(string codigo){
        Habitacion* h = buscarHabitacion(codigo);
        if (h) h->desbloquear();
    }

    void generarReportes() const{
        verOcupacion();
        verIngresos();
    }
    void verOcupacion() const{
        for (auto h : habitaciones)
            cout << h->getCodigo() << " - " << (h->estaDisponible() ? "Disponible" : "No disponible") << endl;
    }
    void verIngresos() const{
        double total = 0;
        for (auto r : reservas)
            if (r->estaActiva()) total += r->obtenerCosto();
        cout << "Ingresos totales: S/. " << total << endl;
    }
};

#endif
