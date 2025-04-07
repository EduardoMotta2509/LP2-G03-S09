#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Habitacion {
private:
    string nombre;
public:
    Habitacion(string nombre) : nombre(nombre) {}

    void mostrar() const {
        cout << "Habitación: " << nombre << endl;
    }
};

class Casa {
private:
    string direccion;
    vector<Habitacion> habitaciones;  // Composición: las habitaciones son parte de la casa
public:
    Casa(string direccion) : direccion(direccion) {}

    void agregarHabitacion(const string& nombreHabitacion) {
        habitaciones.emplace_back(nombreHabitacion);  // Se crean dentro de la casa
    }

    void mostrarHabitaciones() const {
        cout << "Casa en: " << direccion << endl;
        for (const Habitacion& h : habitaciones) {
            h.mostrar();
        }
    }
};

int main() {
    Casa miCasa("Calle Primavera 123");

    // Las habitaciones solo existen dentro de la casa
    miCasa.agregarHabitacion("Sala");
    miCasa.agregarHabitacion("Cocina");
    miCasa.agregarHabitacion("Dormitorio principal");

    miCasa.mostrarHabitaciones();

    return 0;
}
