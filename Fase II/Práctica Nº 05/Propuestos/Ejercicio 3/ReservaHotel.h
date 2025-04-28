#ifndef RESERVAHOTEL_H
#define RESERVAHOTEL_H

#include <iostream>
using namespace std;

#include "Habitacion.h"

class ReservaHotel{
private:
    int cantNoches;
    float precioTotal;
    string codigo;
    Habitacion* habitacionesReservadas;

public:
    ReservaHotel(int cantidad, string _codigo) {
        cantNoches = cantidad;
        codigo = _codigo;
        precioTotal = 0.0;
        habitacionesReservadas = new Habitacion[cantNoches];
    }

    void IngresarHabitaciones(){
        // Ingresar las habitaciones
        for (int i = 0; i < cantNoches; i++) {
            int numero;
            string tipo;
            float precioPorNoche;
            cout << "Ingrese el numero de la habitacion " << i + 1 << ": ";
            cin >> numero;
            cout << "Ingrese el tipo de habitacion " << i + 1 << ": ";
            cin >> tipo;
            cout << "Ingrese el precio x noche de la habitacion " << i + 1 << ": ";
            cin >> precioPorNoche;
            habitacionesReservadas[i] = Habitacion(numero, tipo, precioPorNoche); // Inicialización del objeto
        }

        // Mostrar información de las habitaciones
        cout << "\nLista de habitaciones reservadas:\n";
        for (int i = 0; i < cantNoches; i++) {
            cout<<"Habitación Nº "<<i+1<<": "<<endl;
            habitacionesReservadas[i].mostrarHabitacion();
        }
    }

    void calcularTotal(){
        for (int i=0; i<cantNoches; i++){
            precioTotal = precioTotal + habitacionesReservadas[i].getPrecioXNoche();
        }
        precioTotal=precioTotal*cantNoches;
        cout<<"El precio total por "<<cantNoches<<" noches es: "<<precioTotal<<endl;
    }
    ~ReservaHotel(){
        delete[] habitacionesReservadas;
    }
};
#endif
