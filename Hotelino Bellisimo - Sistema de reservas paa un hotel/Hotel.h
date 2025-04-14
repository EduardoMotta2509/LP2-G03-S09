#ifndef HOTEL_H
#define HOTEL_H

class Hotel {
private:
    set<Habitacion*> habitaciones;
    vector<Reserva> reservas;
public:
    Hotel();
    void agregarHabitacion(Habitacion* habitacion) {
        cout << "Hotel: agregarHabitacion" << endl;
    }
    void eliminarHabitacion(int codigo) {
        cout << "Hotel: eliminarHabitacion" << endl;
    }
    Habitacion* buscarHabitacion(int codigo) {
        cout << "Hotel: buscarHabitacion" << endl;
        return nullptr;
    }
    set<Habitacion*> getHabitaciones() {
        cout << "Hotel::getHabitaciones" << endl;
        return habitaciones;
    }
    void agregarReserva(const Reserva& reserva) {
        cout << "Hotel: agregarReserva" << endl;
    }
    void cancelarReserva(int codigo) {
        cout << "Hotel: cancelarReserva" << endl;
    }
    Reserva* buscarReserva(int codigo) {
        cout << "Hotel: buscarReserva" << endl;
        return nullptr;
    }
    vector<Reserva> getReservas() {
        cout << "Hotel: getReservas" << endl;
        return reservas;
    }
    void verReportesOcupacion() const {
        cout << "Hotel::verReportesOcupacion" << endl;
        cout << "--- Reporte de Ocupación ---" << endl;
        cout << "Total de habitaciones: " << endl;
        cout << "Habitaciones ocupadas: " << endl;
        cout << "Habitaciones disponibles: " << endl;
    }
    void verReporteIngresos() const {
        cout << "Hotel::verReporteIngresos" << endl;
        cout << "--- Reporte de Ingresos ---" << endl;
        cout << "Ingresos totales: " << endl;
    }
};
#endif