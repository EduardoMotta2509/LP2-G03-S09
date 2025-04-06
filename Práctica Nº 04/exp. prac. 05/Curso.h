#ifndef CURSO_H
#define CURSO_H

#include "Estudiante.h"
#include <vector>
using namespace std;

class Curso {
private:
    string nombreCurso;
    vector<Estudiante> estudiantes;

public:
    Curso(string nombre) : nombreCurso(nombre) {}

    void agregarEstudiante(const Estudiante& est) {
        estudiantes.push_back(est);
    }

    bool eliminarEstudiantePorID(int id) {
        for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
            if (it->getId() == id) {
                estudiantes.erase(it);
                return true;
            }
        }
        return false;
    }

    bool mostrarEstudiantePorID(int id) const {
        for (const auto& est : estudiantes) {
            if (est.getId() == id) {
                est.mostrarInfo();
                return true;
            }
        }
        cout << "Estudiante con ID " << id << " no encontrado.\n";
        return false;
    }

    bool modificarNombreEstudiantePorID(int id, string nuevoNombre) {
        for (auto& est : estudiantes) {
            if (est.getId() == id) {
                est.setNombre(nuevoNombre);
                return true;
            }
        }
        return false;
    }

    void mostrarEstudiantes() const {
        cout << "Estudiantes del curso de " << nombreCurso << ":" << endl;
        for (const auto& est : estudiantes) {
            est.mostrarInfo();
        }
        cout << endl;
    }
};

#endif

