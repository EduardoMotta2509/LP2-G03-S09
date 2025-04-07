#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Declaración adelantada para evitar dependencias circulares
class Estudiante;

class Universidad {
private:
    string nombre;
    vector<Estudiante*> estudiantes;  // Lista de estudiantes asociados
public:
    Universidad(string nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }

    void agregarEstudiante(Estudiante* estudiante) {
        estudiantes.push_back(estudiante);
    }

    void mostrarEstudiantes() {
        cout << "Estudiantes en la " << nombre << ":" << endl;
        for (Estudiante* e : estudiantes) {
            cout << "- " << e->getNombre() << endl;
        }
    }
};

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    Universidad* universidad;  // Asociación con Universidad
public:
    Estudiante(string nombre, Universidad* uni) : nombre(nombre), universidad(uni) {
        universidad->agregarEstudiante(this);  // Asociamos el estudiante a la universidad
    }

    string getNombre() const {
        return nombre;
    }

    Universidad* getUniversidad() const {
        return universidad;
    }
};

int main() {
    // Crear una universidad
    Universidad uni("Universidad Nacional");

    // Crear estudiantes asociados a la universidad
    Estudiante est1("Carlos Pérez", &uni);
    Estudiante est2("María López", &uni);

    // Mostrar información de la universidad y sus estudiantes
    uni.mostrarEstudiantes();

    return 0;
}
