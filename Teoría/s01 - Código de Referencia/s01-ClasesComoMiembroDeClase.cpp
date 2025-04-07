#include <iostream>
using namespace std;

// Definición de la clase Direccion
class Direccion {
private:
    string ciudad;
    string calle;

public:
    // Constructor de Direccion
    Direccion(string _ciudad, string _calle) {
        ciudad = _ciudad;
        calle = _calle;
    }

    // Métodos de acceso
    string getCiudad() { return ciudad; }
    string getCalle() { return calle; }

    // Método para mostrar información de la dirección
    void mostrarDireccion() {
        cout << "Ciudad: " << ciudad << ", Calle: " << calle << endl;
    }
};

// Definición de la clase Persona que tiene una Direccion como atributo
class Persona {
private:
    string nombre;
    int edad;
    Direccion direccion; // Atributo de tipo Direccion

public:
    // Constructor de Persona (usa inicialización de lista para Direccion)
    Persona(string _nombre, int _edad, string _ciudad, string _calle) 
        : direccion(_ciudad, _calle) { // Inicializa el objeto direccion
        nombre = _nombre;
        edad = _edad;
    }

    // Método para mostrar la información de la persona
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        cout << "Dirección: ";
        direccion.mostrarDireccion(); // Llamar método de la clase Direccion
    }
};

int main() {
    // Crear un objeto de la clase Persona
    Persona p1("Adriana", 30, "Bogotá", "Calle 45 #10-20");

    // Mostrar información de la persona y su dirección
    p1.mostrarInformacion();

    return 0;
}
