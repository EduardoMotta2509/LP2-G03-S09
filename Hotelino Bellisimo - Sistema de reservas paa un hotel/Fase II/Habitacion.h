#ifndef HABITACION_H
#define HABITACION_H

#include <string>
using namespace std;

class Habitacion {
protected:
    string codigo;
    string tipo;
    bool disponible;
    bool bloqueada;
    double precio;
public:
    Habitacion(string c, string t, double p)
        : codigo(c), tipo(t), precio(p), disponible(true), bloqueada(false) {}
    virtual ~Habitacion() {}

    virtual double calcularTarifa(int dias) const = 0;

    string getCodigo() const { return codigo; }
    string getTipo() const { return tipo; }
    double getPrecio() const { return precio; }
    void setPrecio(double p) { precio = p; }

    bool estaDisponible() const { return disponible && !bloqueada; }
    void setDisponible(bool d) { disponible = d; }
    void bloquear() { bloqueada = true; }
    void desbloquear() { bloqueada = false; }

    bool operator==(const Habitacion& h) const {
        return codigo == h.codigo;
    }
};

#endif
