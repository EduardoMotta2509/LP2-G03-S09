#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Profesor {
public:
    string nombre;
    Profesor(string nombre) : nombre(nombre) {}
};

class Estudiante {
public:
    string nombre;
    Estudiante(string nombre) : nombre(nombre) {}
};

class Curso {
public:
    string nombre;
    Curso(string nombre) : nombre(nombre) {}
};

// Clase intermedia para modelar la asociación ternaria
class Inscripcion {
public:
    Estudiante* estudiante;
    Curso* curso;
    Profesor* profesor;

    Inscripcion(Estudiante* est, Curso* cur, Profesor* prof)
        : estudiante(est), curso(cur), profesor(prof) {}

    void mostrarInformacion() {
        cout << estudiante->nombre << " está inscrito en " << curso->nombre
             << " con el profesor " << profesor->nombre << "." << endl;
    }
};

int main() {
    Profesor prof("Dr. López");
    Estudiante est("Juan Pérez");
    Curso curso("Programación Avanzada");

    Inscripcion inscripcion(&est, &curso, &prof);
    inscripcion.mostrarInformacion();

    return 0;
}
