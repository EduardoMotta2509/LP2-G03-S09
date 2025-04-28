#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
using namespace std;

#include "Asignatura.h"

class Profesor{
private:
    string nombre;
    string direccion;
    string nroTelefono;
    vector<Asignatura> asignaturasImpartidas;
public:
    Profesor(string _nombre, string _direccion, string _nroTelefono, vector<Asignatura> _asignaturasImpartidas) : nombre(_nombre), direccion(_direccion), nroTelefono(_nroTelefono), asignaturasImpartidas(_asignaturasImpartidas) {}

    void asignarNuevoCurso(Asignatura nuevoCurso){
        asignaturasImpartidas.push_back(nuevoCurso);
    }

};
#endif