#ifndef RESERVA_H
#define RESERVA_H

#include "Usuario.h"
#include "Habitacion.h"
#include "ValidarFechaExcepcion.h"
#include <string>
using namespace std;

class Usuario; // Forward declaration
class Reserva {
private:
    string codigoReserva;
    string fechaInicio, fechaFin;
    Usuario* usuario;
    Habitacion* habitacion;
    bool activa;
public:
    Reserva(string cod, string ini, string fin, Usuario* u, Habitacion* h)
        : codigoReserva(cod), fechaInicio(ini), fechaFin(fin), usuario(u), habitacion(h), activa(true) {
        if (ini >= fin) throw ValidarFechaExcepcion("La fecha de inicio debe ser menor que la de fin");
        habitacion->setDisponible(false);
    }
    bool operator==(const Reserva& r) const { return codigoReserva == r.codigoReserva; }
    bool estaActiva() const { return activa; }
    double obtenerCosto() const { return habitacion->calcularTarifa(2); }
    void cancelar() { activa = false; habitacion->setDisponible(true); }
    Habitacion* getHabitacion() const { return habitacion; }
    Usuario* getUsuario() const { return usuario; }
    string getCodigo() const { return codigoReserva; }
};

#endif
