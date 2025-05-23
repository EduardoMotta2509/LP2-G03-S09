#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// Clase base para Habitación
class Habitacion {
protected:
    int codigo;
    string tipo;
    bool disponible;
    double precio;
public:
    Habitacion(int _codigo, string _tipo, double _precio) : codigo(_codigo), tipo(_tipo), disponible(true), precio(_precio) {}
    int getCodigo() const {
        cout << "Habitacion::getCodigo" << endl;
        return codigo;
    }
    string getTipo() const {
        cout << "Habitacion: getTipo" << endl;
        return tipo;
    }
    bool estaDisponible() const {
        cout << "Habitacion: estaDisponible" << endl;
        return disponible;
    }
    double getPrecio() const {
        cout << "Habitacion: getPrecio" << endl;
        return precio;
    }
    void setDisponible(bool disponible) {
        cout << "Habitacion: setDisponible" << endl;
    }
    virtual double calcularTarifa() {
        cout << "Habitacion: calcularTarifa" << endl;
        return precio;
    }
};
#endif