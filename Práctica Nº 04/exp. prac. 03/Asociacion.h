#ifndef ASOCIACION_H
#define ASOCIACION_H

#include "Estudiante.h"
#include "Docente.h"
#include "Curso.h"

class Asociacion {
private:
    Estudiante* estudiante;
    Docente* docente;
    Curso* curso;
public:
    Asociacion(Estudiante* e, Docente* d, Curso* c)
        : estudiante(e), docente(d), curso(c) {}

    void mostrarRelacion() {
        cout << "La relación es: " << endl;
        estudiante->mostrarInfo();
        docente->mostrarInfo();
        curso->mostrarInfo();
        cout << endl;
    }
};

#endif