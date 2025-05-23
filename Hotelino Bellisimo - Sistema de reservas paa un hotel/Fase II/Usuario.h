#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;
#include <vector>
#include "Reserva.h"
#include "Hotel.h"

class Usuario {
protected:
    string nombre, dni, nacionalidad, correo, contrasena;
    vector<Reserva*> historial;
public:
    Usuario(string n, string d, string nac, string c, string p)
        : nombre(n), dni(d), nacionalidad(nac), correo(c), contrasena(p) {}
    virtual ~Usuario() {}

    bool autenticar(const string& c, const string& p) const {
        return correo == c && contrasena == p;
    }

    string getDni() const { return dni; }

    void actualizarDatos(string nuevoNombre, string nuevoDni, string nuevaNacionalidad) {
        nombre = nuevoNombre;
        dni = nuevoDni;
        nacionalidad = nuevaNacionalidad;
    }

    Habitacion* buscarHabitacion(Hotel& hotel, string codigo) {
        return hotel.buscarHabitacion(codigo);
    }

    Reserva* reservar(Hotel& hotel, string codigo, string tipo, string ini, string fin) {
        Habitacion* h = hotel.buscarHabitacion(codigo);
        if (h && h->getTipo() == tipo && h->estaDisponible()) {
            Reserva* r = new Reserva("RES" + codigo, ini, fin, this, h);
            hotel.registrarReserva(r);
            historial.push_back(r);
            return r;
        }
        return nullptr;
    }

    bool cancelarReserva(Hotel& hotel, string codigoReserva) {
        Reserva* r = hotel.buscarReserva(codigoReserva);
        if (r && r->getUsuario() == this) {
            r->cancelar();
            return true;
        }
        return false;
    }

    void verHistorial() const {
        for (auto r : historial)
            cout << r->getCodigo() << " - " << r->getHabitacion()->getCodigo() << " - " << (r->estaActiva() ? "Activa" : "Cancelada") << endl;
    }
};

#endif
