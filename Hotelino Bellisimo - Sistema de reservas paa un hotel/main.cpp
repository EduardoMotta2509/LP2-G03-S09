#include "Administrador.h"
#include "HabitacionSimple.h"
#include "HabitacionDoble.h"
#include "Suite.h"
#include "Hotel.h"
#include "Reserva.h"
#include "Usuario.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Crear instancias de Usuario y Administrador
    Usuario* usuario1 = new Usuario("Juan Perez", "12345678A", "Española");
    Administrador* admin1 = new Administrador("Ana López", "98765432B", "Mexicana");

    // Crear instancia de Hotel
    Hotel* hotelPrincipal = new Hotel();

    // Crear instancias de Habitacion
    Habitacion* simple1 = new HabitacionSimple(101, 50.0);
    Habitacion* doble1 = new HabitacionDoble(201, 80.0);
    Habitacion* suite1 = new Suite(301, 120.0);

    // Agregar habitaciones al hotel
    hotelPrincipal->agregarHabitacion(simple1);
    hotelPrincipal->agregarHabitacion(doble1);
    hotelPrincipal->agregarHabitacion(suite1);

    // Mostrar las habitaciones del hotel
    cout << "Habitaciones en el hotel:" << endl;
    for (Habitacion* habitacion : hotelPrincipal->getHabitaciones()) {
        cout << "Código: " << habitacion->getCodigo();
        cout << ", Tipo: " << habitacion->getTipo();
        cout << ", Precio: " << habitacion->getPrecio() << endl;
    }

    // Crear una reserva
    Reserva reserva1(1, usuario1, simple1, "2025-04-20", "2025-04-25");

    // Agregar la reserva al hotel
    hotelPrincipal->agregarReserva(reserva1);

    // Mostrar las reservas del hotel
    cout << "\nReservas en el hotel:" << endl;
    for (const auto& reserva : hotelPrincipal->getReservas()) {
        reserva.mostrarDetalles();
    }

    // Simular acciones del administrador
    cout << "\nAcciones del Administrador:" << endl;
    admin1->agregarHabitacion(*hotelPrincipal, 102, "Simple", 55.0);
    admin1->gestionarDisponibilidad(*hotelPrincipal, 101, false); // Marcar la habitación simple1 como no disponible
    admin1->verReportesOcupacion(*hotelPrincipal);
    admin1->verReporteIngresos(*hotelPrincipal);

    // Mostrar las habitaciones actualizadas del hotel
    cout << "\nHabitaciones en el hotel después de las acciones del administrador:" << endl;
    for (Habitacion* habitacion : hotelPrincipal->getHabitaciones()) {
        cout << "Código: " << habitacion->getCodigo();
        cout << ", Tipo: " << habitacion->getTipo();
        cout << ", Precio: " << habitacion->getPrecio();
        cout << ", Disponible: " << (habitacion->estaDisponible() ? "Sí" : "No") << endl;
    }

    // Liberar la memoria (importante para evitar fugas de memoria)
    delete usuario1;
    delete admin1;
    delete hotelPrincipal;
    delete simple1;
    delete doble1;
    delete suite1;

    return 0;
}