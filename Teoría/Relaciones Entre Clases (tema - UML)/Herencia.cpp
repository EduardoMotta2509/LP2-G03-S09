#include <iostream>
#include <string>

using namespace std;

// Clase base
class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad) : nombre(nombre), edad(edad) {}

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

// Clase derivada
class Estudiante : public Persona {
private:
    string carrera;

public:
    Estudiante(string nombre, int edad, string carrera)
        : Persona(nombre, edad), carrera(carrera) {}

    void mostrarDatosCompletos() const {
        mostrarDatos(); // método heredado
        cout << "Carrera: " << carrera << endl;
    }
};

int main() {
    Estudiante estudiante1("Laura", 21, "Ingeniería de Sistemas");

    estudiante1.mostrarDatosCompletos();

    return 0;
}
