#include "Curso.h"
#include "Estudiante.h"

int main() {
    Curso curso("Programación II");

    Estudiante est1("Eduardo", 2024551335);
    Estudiante est2("Jose", 2024001337);
    Estudiante est3("Paul", 2024009876);

    curso.agregarEstudiante(est1);
    curso.agregarEstudiante(est2);
    curso.agregarEstudiante(est3);

    curso.mostrarEstudiantes();

    cout << "Buscando estudiante con ID 2024001337:\n";
    curso.mostrarEstudiantePorID(2024001337);

    cout << "Modificando nombre del estudiante con ID 2024001337:\n";
    if (curso.modificarNombreEstudiantePorID(2024001337, "Gilberto")) {
        curso.mostrarEstudiantePorID(2024001337);
    } else {
        cout << "Estudiante no encontrado.\n";
    }

    cout << "Eliminando estudiante con ID 2024009876:\n";
    if (curso.eliminarEstudiantePorID(2024009876)) {
        cout << "Estudiante eliminado correctamente.\n";
    } else {
        cout << "Estudiante no encontrado.\n";
    }

    curso.mostrarEstudiantes();

    return 0;
}

