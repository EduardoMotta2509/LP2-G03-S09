#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
using namespace std;
#include "Asignatura.h"

class Estudiante{
private:
    string nombre;
    string direccion;
    string nroMatricula;
    vector<Asignatura> asignaturas;
public:
    Estudiante(string _nombre, string _direccion, string _nroMatricula, vector<Asignatura> _asignaturas) : nombre(), direccion(), nroMatricula(), asignaturas() {}
};
#endif
