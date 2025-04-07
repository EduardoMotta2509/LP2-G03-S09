#include <iostream>
#include <string>

using namespace std;

// Clase Universidad
class Universidad {
private:
    string nombre;
public:
    Universidad(string nombre) : nombre(nombre) {}
    
    string getNombre() const {
        return nombre;
    }
};

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    Universidad* universidad;  // Asociación Unidireccional: Un estudiante conoce su universidad.
public:
    Estudiante(string nombre, Universidad* uni) : nombre(nombre), universidad(uni) {}

    void mostrarInformacion() {
        cout << "Nombre del Estudiante: " << nombre << endl;
        cout << "Universidad: " << universidad->getNombre() << endl;
    }
};

int main() {
    // Creando una universidad
    Universidad uni("Universidad Nacional");

    // Creando un estudiante asociado a la universidad
    Estudiante estudiante1("Carlos Pérez", &uni);
    
    // Mostrando información
    estudiante1.mostrarInformacion();

    return 0;
}
